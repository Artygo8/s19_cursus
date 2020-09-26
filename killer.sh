#!/bin/bash

#
# this script requires 1 arg, the service that you want to kill
# modify FUNCTION in the "function apply" according to your needs
#

DEPLOY=$1
APP=$1

# Config
ftps_app="pure-ftpd"
wp_app="lighttpd"
pma_app="lighttpd"

HELP="USAGE : ./killer.sh   ftps | grafana | influxdb | mysql | wordpress (wp) | phpmyadmin (pma) | nginx | telegraf | sshd"

function apply {
	if [ $APP == "telegraf" ];then	
		for i in "nginx" "ftps" "grafana" "mysql" "phpmyadmin" "wordpress"; do
			DEPLOY=$i
			FUNCTION="kubectl exec deploy/${DEPLOY}-deployment -- pkill $APP"
			echo $FUNCTION
			$FUNCTION
		done
	else
		FUNCTION="kubectl exec deploy/${DEPLOY}-deployment -- pkill $APP"
		echo $FUNCTION
		$FUNCTION
	fi
}

if [ $# == 0 ]; then
	echo $HELP
	echo
	echo "remove 1 at the time then verify that the pod restarts with kubectl get pods"
	echo
	kubectl get pods
	exit
fi

if [ $APP == "sshd" ]; then
	DEPLOY="nginx"

elif [ $APP == "influxdb" ]; then
	APP="influxd"

elif [ $APP == "ftps" ]; then
	APP=$ftps_app

elif [ $APP == "wp" ] || [ $APP == "wordpress" ]; then
	APP=$wp_app
	DEPLOY="wordpress"
elif [ $APP == "pma" ] || [ $APP == "phpmyadmin" ]; then
	APP=$pma_app
	DEPLOY="phpmyadmin"
fi

if [ -e ./nc_test.sh ]; then
	./nc_test.sh
	tput setaf 3
	apply
	tput sgr0
	./nc_test.sh
else
	apply
fi
