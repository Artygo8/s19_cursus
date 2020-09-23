FROM alpine:3.11

ARG FTP_USER="ftp_user"
ARG FTP_PASSWORD="ftp_password"

RUN echo "@testing http://dl-cdn.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories

# install what we need
RUN apk update && apk add vsftpd openssl telegraf@testing

# create a new user
RUN adduser -D -g '' $FTP_USER;\
    echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

RUN mkdir /home/$FTP_USER/ftp;\
    chown nobody:nogroup /home/$FTP_USER/ftp;\
    chmod a-w /home/$FTP_USER/ftp;\
    mkdir /home/$FTP_USER/ftp/files;\
    chown $FTP_USER:$FTP_USER /home/$FTP_USER/ftp/files;\
    echo coucou > /home/$FTP_USER/ftp/files/hello.txt;\
    echo $FTP_USER >> /etc/vsftpd.userlist;

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.crt -subj '/CN=BE/O=agossuin'

# copy
COPY srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY srcs/anon.txt /srv/ftp/anon.txt
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf

VOLUME [ "/home/$FTP_USER/ftp/files" ]

EXPOSE 21

ENTRYPOINT nohup sh -c "telegraf &"; vsftpd /etc/vsftpd/vsftpd.conf
