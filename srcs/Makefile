NAME		= ft_server

# Server Objects
WP			= wordpress
NG			= nginx
PHP			= php
SQL			= mysql
MDB			= mariadb

# Package Manager
PM			= apt-get
INST		= install -y

# Beautify
BF			= echo "======================="

# RULES
$(NAME):	${PM} ${NG} ${SQL}
			@${BF} && echo "=== BUILDING SERVER ===" && ${BF}

$(PM):
			@${BF} && echo "===   UPDATING PM   ===" && ${BF}
			@${PM} update
			@apt update

$(WP):
			@${BF} && echo "===    WordPress    ===" && ${BF}
			@${PM} ${INST} ${WP}

$(NG):		${PM}
			@${BF} && echo "=== BUILDING NGINX  ===" && ${BF}
			${PM} ${INST} ${NG}
			@${BF} && echo "===   START NGINX   ===" && ${BF}
			service ${NG} start

$(PHP):
			@${BF} && echo "===    PhpMyAdmin   ===" && ${BF}
			@${PM} ${INST} ${PHP}

$(SQL):		${PHP}
			@${BF} && echo "===      MySQL      ===" && ${BF}
			@${PM} ${INST} ${PHP}-${SQL}

$(MDB):		${SQL}
			@${BF} && echo "===     MariaDB     ===" && ${BF}
			@${PM} ${INST} ${MDB}



















# Utils
wget:
			@echo "########### wget ###########"
			${PM} ${INST} wget

tar:
			@echo "########### tar  ###########"
			${PM} ${INST} tar
