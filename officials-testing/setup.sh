#!/usr/bin/env bash

minikube delete --all
minikube start --cpus=2 \
        --disk-size 6000 \
        --addons dashboard \
        --addons metallb

eval $(minikube docker-env)
sleep 3

kubectl apply -k ./

sleep 100
minikube service wordpress

# kubectl exec -it wordpress-mysql-db4bff4b-7626q /bin/sh
# SHOW DATABASES;
# mysql -u root -p
