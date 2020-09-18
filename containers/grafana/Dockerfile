FROM alpine:3.11

RUN adduser -D -g 'www' www
RUN apk update
RUN echo @testing http://nl.alpinelinux.org/alpine/edge/testing >> /etc/apk/repositories
#RUN apk add grafana* --update-cache --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted
RUN apk add grafana@testing grafana-image-renderer@testing


RUN echo server_url = http://127.0.0.1:3001/render >> /etc/grafana.ini
RUN echo callback_url = http://127.0.0.1:3000/ >> /etc/grafana.ini

#RUN /etc/init.d/grafana-image-renderer start
#RUN rc-service grafana start
RUN rc-update add grafana default
RUN reboot

#mkdir /run/openrc
#touch /run/openrc/softlevel
#rc-service grafana status

CMD /etc/init.d/grafana-image-renderer start
