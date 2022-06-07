# Managing Bluetooth connections on terminal
1. Identify your computer bluetooth
	```sh
	hcitool dev
	```
	* Outpu example:
	>Devices:
	>hci0	E8:D0:FC:C8:2E:54

1. Scan available devices
	```sh
	hcitool -i hci0 scan
	```
1. Trust the discovered device
	```sh
	bluetoothctl
	```
	* This will open an terminal with something like this:
	> [bluetooth]#

	* So trust the device using:
	> [bluetooth]# trust FC:XX:XX:XX:XX:FE

	* Expected output
	> [CHG] Device FC:XX:XX:XX:XX:FE Trusted: yes

1. Connect to the device
	```sh
	bluetoothctl
	```
	* This will open an terminal with something like this:
	> [bluetooth]#

	* So connect using
	> [bluetooth]# connect FC:XX:XX:XX:XX:FE

	* Expected output
	> Attempting to connect to FC:XX:XX:XX:XX:FE
	> Connection successful

# Listing largest folders/files including the sub-directories
```sh
du -Sh | sort -rh | head -5
```
# Mounting remote directories over an SSH connection
SSHFS (SSH Filesystem) is a filesystem client based on FUSE for mounting remote directories over an SSH connection. SSHFS is using the SFTP protocol, which is a subsystem of SSH and it is enabled by default on most SSH servers.

As a result, you will have a mounted partition on the host side.

