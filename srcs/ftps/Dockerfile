FROM alpine:3.11

# install what we need
RUN apk update && apk add vsftpd openrc

# copy
COPY srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY srcs/anon.txt /srv/ftp/anon.txt

# openrc for sshd
RUN openrc
RUN touch /run/openrc/softlevel
RUN rc-update add vsftpd && rc-status

EXPOSE 21

ENTRYPOINT ["openrc"]
