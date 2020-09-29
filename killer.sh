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

usage="USAGE : ./killer.sh   ftps | grafana | influxdb | mysql | wordpress (wp) | phpmyadmin (pma) | nginx | telegraf | sshd

remove 1 at the time then verify that the pod restarts with kubectl get pods

`kubectl get pods`"

function apply {
	tput setaf 3
	for deployment in ${DEPLOY[@]}; do
		FUNCTION="kubectl exec deploy/${deployment} -- pkill $APP"
		echo $FUNCTION
		$FUNCTION
	done
	tput sgr0
}

case $APP in
	grafana)
		;;
	telegraf)
		DEPLOY=("influxdb" "nginx" "ftps" "wordpress" "phpmyadmin" "mysql" "grafana")
		;;
	sshd | nginx)
		DEPLOY="nginx"
		;;
	influx | influxd | influxdb)
		APP="influxd"
		DEPLOY="influxdb"
		;;
	ftps | ftp | pure-ftpd)
		APP=$ftps_app
		DEPLOY="ftps"
		;;
	wp | wordpress)
		APP=$wp_app
		DEPLOY="wordpress"
		;;
	pma | phpmyadmin)
		APP=$pma_app
		DEPLOY="phpmyadmin"
		;;
	mysql | mysqld)
		APP="mysqld"
		DEPLOY="mysql"
		;;
	*)
		echo "Invalid option !"
		echo "$usage"
		exit
		;;	
esac

[ -x ./nc_test.sh ] && ./nc_test.sh
apply
[ -x ./nc_test.sh ] && ./nc_test.sh