Reference: [link](https://linuxize.com/post/how-to-use-sshfs-to-mount-remote-directories-over-ssh/)

## Install
```sh
sudo apt install sshfs
```
## Configuration/Use
1. Create a folder (server side/host) in order to mount the remote file System
1. Mount File System
```sh
sshfs <user>@<Cliente IP>:<target client folder> <host mount folder>
```
    - Exemple:
```sh
sshfs linuxize@192.168.121.121:/home/linuxize /home/linuxize/linuxizeremote
```
1. Insert password and now you will be able to access te content of maped folder as a mounted partition.

# Managing install librarys (apititude)
To do this one can use apititude

## Install
sudo apt install apititude

# C language library configurations
You can use a **.a** (static) or **.o** file as a library. The file must follow the pattern lib~.so, at the end you can use so.x.y.z, where x, y and z are library versions.

## Listing Linux library paths
```sh
ldconfig -v
```

## Main library paths
- /usr/lib
- /usr/lib/x86_64-linux-gnu
- /usr/local/lib
- /lib/x86_64-linux-gnu

## Setting Library environment variable
```sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/your/.a or .o/library
```
# Symbolic Link
```sh
ln -s [target file] [Symbolic filename]
```
# Find
- Using find to exclude more than one directory names from the search
```sh
find . -type d \( -path ./node_modules -o -path ./out -o -name ./dist \) -prune -false -o -name '*.md'
```
    - Exclusion methods
        - -path ./dir_name: used for the current directory level
        - -name dir_name: used to exclude name in all levels searched
    - -name pattern: used to specify the pattern/file to be searched
    - '-o' is used as an or expression to add mor dirs

- Using find to exclude a directory name from the search
```sh
find . -path ./node_modules -prune -false -o -name '*.md'
```
    - Exclusion methods
        - -path ./dir_name: used for the current directory level
        - -name dir_name: used to exclude name in all levels searched
    - -name pattern: used to specify the pattern/file to be searched

# Journal

## Changing jornoul configurations
Some references:
- [Journal clean-up](https://www.linuxuprising.com/2019/10/how-to-clean-up-systemd-journal-logs.html)

### Changing journal maxsize
1. Openning journal config file
```sh
vim /etc/systemd/journald.conf
```

1. Uncomment *SystemMaxUse* and configure it with the desired maxsize
```
SystemMaxUse=100M
```

## Checking journal disk usage
```sh
journalctl --disk-usage
```

## Removing journal files
1. Asking the journal daemon to rotate journal files. Journal file rotation has the effect that all currently active journal files are marked as archived and renamed, so that they are never written to in future. New (empty) journal files are then created in their place
```sh
sudo journalctl --rotate
```

1. Making all journal files contain no data older than 1 second. This will free your system disk.
```sh
sudo journalctl --vacuum-time=1s
```

# Creating linux socat
This can be used to forward TCP communication from one pc/board to another one.
```sh
sudo socat TCP4-LISTEN:<host port>,fork TCP:<target ip>:<target port>
```
Where:
- host port: it is the port of the host that you will desire to open to foward the comunication to the target
- targe ip: IP of the target board/pc
- target port: Port of the target pc/board. Note: port 22 must be used in case of ssh communication.

Testing socat redirection
```sh
ssh <user>@<host ip> -p <host port>
```
Where:
- host ip: Host ip who foward the below port
- host port: it is the port of the host fowarded using previous command

NOTE: When the socat is closed by the other part, socat close conection and needs to be reopen. To resolve this:
```sh
#!/bin/bash

while :; do
    echo "Reopenning socat"
    socat TCP4-LISTEN:12345,fork TCP:192.168.7.2:22
    echo "Socat closed"
    sleep 1
done
```

# Sed + Grep
grep e trocar substituir as mesmas strings encontradas com sed, substituir string em todos os arquivos:
procura='XY'; substituicao='UVA'; grep -rl "$procura" . | xargs sed -i "s/$procura/$substituicao/g"

# Grep
Opções interessantes do grep:
    - -i: ignora se a letra é maiúscula ou minúscula
    - -n: informa a linha do arquivo onde foi encontrado o padrao buscado
    - -r: busca nos diretórios de forma recursiva
    - -l: lista apenas os arquivos que coincidem e não o texto encontrado nesses arquivos
    - --exclude-dir: exlui um ou mais diretórios da busca
    - -I: Exclui arquivos binarios da busca

## Excluindo alguns diretórios da busca e listando apenas os arquivos sem printar conteúdo
```sh
 grep -irl --exclude-dir={dir1,dir2,dir3} "TEXTO A SER PROCURADO"
```
- Onde:
    - -i: ignora se a letra é maiúscula ou minúscula
    - -r: busca nos diretórios de forma recursiva
    - -l: lista apenas os arquivos que coincidem e não o texto encontrado nesses arquivos
    - --exclude-dir: exlui um ou mais diretórios da busca

## Excluindo os arquivos binários da busca
```sh
grep -I "TEXTO A SER PROCURADO"
```
- Onde:
    - -I: Não busca co conteúdo do texto(string) em arquivos binários

# SSH
.

## Running a command into another linux PC
- Install requirements
sshpass precisa ser instalado
```sh
sudo apt install sshpass
```
- Running command
```sh
sshpass -p <password of remote PC> ssh <remote user>@<remote pc IP> << EOF
    cd
    touch sshpass_teste.txt
    cho "Testado com sucesso" > sshpass_teste.txt
EOF
```

## Exchangin ssh keys to password-less login
- On the PC that you want to use to acess another, run this:
```sh
cat ~/.ssh/id_rsa.pub | ssh <user>@<IP board> 'cat >> .ssh/authorized_keys'
```
Where:
- user: board user
- IP board: board password

# Generating self extractive 7zip file for Windows with password

1. Coping file 7z.sfx or 7zCon.sfx from a windows machine with the desired architecture (32 or 64 bits) to your linux machine
    - Usually this files are at *C:\Program Files\7-Zip* folder
    - 7z.sfx: GUI version. When any action from user is necessary, a GUI will open.
    - 7zCon.sfx: command line version. When any action from user is necessary, a dos prompt will open.
1. Rename file and move to /usr/lib/p7zip/
    - Renaming suggestions 7z.sfx to 7zWin<32 or 64>.sfx
    - Renaming suggestions 7zCon.sfx to 7zConWin<32 or 64>.sfx
1. Generating auto extract file
```sh
7za a -sfx7z<or Con>Win<32 or 64>.sfx -p<password> <resulting file name>.exe <file to be compacted>
```
1. On Windows PC
    1. Move the <resulting file name>.exe to the windows PC
    1. Double click on it
    1. Insert the correct password and the content will be extracted

# Alterando a resolução e o frame rate das interfaces de vídeo
- Listando interfaces de vídeo conectadas e suas respectivas resoluções
```sh
xrandr
```
- Alterando a resolução e o frame rate de uma determinada interface de vídeo
```sh
xrandr --output HDMI-1 --mode 1920x1080 -r 60
```
    - Troque 1920x1080 pela resolução desejada, 60 pelo frame rate desejado e HDMI-1 pela interface de vídeo desejada

# Empty trash in terminal
```sh
rm -rf ~/.local/share/Trash/*
```

# Supending/hibernating PC
**Referência:** [Link](https://www.cyberciti.biz/faq/linux-command-to-suspend-hibernate-laptop-netbook-pc/)
- Suspending PC (using RAM)
```sh
systemctl suspend
```
# Instalação de pacotes Ubuntu
**Referência:** [link](https://www.vivaolinux.com.br/dica/Tutorial-basico-do-APTGET)
- Para atualizar a lista local de pacotes
```sh
sudo apt-get update
```
- Para instalar todas as atualizações disponíveis
```sh
sudo apt-get upgrade
```
- Para remover um pacote
```sh
sudo apt-get remove <nomedopacote>
```
- Para remover completamente um pacote e arquivos ou registros de configuração
```sh
sudo apt-get --purge remove <nomedopacote>
```
- Removendo um pacote e suas dependências:
```sh
sudo apt-get remove --auto-remove <package name>
```
- Limpando o apt install
```sh
sudo apt-get clean && sudo apt-get update
```

# Logout from terminal
```sh
sudo pkill -u username
```
# Varrendo IP's da rede local e checando dispositivos conectados
Exemplo para as configurações de rede a seguir:
**IP PC:** 192.168.0.x
**netmask:** 255.255.255.0
```sh
sudo nmap -sn 192.168.0.0/24
```

# Criando pasta e arquivos temporários, ou seja, desaparecem quando reinicia o computador
.

## Diretório
Cria uma pasta temporária e informa em STD out o nome da pasta criada. É preciso passar pelo menos três letras 'X' maísculas depois do ponto após o nome do arquivo, esses 'x' serão usados para gerar um 'ID' pseudo-aleatório para evitar problemas de conflito de nome.
```sh
mktemp -d tmp.XXX
```
- Obs: O nome da pasta não precisa ser obrigatóriamente tmp.
- Obs2: Se o nome do arquivo for omitido, o sistema vai escolher automaticamente

## Arquivo
Cria um arquivo temporário e informa em STD out o nome do arquivo criado. É preciso passar pelo menos três letras 'X' maísculas depois do ponto após o nome do arquivo, esses 'X' serão usados para gerar um 'ID' pseudo-aleatório para evitar problemas de conflito de nome.
```sh
mktemp tmp.XXX
```
- Obs: O nome da pasta não precisa ser obrigatóriamente tmp.

# Configurando Ubuntu para usar Workspaces com app's separados
Rodar a linha de comando a seguir no terminal
```sh
gsettings set org.gnome.shell.extensions.dash-to-dock isolate-workspaces true
```

# Criando um novo usuario (ex: tc.lbarros)
```sh
sudo adduser tc.lbarros --force-badname #Devido ao ponto no meio do nome eh preciso usar o force-badname
sudo usermod -aG sudo tc.lbarros #Adiciona o usuario ao gruipo root
```
# Controlando as configurações de som do PC
O app PulsAudioControl ajuda a controlar as entradas e saídas de som do PC e ter um controle melhor do nivel de som de cada aplicação.
Obs: O Spotify não estava reproduzindo som uma vez e só com este app foi possível checar que ele estava mutado e desmuta-lo.

## Instalação
```sh
sudo apt install pavucontrol
```
## Uso
Basta digitar o comando abaixo que uma GUI será aberta. Também é possível achar o Pulse Audio na seção de app's linux.
```sh
pavucontrol
```
# Compactando arquivos TAR.GZ
Commando para compactar
```sh
tar -czf <nome_a_ser_gerado>.tar.gz <arquivo_ou_pasta_alvo>/
```
Comando para descompactar
```sh
tar -xzf <nome_arquivo>.tar.gz
```

# Monitoring network traffic
## Using iftop

### Instalando
```sh
sudo apt install iftop
```

### Filtrando por interface e mostrando as portas
```sh
sudo iftop -P -i eth0
```
# Changing hostname
```sh
sudo vim /etc/hostname
```

# Backgound and foreground process
## Listing background process
```sh
jobs
```

## Stopping foreground process
```sh
CTRL+z
```

## Starting stopped foreground process number 'n' in background
```sh
bg %n
```

## Bringging background process number 'n' to foreground
```sh
fg %n
```
