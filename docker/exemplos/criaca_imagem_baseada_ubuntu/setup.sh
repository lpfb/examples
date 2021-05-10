#! /bin/bash

echo "Criando imagem lbarros/ubuntu a partir de DockerFile"
docker build -f Dockerfile -t lbarros/ubuntu .

echo "Abrindo container em modo iterativo (terminal)"
docker run -it lbarros/ubuntu
