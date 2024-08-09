# PrivEsc - Ferramenta de Enumeração de Escalação de Privilégios
![bandicam 2024-08-09 03-17-05-316](https://github.com/user-attachments/assets/32a1a65b-167e-43c0-9c1f-90267045e348)

PrivEsc é uma ferramenta escrita em C para auxiliar na enumeração de informações do sistema com foco em identificar potenciais vetores de escalação de privilégios. Ela automatiza a coleta de dados essenciais sobre o sistema, rede, permissões de arquivos, processos em execução, entre outros, que podem ser úteis durante um processo de pentest ou auditoria de segurança.
## Funcionalidades

- Informações do Sistema: Coleta detalhes sobre a distribuição, kernel, hostname, e tempo de atividade.
- Informações de Rede: Lista interfaces de rede, conexões ativas e portas abertas.
- Processos em Execução: Lista todos os processos em execução no sistema.
- Permissões de Arquivos: Verifica permissões de arquivos críticos e binários com o bit SUID setado.
- Configurações do Apache, MySQL e NFS: Coleta informações sobre as configurações de serviços populares.
- Arquivos Sensíveis: Tenta acessar arquivos como /etc/passwd e /etc/shadow.
- Pesquisa de Exploits: Realiza buscas no Exploit-DB para possíveis vulnerabilidades utilizando palavras-chave.
## Como Baixar, Compilar e Executar
Requisitos:
- Sistema Operacional: Linux
- Compilador GCC: sudo apt-get install gcc
- Permissões de superusuário (sudo)

Passos para Compilar e Executar:
```bash
git clone https://github.com/0xFatality/PrivEsc
cd PrivEsc
gcc privesc.c -o privesc
./privesc
```
## Aviso Legal
Este software foi desenvolvido para fins educacionais e de pesquisa. O uso inadequado desta ferramenta para comprometer sistemas sem a devida autorização é ilegal e contra os princípios éticos. O autor não se responsabiliza por qualquer dano causado pelo uso indevido desta ferramenta.

![bff2ea9e2d174db26e00097445bd310524609b06_00](https://github.com/user-attachments/assets/d1f01aaf-9f3f-4520-b913-d19448446ac3)


