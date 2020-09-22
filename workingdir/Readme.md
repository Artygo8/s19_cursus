# for the https not connecting (thisisunsafe): https://medium.com/@dblazeski/chrome-bypass-net-err-cert-invalid-for-development-daefae43eb12
# for the ssh warning message: https://stackabuse.com/how-to-fix-warning-remote-host-identification-has-changed-on-mac-and-linux/
# https://matthewpalmer.net/kubernetes-app-developer/articles/kubernetes-apiversion-definition-guide.html


https://stackoverflow.com/questions/41512237/how-to-execute-a-shell-command-before-the-entrypoint-via-the-dockerfile#:~:text=You%20can%20only%20have%20one,image%20once%20it%20is%20built.

# take 3 first numbers around `kubectl get nodes -o wide` ex:(192.168.64.1 for mac) for the loadBalancerIP

> kubectl get configmap influxdb-config --export -o yaml >> influxdb-config.yaml

https://kubernetes.io/docs/reference/kubectl/cheatsheet/

# best resource
https://octoperf.com/blog/2019/09/19/kraken-kubernetes-influxdb-grafana-telegraf/


../../../binaries/kubectl create configmap influxdb-config --from-file=influxdb-datasource.yml
../../../binaries/kubectl get configmap influxdb-config --export -o yaml >> influxdb-datasource.yaml
