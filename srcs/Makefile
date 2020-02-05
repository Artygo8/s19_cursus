NAME		= server

# WordPress
WP			= wordpress

# NGINX
NG			= nginx

# Package Manager
PM			= apt-get
INST		= install -y

# Beautify
BF			= echo "======================="

# RULES
$(NAME):	${PM} ${NG}
			@${BF} && echo "=== BUILDING SERVER ===" && ${BF}

$(PM):
			@${BF} && echo "===   UPDATING PM   ===" && ${BF}
			@${PM} update

$(WP):
			@${BF} && echo "===    WordPress    ===" && ${BF}
			@${PM} ${INST} ${WP}
			#wget https://wordpress.org/latest.tar.gz
			#tar xpf latest.tar.gz
			#ls

$(NG):		${PM}
			@${BF} && echo "=== BUILDING NGINX  ===" && ${BF}
			@${PM} ${INST} ${NG}
			@service ${NG} start

# Utils
wget:
			@echo "########### wget ###########"
			${PM} ${INST} wget

tar:
			@echo "########### tar  ###########"
			${PM} ${INST} tar
