#!/bin/bash

#
# this script requires 1 arg, the service that you want to kill
# modify FUNCTION in the "function apply" according to your needs
#

DEPLOY=$1
APP=$1

function apply {
	FUNCTION="kubectl exec deploy/${DEPLOY}-deployment -- pkill $APP"
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

if [ -e ./nc_test.sh ]; then
	./nc_test.sh
fi
