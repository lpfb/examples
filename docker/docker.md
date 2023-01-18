# Instalacao
Referencia: https://docs.docker.com/engine/install/ubuntu/
```sh
sudo apt-get update
sudo apt-get install \
    ca-certificates \
    curl \
    gnupg \
    lsb-release
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin
sudo docker version
# para rexecutar o docker sem ser no modo sudo
sudo usermod -aG docker $(whoami)
```
# Entendo o docker run
Quando rodamos, por exemplo, o comando docker run hello-world, o que acontece é o seguinte:
1. o docker busca e baixa a imagem no docker Hub
```sh
docker pull hello-world
```
1. em seguida a imagem eh inicializada
```sh
docker start <image ID>
```
- Cada vez que rodamos o docker run, é criada um container com a imagem desejada e eh atribuido um nome, coluna NAMES, aleatorio ao mesmo.

# Conceitos gerais
## Volumes
Quando criamos um volume de dados, o que estamos fazendo é apontá-lo para uma pequena pasta no Docker Host. Então, quando criamos um volume, criamos uma pasta dentro do container, e o que escrevermos dentro dessa pasta na verdade estaremos escrevendo do Docker Host.

Isso faz com que não percamos os nossos dados, pois o container até pode ser removido, mas a pasta no Docker Host ficará intacta.

## Estados do docker
- Running
    - Pode ser visto via "docker ps"
- Stopped
    - Pode ser visto via "docker ps -a"

## Layers
Os magens dos containers sao compostas por varios layers, alguns destes podem ser compartilhados entre as imagens instaldadas. Esses layers das imagens são read-only.

Quando rodamos um container a partir de uma imagem, esse container criar um layer adicional que permite a escrita e leitura, um tipo de layer de file system, de forma que cada container tem seu proprio layer de file system, dividindo apenas os layers de imagem (read-only) com os demais containers.

# Comandos importantes
# Docker disk usage
docker system df         # Show docker disk usage, including space reclaimable by pruning

# automatic clean up
docker system prune      # will delete ALL unused data 
                         # (i.e. In order: containers stopped, volumes without containers and images with no containers)
# manual clean up
docker container prune   # Remove all stopped containers
docker volume prune      # Remove all unused volumes
docker image prune       # Remove unused images
docker system prune      # All of the above, in this order: containers, volumes, images


- Baixando uma imagem do Docker Hub
    - Os comandos abaixo baixam o container ubuntu, o executam e param (estado de stop)
    - Sem especificar a versao
        - docker run <image name>
        - ex: docker run ubuntu
    - Especificando a versao desejada
        - docker run <image name>:<versao>
        - ex: docker run ubuntu:14.04
- Listar containers que estão ativos:
    - docker ps
- Listar containers que estão parados/inativos:
    - docker ps -a
- Listar imagens instaladas
    - docker images
- Removendo um container
    - CUIDADO: este comando também remove o layer de file system read/write, ou seja, você vai perder os dados salvos nesse layer. Caso você tenha um volume mapeado dentro do docker, este volume nao eh removida.
    - docker rm <CONTAINER ID>
- Limpar todos os containers inativos
    - docker container prune
- Removendo imagens
    - docker rmi <REPOSITORY>
- Dar um start em um container que esta parado (nao sera aberto o terminal)
    - docker start <CONTAINER ID>
- Parando um ou mais containers
    - -t 0: eh usado para parar o container imediatamente e nao esperar os 10 segundos padrao
    - Dar um stop em um container que esta ativo
        - docker stop -t 0 <CONTAINER ID>
    - Dando stop em todos os catainers ativos
        docker stop -t 0 $(docker ps -q)
- Dar attach em um container rodando e abrindo o modo iterativo
    - docker container exec -it <CONTAINER NAME?ID> /bin/bash
- Rodando imagem no modo iterativo com terminal
- Este comando vai baixar a imagem, caso a mesma nao esteja instalada, e ira abrir o terminal dentro da mesma
    - docker run -it <IMAGE ID>
