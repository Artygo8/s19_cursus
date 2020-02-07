NAME		= ft_server

# Server Objects
WP			= wordpress
NG			= nginx
PHP			= php
SQL			= mysql
MDB			= mariadb
GNUP		= gnupg
PMA			= phpmyadmin

# Package Manager
PM			= apt-get
INST		= install -y

# Beautify
BF			= echo "======================="

# RULES
$(NAME):	${NG} ${MDB}
			service ${NG} start

# # # # # # # #
# THE OBJECTS #
# # # # # # # #

$(GNUP):
			${PM} ${INST} $(GNUP)

$(PM):
			${PM} ${INST} lsb-release
			${PM} update

$(WP):		${PM}
			${PM} ${INST} ${WP}

$(NG):		${PM}
			${PM} ${INST} ${NG}

$(MDB):		${PM} sudo
			${PM} ${INST} ${MDB}-server ${MDB}-client
			sudo mysql_secure_installation

$(PMA):		${PM} mysql sudo
	sudo mv phpMyAdmin-4.9.0.1-english/ /usr/share/phpmyadmin
	sudo mkdir -p /var/lib/phpmyadmin/tmp
	sudo chown -R www-data:www-data /var/lib/phpmyadmin

# Utils
wget:		${PM}
			${PM} ${INST} wget

tar:		${PM}
			${PM} ${INST} tar

sudo:		${PM}
			${PM} ${INST} sudo
