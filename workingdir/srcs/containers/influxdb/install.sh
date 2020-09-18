#!/usr/bin/env bash

binaries="bin"

function _install_script {
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
        sh ./$binaries/dockerd-rootless.sh --experimental --storage-driver vfs > /dev/null &
        systemctl --user start docker > /dev/null
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

_install_script
# docker build -t influxdb:agossuin .
docker run -it influxdb:alpine sh

rm -rf $binaries