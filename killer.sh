#!/bin/bash

DEPLOY=$1
APP=$1
FUNCTION="kubectl exec deploy/${DEPLOY}-deployment -- pkill $APP"

function apply {
	echo $FUNCTION
	$FUNCTION
}

if [ $APP == "telegraf" ]; then
	for i in {"nginx" "ftps" "grafana" "mysql" "phpmyadmin" "wordpress"}; do
		APP=$i
		apply
	done
	exit
fi

if [ $APP == "sshd" ]; then
	DEPLOY="nginx"
fi

if [ $APP == "ftps" ]; then
	APP=pure-ftpd
fi

apply
