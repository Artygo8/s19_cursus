#!/usr/bin/env bash

#                  _       _     _
# __   ____ _ _ __(_) __ _| |__ | | ___  ___
# \ \ / / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#  \ V / (_| | |  | | (_| | |_) | |  __/\__ \
#   \_/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/
#

STARTTIME=$(date +%s)
MAINTAINER="agossuin"

MYSQL_ROOT_PASSWORD="password"
WP_USER="john"
WP_PASSWORD="snow"
SSH_USER="ssh-user"
SSH_PASSWORD="ssh-password"

#  __                  _   _
# / _|_   _ _ __   ___| |_(_) ___  _ __  ___
#| |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
#|  _| |_| | | | | (__| |_| | (_) | | | \__ \
#|_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
#

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
    _SAFE docker build -t $1:$MAINTAINER ./containers/$1/ ${@:2} > /dev/null  || exit
}

#           _       _ _          _
# _ __ ___ (_)_ __ (_) | ___   _| |__   ___
#| '_ ` _ \| | '_ \| | |/ / | | | '_ \ / _ \
#| | | | | | | | | | |   <| |_| | |_) |  __/
#|_| |_| |_|_|_| |_|_|_|\_\\__,_|_.__/ \___|
#

_TIMESTAMP "Minikube restart"
minikube delete --all
_SAFE minikube start --cpus=2 --disk-size 9000 --addons dashboard --addons metallb

#     _            _
#  __| | ___   ___| | _____ _ __
# / _` |/ _ \ / __| |/ / _ \ '__|
#| (_| | (_) | (__|   <  __/ |
# \__,_|\___/ \___|_|\_\___|_|
#

eval $(minikube docker-env)

_docker_build mysql --build-arg MYSQL_ROOT_PASSWORD=$MYSQL_ROOT_PASSWORD --build-arg WP_USER=$WP_USER --build-arg WP_PASSWORD=$WP_PASSWORD
_docker_build wordpress --build-arg WP_USER=$WP_USER --build-arg WP_PASSWORD=$WP_PASSWORD
# _docker_build phpmyadmin
# _docker_build ftps
# _docker_build nginx --build-arg SSH_PASSWORD=$SSH_PASSWORD --build-arg SSH_USER=$SSH_USER

#                       _
# _   _  __ _ _ __ ___ | |
#| | | |/ _` | '_ ` _ \| |
#| |_| | (_| | | | | | | |
# \__, |\__,_|_| |_| |_|_|
# |___/

_TIMESTAMP "Kubectl apply"
_SAFE kubectl apply -k ./

#     _             _
# ___| |_ __ _ _ __| |_
#/ __| __/ _` | '__| __|
#\__ \ || (_| | |  | |_
#|___/\__\__,_|_|   \__|
#


_TIMESTAMP "Waiting 15s for the pods and services..."; sleep 15
kubectl get all
minikube service wordpress

# for the https not connecting (thisisunsafe): https://medium.com/@dblazeski/chrome-bypass-net-err-cert-invalid-for-development-daefae43eb12
# for the ssh warning message: https://stackabuse.com/how-to-fix-warning-remote-host-identification-has-changed-on-mac-and-linux/
