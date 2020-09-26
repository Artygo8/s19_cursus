#!/usr/bin/env bash

# at first use on the 42user Xubuntu VM, run:
# sudo usermod -aG docker user42; newgrp docker

#                   _       _     _
#  __   ____ _ _ __(_) __ _| |__ | | ___  ___
#  \ \ / / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#   \ V / (_| | |  | | (_| | |_) | |  __/\__ \
#    \_/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/
#

containers=("nginx" "wordpress" "phpmyadmin" "ftps" "grafana" "mysql" "influxdb")
minikube_config="--cpus 2 --disk-size 10000 --addons dashboard --addons metallb"
binaries="binaries"

LOGS_UPDATES=10
LOGS_INTERVAL=5
VERBOSE=0
REMOVE_BINARIES=0

MYSQL_ROOT_PASSWORD="password"
SSH_USER="james"
SSH_PASSWORD="bond"
FTP_USER="john"
FTP_PASSWORD="rambo"
# for grafana, change in secrets.yaml

STARTTIME=$(date +%s)
MAINTAINER="agossuin"

if [[ `uname` == "Linux" ]]; then
    if [[ `uname -a | grep "VirtualBox"` ]]; then
        loadBalancerBaseIP=172.17.0.1
    else
        loadBalancerBaseIP=192.168.99.13
    fi
    SED_CMD="sed -i -e"
else
    loadBalancerBaseIP=192.168.64.1
    SED_CMD="sed -i '' -e"
fi

#  _           _        _ _
# (_)_ __  ___| |_ __ _| | |
# | | '_ \/ __| __/ _` | | |
# | | | | \__ \ || (_| | | |
# |_|_| |_|___/\__\__,_|_|_|
#

function _installScript {
    export PATH="$PWD/$binaries:$PATH"

    if ([ -z `which minikube` ] || [ -z `which docker` ] || [ -z `which kubectl` ]) && [ `uname` != "Linux" ]; then
        echo "please install minikube, docker and linux with brew"
    fi
    if [ `uname` != "Linux" ]; then
        return
    fi
    if [[ -z `which minikube` ]]; then
        mkdir -p ./$binaries
        curl -sLO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
        install minikube-linux-amd64 ./$binaries/minikube
        rm minikube-linux-amd64
    fi
    if [[ -z `which docker` ]]; then
        mkdir -p ./$binaries
        export DOCKER_HOST=unix:///run/user/1000/docker.sock
        curl -sLO https://download.docker.com/linux/static/stable/x86_64/docker-19.03.12.tgz
        curl -sLO https://download.docker.com/linux/static/stable/x86_64/docker-rootless-extras-19.03.12.tgz
        tar xzvf docker-19.03.12.tgz >/dev/null
        tar xzvf docker-rootless-extras-19.03.12.tgz >/dev/null
        mv docker/* $binaries/
        mv docker-rootless-extras/* $binaries/
        rm -rf docker*
        systemctl --user start docker
    fi
    if [[ -z `which kubectl` ]]; then
        curl -sLO "https://storage.googleapis.com/kubernetes-release/release/$(curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt)/bin/linux/amd64/kubectl"
        chmod +x ./kubectl
        mv ./kubectl $binaries/kubectl
    fi

    tput setaf 4
    echo Minikube - `which minikube`
    echo Docker - `which docker`
    echo Kubectl - `which kubectl`
    tput sgr0
}

#   __                  _   _
#  / _|_   _ _ __   ___| |_(_) ___  _ __  ___
# | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
# |  _| |_| | | | | (__| |_| | (_) | | | \__ \
# |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
#

function _SAFE {
    if [[ $VERBOSE -eq 0 ]]; then
        $@ > /dev/null || (echo "COMMAND FAILED:" $@ && exit 1)
    else
        $@ || (echo "COMMAND FAILED:" $@ && exit 1)
    fi
}

function _TIMESTAMP {
    tput setaf 3
    echo
    ENDTIME=$(date +%s)
    echo "[$(( (($ENDTIME - $STARTTIME)) / 60 ))m$(( (($ENDTIME - $STARTTIME)) %60 ))s] $@"
    tput sgr0
}

function _changeFilesIP {
    $SED_CMD "s/        -.*/        - ${loadBalancerBaseIP}0-${loadBalancerBaseIP}9/g" srcs/yaml/metallb-configmap.yaml
    rm -rf srcs/containers/nginx/srcs/localhost/index.html
    cp srcs/containers/nginx/srcs/localhost/index-template.html srcs/containers/nginx/srcs/localhost/index.html
    rm -rf srcs/containers/mysql/srcs/wordpress.sql
    cp srcs/containers/mysql/srcs/wordpress-template.sql srcs/containers/mysql/srcs/wordpress.sql
    rm -rf srcs/containers/ftps/Dockerfile
    cp srcs/containers/ftps/Dockerfile-template srcs/containers/ftps/Dockerfile
    for i in {0..4}; do
        $SED_CMD "s/  loadBalancerIP:.*/  loadBalancerIP: $loadBalancerBaseIP$i/g" srcs/yaml/${containers[$i]}-deployment.yaml
        $SED_CMD "s/\$${containers[$i]}/$loadBalancerBaseIP$i/g" srcs/containers/nginx/srcs/localhost/index.html
        $SED_CMD "s/\$${containers[$i]}/$loadBalancerBaseIP$i/g" srcs/containers/ftps/Dockerfile
        $SED_CMD "s/\$${containers[$i]}/$loadBalancerBaseIP$i/g" srcs/containers/mysql/srcs/wordpress.sql
    done
}

