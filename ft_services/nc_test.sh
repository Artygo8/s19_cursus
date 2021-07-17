#!/bin/bash

baseIP=172.17.0.1

services=("nginx" "wp" "pma" "ftps" "grafana")
declare -A endIP=( [nginx]=0 [wp]=1 [pma]=2 [ftps]=3 [grafana]=4 )
declare -A ports=( [nginx]="80 443 22" [wp]=5050 [pma]=5000 [ftps]=21 [grafana]=3000 )

function try_connect {
	service=$1
	service_ports=${ports[$service]}
	for port in $service_ports; do
		echo -n $service $port: && \
		(nc -zv ${baseIP}${endIP[$service]} $port 2> /dev/null && echo ok!) || echo not connected...
	done
}

for svc in ${services[@]}; do
	try_connect $svc
done
