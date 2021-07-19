# Geral
O docker por padro jah cria uma rede local que permite a comunicacao entre os containers. O problema dessa rede eh que o IP dos containers eh dinamico, ou seja, cada vez que um containers sobe ele pode redecer um ip diferente.

Para listar as redes do docker basta rodar:
```sh
docker network ls
```

## Fazendo o ping de um container usando a rede deafult
Em um terminal (terminal 1)
1. docker run -it ubuntu
1. hostname -i
    - Ex: 172.18.0.2

Em outro terminal (terminal 2)
1. docker run -it ubuntu
1. hostname -i
    - Ex: 172.18.0.3

Cada um deles vai informa seu ip, com esta informaçao basta, por exemplo, entra no container do terminal 1 e rodar
```sh
# Instalando o pacote de ping, por padrao a imagem ubuntu do docker vem sem
apt-get update && apt-get install -y iputils-ping
ping 172.18.0.3
```

Conforme foi dito, o problema dessa abordagem eh que a rede default do docker nao aceita configuracao de hostname e a cada hora o docker pode assumir um ip diferente.

## Criando uma rede e conectado containeres
Comando usado para criar uma rede com o driver tipo brige. Existem outros tipos de drivers, mas este e o mais comum e funciona na maioria dos casos.
```sh
docker network create --driver bridge <nome da rede>
```

### Exemplo de configuraçao e utilizaçao
Para tonar a comunicacao facil e independente do ip, eh necessario subir os containers com a flag **--name** que serah usado pela docker network como hostname.

1. Criando uma rede
```sh
docker network create --driver bridge minha-rede
```
1. Verificando que a rede foi criada
```sh
docker network ls | grep minha-rede
```
1. Subindo o container **ubuntu-um** em um terminal e atrelando ele a uma rede
```sh
docker run -it --name ubuntu-um --network minha-rede ubuntu
```
1. Subindo o container **ubuntu-dois** em outro terminal e atrelando ele a uma rede
```sh
docker run -it --name ubuntu-dois --network minha-rede ubuntu
```
1. Eh possivel inspecionar as configuracoes do container, inclusive a qual rede esta atrelado, com o comando
```sh
# docker inspect <container-name/id>
# Ex:
docker inspect ubuntu-um
```
1. Tambem eh possivel inspecionar quem esta conectado em uma rede docker com o comando
```sh
# docker inspect <nome da rede>
# Ex:
docker inspect minha-rede
```
1. Efetuando o ping do container ubuntu-um dentro do container ubuntu-dois
```sh
apt-get update && apt-get install -y iputils-ping
ping ubuntu-um
```
1. Efetuando o ping do container ubuntu-dois dentro do container ubuntu-um
```sh
apt-get update && apt-get install -y iputils-ping
ping ubuntu-dois
```