function _dockerBuildContainers {
    for container in "${containers[@]}"; do
        _TIMESTAMP Building $container:$MAINTAINER
        _SAFE docker build -t $container:$MAINTAINER ./srcs/containers/$container/ \
            --build-arg SSH_PASSWORD=$SSH_PASSWORD \
            --build-arg SSH_USER=$SSH_USER \
            --build-arg FTP_USER=$FTP_USER \
            --build-arg FTP_PASSWORD=$FTP_PASSWORD \
            --build-arg MYSQL_ROOT_PASSWORD=$MYSQL_ROOT_PASSWORD
    done
}

function _waitServicesReady {
        for container in "${containers[@]}"; do
        while true; do
            kubectl get pods | grep "$container.*1/1" > /dev/null && break
            sleep 1
        done
    done
    while true; do
        kubectl logs `kubectl get pods | grep -o "\S*mysql\S*"` | grep "3306" > /dev/null && break
        sleep 1
    done
}

function _getLogs {
    echo
    echo -n "updating $LOGS_UPDATES logs every ${LOGS_INTERVAL}s"
    for ((i = 0 ; i < $LOGS_UPDATES ; i++)); do
        echo -n "."
        mkdir -p ./logs
        for container in "${containers[@]}"; do
            kubectl logs `kubectl get pods | grep -o "\S*$container\S*"` > ./logs/$container.log
        done
        sleep $LOGS_INTERVAL;
    done
    echo
}

function _cleanUp {
    if [[ $REMOVE_BINARIES -eq 0 ]]; then
        _TIMESTAMP "no clean"
    else
        _TIMESTAMP "clean"
        rm -rf $binaries/
    fi
}

function _main {

    _TIMESTAMP "Preparing the .yaml files + index.html + wordpress.sql"
    _changeFilesIP

    _TIMESTAMP "install dependencies if necessary"
    _installScript

    _TIMESTAMP "Minikube restart"
    _SAFE minikube delete --all
    _SAFE minikube start $minikube_config

    _TIMESTAMP "Docker containers"
    eval $(minikube docker-env)
    _dockerBuildContainers

    _TIMESTAMP "Kubectl apply"
    _SAFE kubectl apply -k ./srcs/
    
    _TIMESTAMP "Waiting for the services to be ready..."
    _waitServicesReady
    kubectl get services

    _TIMESTAMP "Sending wordpress datas to mysql"
    _SAFE kubectl exec -i `kubectl get pods | grep -o "\S*mysql\S*"` -- mysql wordpress -u root < ./srcs/containers/mysql/srcs/wordpress.sql

    _SAFE minikube dashboard 2> /dev/null &
    _getLogs
    _cleanUp
}

#      _             _
#  ___| |_ __ _ _ __| |_
# / __| __/ _` | '__| __|
# \__ \ || (_| | |  | |_
# |___/\__\__,_|_|   \__|
#

_main
