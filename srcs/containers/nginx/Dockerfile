FROM alpine:3.11

ARG SSH_USER
ARG SSH_PASSWORD

RUN echo "@testing http://dl-cdn.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories

# install what we need
RUN apk update && apk add nginx openssl openssh openrc telegraf@testing

# create a new user
RUN adduser -D -g '' $SSH_USER;\
    echo "$SSH_USER:$SSH_PASSWORD" | chpasswd

# copy
COPY srcs/default.conf /etc/nginx/conf.d/default.conf
COPY srcs/localhost/ /var/www/localhost/
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY srcs/entrypoint.sh /entrypoint.sh

# generate key and cert for ssl
RUN openssl req -new -x509 -nodes -sha256 -days 365 -keyout /etc/ssl/host.key -out /etc/ssl/host.cert -subj '/CN=BE/O=agossuin'

# nginx test config
RUN mkdir /var/run/nginx/;\
    nginx -t

RUN openrc;\
    touch /run/openrc/softlevel;\
    rc-update add sshd && rc-status

EXPOSE 22 80 443

ENTRYPOINT [ "sh", "/entrypoint.sh" ]
