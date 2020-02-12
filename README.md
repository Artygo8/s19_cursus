# Cleaning
docker image rm debian:buster
docker system prune -f

# Build the image
docker build -t hello:hello .

# Run the image
docker run -it hello:hello bash

docker build --ssh default .

service nginx start

/var/lib/wordpress#

docker-machine create
docker-machine ls
docker-machine env

docker run -d -p 80:80 9ee3b6c48418
docker run -d -i -p 80:80 hello:hello

#####################
srcs/config.inc.php
$cfg['blowfish_secret'] = 'STRINGOFTHIRTYTWORANDOMCHARACTERS';
####################


docker run --name he:he -d -i -p 80:80 -p 443:443 yo:yo
