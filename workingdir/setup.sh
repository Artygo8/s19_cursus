#!/usr/bin/env bash

#                   _       _     _
#  __   ____ _ _ __(_) __ _| |__ | | ___  ___
#  \ \ / / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#   \ V / (_| | |  | | (_| | |_) | |  __/\__ \
#    \_/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/
#

containers=("nginx" "wordpress" "phpmyadmin" "ftps" "grafana" "mysql" "influxdb")
# containers=("grafana" "influxdb")
minikube_config="--cpus=2 --disk-size 10000 --addons dashboard --addons metallb"
binaries="binaries"

VERBOSE=0

MYSQL_ROOT_PASSWORD="password"
WP_USER="john"
WP_PASSWORD="snow"
SSH_USER="james"
SSH_PASSWORD="bond"

STARTTIME=$(date +%s)
MAINTAINER="agossuin"

if [[ `uname` == "Linux" ]]; then
    loadBalancerBaseIP=192.168.99.13
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
    echo "[$(($ENDTIME - $STARTTIME))s] $@"
    tput sgr0
}

function _changeYamlHtmlIP {
    $SED_CMD "s/        -.*/        - ${loadBalancerBaseIP}0-${loadBalancerBaseIP}9/g" srcs/yaml/metallb-configmap.yaml
    rm -rf srcs/containers/nginx/srcs/localhost/index.html
    cp srcs/containers/nginx/srcs/localhost/index-template.html srcs/containers/nginx/srcs/localhost/index.html
    for i in {0..4}; do
        $SED_CMD "s/  loadBalancerIP:.*/  loadBalancerIP: $loadBalancerBaseIP$i/g" srcs/yaml/${containers[$i]}-deployment.yaml
        $SED_CMD "s/\$${containers[$i]}/$loadBalancerBaseIP$i/g" srcs/containers/nginx/srcs/localhost/index.html
    done
}

function _dockerBuildContainers {
    for container in "${containers[@]}"; do
        _TIMESTAMP Building $container:$MAINTAINER
        _SAFE docker build -t $container:$MAINTAINER ./srcs/containers/$container/ \
            --build-arg SSH_PASSWORD=$SSH_PASSWORD \
            --build-arg SSH_USER=$SSH_USER \
            --build-arg MYSQL_ROOT_PASSWORD=$MYSQL_ROOT_PASSWORD \
            --build-arg WP_USER=$WP_USER \
            --build-arg WP_PASSWORD=$WP_PASSWORD
    done
}

function _cleanUp {
    _TIMESTAMP no clean
    # rm -rf $binaries/
}

function _main {

    _TIMESTAMP "Preparing the .yaml files"
    _changeYamlHtmlIP

    _TIMESTAMP "install dependencies"
    _installScript

    _TIMESTAMP "Minikube restart"
    _SAFE minikube delete --all
    _SAFE minikube start $minikube_config

    _TIMESTAMP "Docker containers"
    eval $(minikube docker-env)
    _dockerBuildContainers

    _TIMESTAMP "Kubectl apply"
    _SAFE kubectl apply -k ./srcs/

    _TIMESTAMP "Waiting 15s for the pods and services..."
    sleep 10
    kubectl get all

    _cleanUp
}

#      _             _
#  ___| |_ __ _ _ __| |_
# / __| __/ _` | '__| __|
# \__ \ || (_| | |  | |_
# |___/\__\__,_|_|   \__|
#

_main
# $minikube service wordpress
