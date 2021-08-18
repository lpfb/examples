# Sintaxe basica
## FROM *
Utilizado para usar uma imagem contida em Docker Hub como base para o desenvolvimento, exemplos:
- FROM ubuntu:latest
    - Lastest indica que queremos a versao mais recente disponivel
- FROM ubuntu:14.04
- FROM node

## MAINTAINER
Usado para informar que eh o mantenedor/criador do dokcer:
- MAINTAINER Luis Paulo

## COPY
Se for preciso copiar algo do PC host para dentro do docker durante a criaçao do mesmo, eh atraves deste comando que isso deve ser feito:
- COPY <Caminho arquivo pc HOST> <Pasta de destino docker>
    - Ex: COPY . /var/www, copia tudo da pasta atual e salva no container em /var/www

## RUN
Usado para rodar comandos dentro do docker, usado tipicamente para instalar dependencias:
- RUN <Comando de instalacao>
    - Ex: RUN apt install python3

## ENTRYPOINT
Utilizado para rodar um comando assim que o container eh iniciado, pode ser um script, uma aplicacao e etc:
- ENTRYPOINT "SCRIPT ou COMANDO"
    - Ex: ENTRYPOINT npm start, usado para iniciar a aplicacao nodejs

## EXPOSE
Instrucao usada para informar ao docker que o container estara escutando em uma porta em especifico durante a execucao. Esta instrucao nao publica a porta, mas server como um tipo de documentacao entre quem construiu a imagem e quem vai utilizar o container. Eh possivel informar o protocolo que eh utilizado tambem, mas isso eh opcional.
- EXPOSE <port>/<protocol>
    - Ex: EXPOSE 80/tcp

# WORKDIR
Diretorio de trabalho em que o container vai iniciar quando for iniciado.
- WORKDIR /var/www

# ENV
Configura variaveis de ambiente para serem utilizadas dentro do container.
- ENV <key>=<value> ...
    - ex: ENV NAME="Luis"
    - ENV MY_NAME="John Doe" MY_DOG="Rex The Dog"
        - Eh possivel usar mais de uma variavel na mesma linha ou usar varias linhas de atribuicao

# Exemplo de uso
Os DockerFile's devem seguir um padrao de nome:
- Se existir apenas um arquivo desse tipo no diretorio, podemos usaro nome: **Dockerfile**
- Se existir mais de um arquivo desse tipo no diretorio atual, devemos usar a convensao: <nome container>.dockerfile

## Criando um Dokerfile simples
1. Crie um arquivo chamado **Dockerfile** com o conteudo abaixo:
```dockerfile
# Informa qual imagem base deve ser utilizada
FROM ubuntu:18.04

# Define o nome do autor
MAINTAINER Luis Paulo

# Instala dependencias
#   OBS: tem que vir acompanhado do apt-get update, senao nao funciona
RUN apt-get update && apt-get install -y \
    vim \
    python3
# Cria variavel de ambiente
ENV AUTHOR="LUIS PAULO"

# Informa o docker para iniciar dentro desta pasta
WORKDIR /home/

# Cria arquivo usano a variavel de ambiente
RUN echo "Ola $AUTHOR, teste rodando ok" > teste.txt

```
1. Criando a imagem
    - Criando sem especificar nome. O Container sera referenciado com um ID (hash)
```sh
# O ponto serve para especificar onde o Dockerfile se encontra
docker build -f Dockerfile .
```
    - Criando container especificando um nome
        - O padrao de nome que se utiliza eh: <nome do autor>/<nome da imagem>
```sh
docker build -f Dockerfile -t lbarros/ubuntu .
```

# Publicando uma imagem no Docker Hub
1. Primeiro e preciso fazer o build da imagem e dar um nome (vide Criando um Dokerfile simples)
1. Entao eh preciso criar uma conta no Docker Hub
1. Com a conta criada, rodar:
```sh
docker login
```
1. Para publicar a imagem
```sh
# docker push <nome da imagem>
# Exemplo:
docker push lbarros/ubuntu
```

# Baixando uma imagem do Docker Hub sem compilar
```sh
docker pull <nome da imagem>
```