- Rodando container no modo deatached, ou seja, rodando o container em segundo plano
    - docker run -d <REPOSITORY>
        - ex: docker run -d dockersamples/static-site
- Listando as portas usadas por um container
    - NOTA: 0.0.0.0 = localhost
    - docker ps, olhar coluna PORTS
    - docker port <CONTAINER ID>
- Expondo as portas do container para o host
    - Usando atribuicao de portas do localhost de forma aleatoria
        - docker run -d -P <REPOSITIRY>
            - ex: docker run -d -P dockersamples/static-site
            - Checando a atribuicao
                - Rodar "docker ps" e olhar a coluna PORTS ou
                - ROdar "docker port <REPOSITORY>"
    - Atribuindo as portas desejadas de localhost as portas do container
        - docker run -d -p 12345:<porta do container> <REPOSITORY>
- Passando variabeis de ambiente ao container
    - docker run -e NAME_VARIAVEL="valor" <REPOSITORY>
        - ex: docker run -d -p 12345:80 -e AUTHOR="TESTE LUIS" dockersamples/static-site
        - O comando acima vai setar a variabel AUTHOR e iniciar o docker static-site que utiliza essa variavel para screver a mensagem do site. Para ver basta digitar no navegador: localhost:12345
- Nomeando um container
    - NOTA: REPOSITIRY é a coluna mostrada quando rodamos "docker images"
    - NOTA2: Apos dar um nome, este nome pode ser usado ao inves do ID do container ou o nome aleatório recebido para o cmd stop, por exemplo.
    - docker run --name teste <REPOSITORY>
        - ex: docker run --name teste -d dockersamples/static-site
- Mapeando um volume do host para ser usada no docker
    - Criando um volume de armazenamento no Docker host
        - docker run -v "/var/www" <REPOSITORY>
        - Para saber em que local do docker host a pasta foi criada, rode:
            1. docker inspect <CONTAINER ID/NAME>
            1. Procurar por pela chave "Mounts/Source" no JSON que será exibido
    - Criando um volume em uma pasta especifica do pc host
        - docker run -v "<path do host>:<path a ser mapeado dentro do docker>" <REPOSITORY>
            - ex: docker run -it -v "/home/lbarros:/var/www" ubuntu 
                - Tudo o que for escrito em /var/www dentro do docker será salvo na /home/lbarros e vice e versa
                - Se rodarmos o ls dentro da pasta /var/www, veremos o conteúdo de /home/lbarros
- Rodando um comando dentro do container
    - docker run <comadno> <REPOSITORY>
        - ex: docker run ubuntu echo "123"
            - O container vai iniciar, rodar o comando e entrar em stop. Sera exibida a mensagem 123 na tela
        - ex: docker run ubuntu ls
            - O container vai iniciar, rodar o comando e entrar em stop. Sera exibido o retorno do comando ls que rodou dentro do container
- Rodando um comando dentro de um volume especifico do container (compartilhado com o host)
    - docker run -it -v "<path do dir pc host>:<path desejado container>" -w "<path desejado container>" <REPOSITORY> <COMMAND>
        - ex: docker run -it -v "/home/lbarros:/lbarros_home" -w "/lbarros_home" ubuntu touch teste2.txt
            - este comando vai executar dentro do container o ubuntu, mapear o volume /home/lbarros dentro do container como /lbarros_home, criar o arquivo teste2.txt dentro deste volume e ir para stop. O resultado pode ser observador dentro de /home/lbarros que agora conterá o arquivo teste2.txt
- Listar resdes ativas no Docker
    - docker network ls
- Inspecionando uma rede docker para ver configuracoes e quais containers estao conectados
    - docker inspect <nome da rede>
    - Ex: docker inspect minha-rede
- Dando attach em um container rodando e abrindo o terminal
    - docker exec -it  <IMAGGE NAME/ID> /bin/bash
        - Ex: docker exec -it  segmentationfault_wss3_1 /bin/bash
