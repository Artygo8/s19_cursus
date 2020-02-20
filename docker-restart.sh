#!/bin/sh
echo -e "\033[31mdocker stop john \033[0m"
docker kill john

echo -e "\033[31mdocker rm john \033[0m"
docker rm john

echo -e "\033[31mdocker rmi test:test \033[0m"
docker rmi test:test -f

echo -e "\033[31mdocker system prune \033[0m"
docker system prune -f

echo -e "\033[31mdocker build test:test \033[0m"
docker build -t test:test .

echo -e "\033[31mdocker run \033[0m"
#docker run --name john -d -p 443:443 -i test:test
docker run --name john -d -i -p 80:80 -p 443:443 test:test
docker run -it test:test bash
#docker run -d -p 80:80 test:test
