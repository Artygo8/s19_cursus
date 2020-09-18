FROM grafana/grafana:6.5.3

COPY grafana.db /var/lib/grafana/grafana.db
RUN cat /run.sh 1>&2

ENTRYPOINT [ "/run.sh" ]