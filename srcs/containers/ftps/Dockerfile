FROM alpine:latest

ARG FTP_USER=user
ARG FTP_PASSWORD=password

RUN echo "@testing http://dl-cdn.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories

RUN apk update && apk add openssl pure-ftpd@testing telegraf@testing

RUN adduser -D -g '' $FTP_USER;\
    echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf

RUN mkdir -p /ftps/$FTP_USER

RUN openssl req -x509 -nodes -days 7300 -newkey rsa:2048 -subj "/CN=BE/O=agossuin" -keyout /etc/ssl/private/pure-ftpd.pem -out /etc/ssl/private/pure-ftpd.pem

RUN chmod 600 /etc/ssl/private/pure-ftpd.pem

EXPOSE 21 21000

CMD nohup sh -c "telegraf &"; /usr/sbin/pure-ftpd -j -Y 2 -p 21000:21000 -P "172.17.0.13"