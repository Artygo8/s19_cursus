#!/usr/bin/env bash

# Minikube
if [[ -z `which minikube` ]]; then
    mkdir -p ./minikube
    curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
    install minikube-linux-amd64 ./minikube/minikube
    rm minikube-linux-amd64
fi
