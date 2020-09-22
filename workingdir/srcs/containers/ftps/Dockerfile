FROM alpine:3.11

RUN echo "@testing http://dl-cdn.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories

# install what we need
RUN apk update && apk add vsftpd openrc telegraf@testing

# copy
COPY srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY srcs/anon.txt /srv/ftp/anon.txt
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf

# openrc for sshd
RUN openrc;\
    touch /run/openrc/softlevel;\
    rc-update add vsftpd && rc-status

EXPOSE 21

ENTRYPOINT nohup sh -c "telegraf &"; openrc

#https://www.installerunserveur.com/configuration-vsftpd
#https://osxdaily.com/2011/02/07/ftp-from-mac/
