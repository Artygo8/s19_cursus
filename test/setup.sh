#!/usr/bin/env bash

STARTTIME=$(date +%s)
MAINTAINER="agossuin"

function _timestamp {
    ENDTIME=$(date +%s)
    tput setaf 3
    echo "[$(($ENDTIME - $STARTTIME))s] $@"
    tput sgr0
}

function _docker_build {
    _timestamp Building $@:$MAINTAINER
    docker build -t $@:$MAINTAINER ./$@/ > /dev/null || exit
}


_timestamp minikube restart
minikube delete --all
minikube start --cpus=2 \
        --disk-size 6000 \
        --addons dashboard \
        --addons metallb

eval $(minikube docker-env)

_timestamp image building
_docker_build mysql
_docker_build wordpress


_timestamp kubectl apply
kubectl apply -k ./


echo
_timestamp sleep 15
sleep 15
echo
# kubectl get secrets
# kubectl get pvc
kubectl get pods
# kubectl get services wordpress
_timestamp Starting service
minikube service wordpress


# Run the following command to delete your Secret, Deployments, Services and PersistentVolumeClaims:
# kubectl delete -k ./
