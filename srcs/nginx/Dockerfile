FROM alpine:3.11

# default arguments can be passed with `--build-arg <varname>=<value>`
ARG pass=SSH_PASSWORD
ARG user=SSH_USERNAME

# install what we need
RUN apk update && apk add nginx openssl openssh openrc

# create a new user
RUN adduser -D -g '' $user
RUN echo "$user:$pass" | chpasswd

# copy
COPY srcs/default.conf /etc/nginx/conf.d/default.conf
COPY srcs/localhost/ /var/www/localhost/

# generate key and cert for ssl
RUN openssl req -new -x509 -nodes -sha256 -days 365 -keyout /etc/ssl/host.key -out /etc/ssl/host.cert -subj '/CN=BE/O=agossuin'

# nginx test config
RUN mkdir /var/run/nginx/                                                       # To avoid "pid not found"
RUN nginx -t                                                                    # Test the config

# openrc for sshd
RUN openrc
RUN touch /run/openrc/softlevel
RUN rc-update add sshd && rc-status

EXPOSE 22 80 443

ENTRYPOINT openrc; nginx -g "daemon off;"





















#RUN openssl genrsa 2048 > /etc/ssl/host.key
#RUN chmod 400 /etc/ssl/host.key
#RUN openssl req -new -x509 -nodes -sha256 -days 365 -key /etc/ssl/host.key -out /etc/ssl/host.cert -subj '/CN=BE/O=agossuin'
