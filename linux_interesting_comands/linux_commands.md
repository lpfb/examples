# Listing largest folders/files including the sub-directories
```sh
du -Sh | sort -rh | head -5
```

# C language library configurations
You can use a '.a' (static) or '.o' file as a library. The file must follow the pattern lib~.so, at the end you can use so.x.y.z, where x, y and z are library versions.

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
sudo socat TCP-LISTEN:<host port>,fork TCP:<target ip>:<target port>
```
Where:
- host port: it is the port of the host that you will desire to open to foward the comunication to the target
- targe ip: IP of the target board/pc
- target port: Port of the target pc/board. Note: port 22 must be used in case of ssh communication.

# Grep
Opções interessantes do grep:
    - -i: ignora se a letra é maiúscula ou minúscula
    - -r: busca nos diretórios de forma recursiva
    - -l: lista apenas os arquivos que coincidem e não o texto encontrado nesses arquivos
    - --exclude-dir: exlui um ou mais diretórios da busca
    - -I: Não busca co conteúdo do texto(string) em arquivos binários

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
sshpass -p <password of remote PC> ssh <remove user>@<remote pc ip> << EOF
    cd
    touch sshpass_teste.txt
    cho "Testado com sucesso" > sshpass_teste.txt
EOF
```

# Generating self extractive 7zip file for Windows with password

1. Coping file 7z.sfx or 7zCon.sfx from a windows machine with the desired architecture (32 or 64 bits) to your linux machine
    - Usually this files are at *C:\Program Files\7-Zip* folder 
    - 7z.sfx: GUI version. When any action from user is necessary, a GUI will open.
    - 7zCon.sfx: command line version. When any action from user is necessary, a dos will open.
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
- Alterando a resolução de uma determinada interface de vídeo
```sh
xrandr --output HDMI-1 --mode 1920x1080 -r 60
```
    - Torque 1920x1080 pela resolução desejada, 60 pelo frame rate desejado e HDMI-1 pela interface de vídeo desejada
 
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
- Limpando o apt install:
```sh
sudo apt-get clean && sudo apt-get update
```
- Removendo um pacote e suas dependências:
```sh
sudo apt-get remove --auto-remove <package name>
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

## Arquivo
Cria um arquivo temporário e informa em STD out o nome do arquivo criado. É preciso passar pelo menos três letras 'X' maísculas depois do ponto após o nome do arquivo, esses 'x' serão usados para gerar um 'ID' pseudo-aleatório para evitar problemas de conflito de nome.
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
