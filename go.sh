minikube start

eval $(minikube docker-env)

# Nginx
# https://www.youtube.com/watch?v=BDrcUjOczsE
cd srcs/nginx && ./docker-restart.sh && cd ../..
kubectl run mynginx --image=mynginx:mynginx --image-pull-policy=Never
kubectl run myhttpsnginx --image=mynginx:mynginx --image-pull-policy=Never
kubectl get deployment
kubectl get pod
kubectl expose pod mynginx --type=LoadBalancer --port=80
kubectl expose pod myhttpsnginx --type=LoadBalancer --port=443 --target-port=8443
kubectl get services
minikube service mynginx
