#!/bin/sh
name="grafana"
echo -e "\033[31mdocker stop $name \033[0m"
docker kill $name

echo -e "\033[31mdocker rm $name \033[0m"
docker rm $name

echo -e "\033[31mdocker rmi test:$name \033[0m"
docker rmi test:$name -f

echo -e "\033[31mdocker system prune \033[0m"
docker system prune -f

echo -e "\033[31mdocker build test:$name \033[0m"
docker build -t test:$name .

echo -e "\033[31mdocker run \033[0m"
# docker run --name $name -d -p 443:443 -i test:$name
docker run --name $name -d -i -p 80:80 -p 443:443 test:$name
docker run -it test:$name sh
# docker run -d -p 80:80 test:$name
