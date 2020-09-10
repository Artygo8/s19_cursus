#!/usr/bin/env bash

#                   _       _     _
#  __   ____ _ _ __(_) __ _| |__ | | ___  ___
#  \ \ / / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#   \ V / (_| | |  | | (_| | |_) | |  __/\__ \
#    \_/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/
#

containers=("nginx" "mysql" "wordpress" "phpmyadmin" "ftps")
minikube_config="--cpus=2 --disk-size 9000 --addons dashboard --addons metallb"

minikube=${minikube:-minikube}

MYSQL_ROOT_PASSWORD="password"
WP_USER="john"
WP_PASSWORD="snow"
SSH_USER="ssh-user"
SSH_PASSWORD="ssh-password"

STARTTIME=$(date +%s)
MAINTAINER="agossuin"

#   __                  _   _
#  / _|_   _ _ __   ___| |_(_) ___  _ __  ___
# | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
# |  _| |_| | | | | (__| |_| | (_) | | | \__ \
# |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
#

function _SAFE {
    $@ || (echo "COMMAND FAILED:" $@ && exit 1)
}

function _TIMESTAMP {
    tput setaf 3
    echo
    ENDTIME=$(date +%s)
    echo "[$(($ENDTIME - $STARTTIME))s] $@"
    tput sgr0
}

function _docker_build_containers {
    for container in "${containers[@]}"; do
        _TIMESTAMP Building $container:$MAINTAINER
        _SAFE docker build -t $container:$MAINTAINER ./srcs/containers/$container/ \
            --build-arg SSH_PASSWORD=$SSH_PASSWORD \
            --build-arg SSH_USER=$SSH_USER \
            --build-arg MYSQL_ROOT_PASSWORD=$MYSQL_ROOT_PASSWORD \
            --build-arg WP_USER=$WP_USER \
            --build-arg WP_PASSWORD=$WP_PASSWORD > /dev/null
    done
}

function _clean_up {
    rm -rf minikube/
}

function _main {

    _TIMESTAMP "Minikube restart"
    $minikube delete --all
    _SAFE $minikube start $minikube_config

    _TIMESTAMP "Docker containers"
    eval $($minikube docker-env)
    _docker_build_containers

    _TIMESTAMP "Kubectl apply"
    _SAFE kubectl apply -k ./srcs/

    _TIMESTAMP "Waiting 15s for the pods and services..."
    sleep 10
    kubectl get all

    _clean_up
}

#      _             _
#  ___| |_ __ _ _ __| |_
# / __| __/ _` | '__| __|
# \__ \ || (_| | |  | |_
# |___/\__\__,_|_|   \__|
#

_main
# $minikube service wordpress
