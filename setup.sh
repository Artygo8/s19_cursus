# linux installation

# install kubectl
curl -LO https://storage.googleapis.com/kubernetes-release/release/`curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt`/bin/linux/amd64/kubectl
chmod +x ./kubectl
sudo mv ./kubectl /usr/local/bin/kubectl
kubectl version --client

# install virtualization
sudo apt install kvm -y

# install minikube
curl -Lo minikube https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64 && chmod +x minikube
sudo mkdir -p /usr/local/bin/
sudo install minikube /usr/local/bin/

#If you have previously installed Minikube, and run:

# minikube start
# and minikube start returned an error:

# machine does not exist
# then you need to clear minikube’s local state:

# minikube delete

# All process
minikube start \
    --network-plugin=cni \
    --enable-default-cni \
    --container-runtime=docker \
    --bootstrapper=kubeadm

minikube status

## start stuffs
kubectl create deployment hello-minikube --image=k8s.gcr.io/echoserver:1.10
# kubectl create deployment nginx --image=nginx
kubectl expose deployment hello-minikube --type=NodePort --port=8080
# kubectl expose deployment nginx --type=NodePort --port=8080
kubectl get pod
minikube service hello-minikube --url

## remove stuffs
kubectl delete services hello-minikube
kubectl delete deployment hello-minikube

minikube stop
minikube delete

# use the docker daemon
minikube docker-env

# extra settings example
--extra-config=kubelet.MaxPods=5

# DASHBOARD
minikube dashboard

# SERVICES
minikube service [-n NAMESPACE] [--url] NAME

# networking
minikube ip
kubectl get service $SERVICE --output='jsonpath="{.spec.ports[0].nodePort}"'

# persistent volumes https://kubernetes.io/docs/concepts/storage/persistent-volumes/
apiVersion: v1
kind: PersistentVolume
metadata:
  name: pv0001
spec:
  accessModes:
    - ReadWriteOnce
  capacity:
    storage: 5Gi
  hostPath:
    path: /data/pv0001/

# addons
minikube addons enable ingress
minikube addons enable ingress-dns
minikube start --addons ingress
minikube start --addons ingress-dns
minikube addons open ingress
minikube addons open ingress-dns
minikube addons disable

# Minikube tunnel for loadbalancer
minikube tunnel
minikube tunnel --cleanup


# private container registeries
https://kubernetes.io/docs/concepts/containers/images/

# http proxy
minikube start --docker-env http_proxy=http://$YOURPROXY:PORT \
                 --docker-env https_proxy=https://$YOURPROXY:PORT
export no_proxy=$no_proxy,$(minikube ip)
