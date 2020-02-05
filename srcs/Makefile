NAME		= server

# NGINX
NG			= nginx

# Package Manager
PM			= apt-get
INST		= install -y

# Beautify
BF			= echo "======================="

# RULES
$(NAME):	${PM} ${NG}
			@ ${BF} && echo "=== BUILDING SERVER ===" && ${BF}

$(PM):
			@${BF} && echo "===   UPDATING PM   ===" && ${BF}
			${PM} update

$(NG):
			@${BF} && echo "=== BUILDING NGINX  ===" && ${BF}
			@${PM} ${INST} ${NG}
