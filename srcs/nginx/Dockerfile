FROM alpine:3.11

RUN apk update
RUN apk add nginx openssl

COPY srcs/nginx.conf    /etc/nginx/nginx.conf
COPY srcs/index.html    /www/localnginx/index.html
COPY srcs/conf.d        /etc/nginx/conf.d

RUN mkdir /var/run/nginx/ && touch /var/run/nginx/nginx.pid

RUN openssl genrsa 2048 > /etc/ssl/host.key
RUN chmod 400 /etc/ssl/host.key
RUN openssl req -new -x509 -nodes -sha256 -days 365 -key /etc/ssl/host.key -out /etc/ssl/host.cert -subj '/CN=BE/O=agossuin'

RUN nginx -t

ENV host 'www/localnginx/'

EXPOSE 80 443

CMD nginx -g 'daemon off;'
