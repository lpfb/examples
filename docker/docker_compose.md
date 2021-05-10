# Geral
O docker compose eh usado para automatizar o processo de subir um setup docker contendo diferentes containers e redes do docker.

**Nota:** o docker compose nao eh instalado junto com a engine docker.

# Instalaçao
```sh
sudo curl -L https://github.com/docker/compose/releases/download/1.15.0/docker-compose-`uname -s`-`uname -m` -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
```

# Paramestros basicos docker-compose.yml
Eh neste arquivo que as configuracoes do setup docker devem ser salvas.

**Campos**
- *version*: indica a versao do yml docker que serah usado.
    - Referencia: [link](https://docs.docker.com/compose/compose-file/compose-versioning/)
- *services:* eh nesta secao que as imagens que devem ser buildadas e os containers necessarios devem ser apontados. Exemplo:
```
services:
    nginx:
        build:
            dockerfile: ./docker/nginx.dockerfile
            context: .
        image: douglasq/nginx
        container_name: nginx
        ports:
            - "80:80"
        networks: 
            - production-network
        depends_on:
            - "mongodb"
```
    - *nginx:* e o nome dado ao serviço/container e que e usado por *depends_on*.
    - *build:* secao para informar qual eh a dockerfile que deve ser usada para construir o container.
        - *dockerfile:* informa a dockerfile que deve ser usada para fazer o build e gerar o container.
        - *context:* informa a partir de que diretorio a dockerfile apontada acima deve ser buscada.
    - *image:* informa qual o nome da imagem que sera gerado.
    - *container_name:* nome que serah dado ao container gerado a partir da imagem buidada.
    - *ports:* mapeamento das portas que serao expostas. Pode ser mais de uma. Ex:
        - ports: "<porta do host mapeada>:<porta do container exposta>"
    - *networks:* informa quais as redes docker que estao visiveis para este container. Pode ser mais de uma.
    - *depends_on:* Se este campo esta presente, indica que o container/servico gerado precisa que outro container/servico esteja operando antes que este container suba. Isso instrui o docker compose a subir o container/servico apontado aqui antes de iniciar este container.
- *networks*: cria redes docker para conectar diferentes containers. As redes criadas aqui podem ser apontadas em services/<image name>/networks.
Ex:
    ```
    networks: 
        <network name>:
            driver: <tipod de driver>
    Ex:
        networks: 
            production-network:
                driver: bridge
    ```
    - Esta secao pode ter mais de uma rede.
    - *network name:* informa o nome da rede.
        - *driver:* tipo do driver. O mais comum e utilizado eh o bridge

## Exemplo de docker-compose.yml
