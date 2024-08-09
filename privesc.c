#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_header(const char *header) {
    printf("\n[*] %s\n", header);
}

void print_separator() {
    printf("-------------------------------------------------------------\n");
}

void run_command(const char *command) {
    int result = system(command);
    if (result != 0) {
        printf("[!] Comando falhou: %s\n", command);
    }
}

void check_command(const char *command) {
    char check[256];
    snprintf(check, sizeof(check), "command -v %s >/dev/null 2>&1", command);
    if (system(check) != 0) {
        printf("[!] %s não está instalado. Abortando...\n", command);
        exit(1);
    }
}

int main() {
    // Verificações de comandos necessários
    check_command("curl");
    check_command("grep");
    check_command("lsb_release");
    check_command("uname");
    check_command("hostnamectl");
    check_command("uptime");
    check_command("ifconfig");
    check_command("netstat");
    check_command("ss");
    check_command("ps");
    check_command("find");
    check_command("cat");
    check_command("ls");
    check_command("searchsploit");

    // Execução da enumeração
    print_header("PrivEsc - Desenvolvido por Fatality");
    print_separator();

    printf("[*] Iniciando Enumeração...\n");
    print_separator();

    printf("[*] Informações Gerais do Sistema:\n");
    run_command("lsb_release -a");
    run_command("uname -a");
    run_command("hostnamectl");
    run_command("uptime");

    print_separator();

    printf("[*] Informações de Rede:\n");
    run_command("ifconfig -a");
    run_command("netstat -antup");
    run_command("ss -ltnp");

    print_separator();

    printf("[*] Processos em Execução:\n");
    run_command("ps aux");

    print_separator();

    printf("[*] Verificando Permissões:\n");
    run_command("ls -al /etc/passwd /etc/group /etc/hosts /etc/hostname /etc/sudoers");

    print_separator();

    printf("[*] Procurando por Binários Suid:\n");
    run_command("find / -perm -4000 -type f -exec ls -ld {} \\; 2>/dev/null");

    print_separator();

    printf("[*] Verificando Arquivos e Diretórios com Permissões Graváveis:\n");
    run_command("find / -writable -type d 2>/dev/null | grep -v 'Permission denied'");
    run_command("find / -perm -2 -type f 2>/dev/null | grep -v 'Permission denied'");

    print_separator();

    printf("[*] Verificando Binários com Permissões Graváveis:\n");
    run_command("find / -perm -o w -type f 2>/dev/null | grep -v 'Permission denied'");

    print_separator();

    printf("[*] Verificando Versão do Kernel:\n");
    run_command("uname -r");

    print_separator();

    printf("[*] Informações de Usuários:\n");
    run_command("cat /etc/passwd");
    run_command("cat /etc/sudoers");

    print_separator();

    printf("[*] Crontabs:\n");
    run_command("cat /etc/crontab");
    run_command("ls -al /etc/cron*");

    print_separator();

    printf("[*] Arquivos Configurados no Apache:\n");
    run_command("ls -al /etc/apache2");
    run_command("ls -al /etc/apache2/sites-enabled");

    print_separator();

    printf("[*] Arquivos Configurados no MySQL:\n");
    run_command("ls -al /etc/mysql");
    run_command("ls -al /etc/mysql/my.cnf");

    print_separator();

    printf("[*] Arquivos Configurados no NFS:\n");
    run_command("cat /etc/exports");

    print_separator();

    printf("[*] Arquivos de Log Suspeitos:\n");
    run_command("ls -al /var/log/*.log");
    run_command("ls -al /var/log/apache2/*.log");
    run_command("ls -al /var/log/mysql/*.log");
    run_command("ls -al /var/log/nginx/*.log");

    print_separator();

    printf("[*] Arquivos de Configuração no /var/www:\n");
    run_command("ls -al /var/www/*");

    print_separator();

    // Função adicional para ler arquivos sensíveis
    print_header("Lendo Arquivos Sensíveis");
    print_separator();
    printf("[*] Tentando ler /etc/passwd:\n");
    run_command("cat /etc/passwd");

    printf("[*] Tentando ler /etc/shadow:\n");
    run_command("cat /etc/shadow");

    print_separator();

    // Função adicional para pesquisar exploits no Exploit-DB
    print_header("Pesquisando por Exploits no Exploit-DB");
    print_separator();
    char keyword[256];
    printf("[?] Digite uma palavra-chave para buscar: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;  // Remove newline

    char search_command[512];
    snprintf(search_command, sizeof(search_command), "searchsploit %s", keyword);
    run_command(search_command);

    print_separator();

    printf("[*] Finalizando Enumeração...\n");
    print_separator();

    printf("[*] Enumeração Concluída. Verifique os resultados acima.\n");
    print_separator();

    return 0;
}
