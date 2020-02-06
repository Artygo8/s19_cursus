# Cleaning
docker image rm debian:buster
docker system prune -f

# Build the image
docker build -t hello:hello .

# Run the image
docker run -it 72b34c405a19 bash

docker build --ssh default .


/var/lib/wordpress#

docker-machine create
docker-machine ls
docker-machine env

docker run -d -p 80:80 7fefabbbf0e4
docker run -d -i -p 80:80 13d5ad650769
