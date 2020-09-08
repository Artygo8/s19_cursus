#!/usr/bin/env bash
SSH_USER="uuu"
SSH_PASSWORD="ppp"

STARTTIME=$(date +%s)
MAINTAINER="agossuin"

function _SAFE {
    $@ || (echo "COMMAND FAILED:" $@ && exit 1)
}

function _TIMESTAMP {
    ENDTIME=$(date +%s)
    tput setaf 3
    echo
    echo "[$(($ENDTIME - $STARTTIME))s] $@"
    tput sgr0
}

function _docker_build {
    _TIMESTAMP Building $1:$MAINTAINER
    _SAFE docker build -t $1:$MAINTAINER ./containers/$1/ ${@:2} > /dev/null || exit
}

_TIMESTAMP "Minikube restart"

minikube delete --all
_SAFE minikube start --cpus=2 \
        --disk-size 9000 \
        --addons dashboard \
        --addons metallb

eval $(minikube docker-env)

# _docker_build mysql
# _docker_build wordpress
# _docker_build phpmyadmin
# _docker_build ftps
_docker_build nginx --build-arg SSH_PASSWORD=$SSH_PASSWORD --build-arg SSH_USER=$SSH_USER


_TIMESTAMP "Kubectl apply"
_SAFE kubectl apply -k ./yaml/


_TIMESTAMP "Waiting 15s for the pods and services..."
sleep 15

kubectl get all

_TIMESTAMP "Starting service"
_SAFE minikube service nginx

# for the https not connecting (thisisunsafe): https://medium.com/@dblazeski/chrome-bypass-net-err-cert-invalid-for-development-daefae43eb12
# for the ssh warning message: https://stackabuse.com/how-to-fix-warning-remote-host-identification-has-changed-on-mac-and-linux/
