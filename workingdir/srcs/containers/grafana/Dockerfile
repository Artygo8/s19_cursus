FROM alpine:3.12

RUN echo "@testing http://dl-cdn.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories

RUN apk update && apk add openrc grafana@testing telegraf@testing
# grafana-image-renderer@testing

# RUN grafana-cli plugins install grafana-kubernetes-app
# RUN grafana-cli plugins install grafana-piechart-panel
# RUN grafana-cli plugins install blackmirror1-singlestat-math-panel
RUN grafana-cli plugins install grafana-clock-panel

COPY ./srcs/grafana.ini /etc/grafana.ini
COPY ./srcs/provisioning /etc/grafana/provisioning
COPY ./srcs/dashboards /var/lib/grafana/dashboards
COPY ./srcs/telegraf.conf /etc/telegraf/telegraf.conf

EXPOSE 3000

CMD nohup sh -c "telegraf &";\
  exec grafana-server \
  --homepath="/usr/share/grafana" \
  --config="/etc/grafana.ini" \
  --packaging=docker