#!/bin/bash
STARTTIME=$(date +%s)
MAINTAINER="agossuin"
#
function _timestamp {
    ENDTIME=$(date +%s)
    tput setaf 3
    echo "[$(($ENDTIME - $STARTTIME))s] $@"
    tput sgr0
}

function _docker_build {
    _timestamp Building $@:$MAINTAINER
    docker build -t $@:$MAINTAINER ./srcs/$@/ > /dev/null || exit
}

#figlet "Ft Services"
tput setaf 6
echo  " _____ _     ____                  _
|  ___| |_  / ___|  ___ _ ____   _(_) ___ ___  ___
| |_  | __| \___ \ / _ \ '__\ \ / / |/ __/ _ \/ __|
|  _| | |_   ___) |  __/ |   \ V /| | (_|  __/\__ \\
|_|    \__| |____/ \___|_|    \_/ |_|\___\___||___/"
tput sgr0

# Docker Machine Restart

# Minikube Restart
_timestamp Minikube Delete
minikube delete --all

_timestamp Minikube Start
minikube start --cpus=2 \
        --disk-size 6000 \
        --addons dashboard \
        --addons metallb

# Variables
MINIKUBE_IP=`minikube ip`
echo https://$MINIKUBE_IP/

eval $(minikube docker-env)

# kubectl create -f ./srcs/yaml/pv.yaml
# kubectl create -f ./srcs/yaml/pvc.yaml

_docker_build mysql
_docker_build nginx
_docker_build wordpress

kubectl apply -k ./srcs/yaml/
