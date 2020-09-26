#!/bin/sh

/etc/init.d/sshd restart
(telegraf && killall nginx)&

function _monitor {
	while [ -e run/sshd.pid ]; do
    		sleep 3
	done
	killall nginx
}

_monitor &
nginx -g "daemon off;"
