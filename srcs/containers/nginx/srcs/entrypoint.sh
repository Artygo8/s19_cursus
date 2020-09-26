#!/bin/sh

/etc/init.d/sshd restart
(telegraf; pkill nginx)&

function _monitor {
	sleep 1
	while [ -e run/sshd.pid ]; do
    		sleep 3
	done
	pkill nginx
}

_monitor &
nginx -g "daemon off;"
