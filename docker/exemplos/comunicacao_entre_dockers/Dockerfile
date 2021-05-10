# Informa qual imagem base deve ser utilizada
FROM ubuntu:18.04

# Define o nome do autor
MAINTAINER Luis Paulo

# Instala dependencias
#   OBS: tem que vir acompanhado do apt-get update, senao nao funciona
RUN apt-get update && apt-get install -y \
    iputils-ping

# Cria variavel de ambiente
ENV AUTHOR="LUIS PAULO"

# Informa o docker para iniciar dentro desta pasta
WORKDIR /home/

# Cria arquivo usano a variavel de ambiente
RUN echo "Ola $AUTHOR, teste rodando ok" > teste.txt
