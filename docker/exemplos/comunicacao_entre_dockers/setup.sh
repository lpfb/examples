#! /bin/bash

echo "Criando imagem lbarros/ubuntu a partir de DockerFile"
docker build -f Dockerfile -t lbarros/ubuntu .

echo "Subindo rede rede com nome minha-rede do tipo bridge"
docker network create --driver bridge minha-rede

docker rm ubuntu-um
docker rm ubuntu-dois
gnome-terminal --tab --title="ubuntu-um" -- docker run -it --name ubuntu-um --network minha-rede lbarros/ubuntu
gnome-terminal --tab --title="ubuntu-dois" -- docker run -it --name ubuntu-dois --network minha-rede lbarros/ubuntu

echo "================================"
echo "Testando a rede"
echo "================================"
echo "No container ubuntu-um (primeira aba aberta), digite o comando abaixo para pingar o outro container:"
echo "> ping ubuntu-dois"
echo "No container ubuntu-dois (segunda aba aberta), digite o comando abaixo para pingar o outro container:"
echo "> ping ubuntu-um"

