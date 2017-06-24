#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leitura.h"
#include "palavra.h"

#define WINDOWS


static void clear_screen(void){
    #ifdef WINDOWS
    system("cls");
    #else
    system("clear");
    #endif
}

void interface_intro (void){
    clear_screen();

    printf("\tWORDNATOR\n\n\n");
    printf("Pressione enter para continuar...\n");
    fflush(stdin);
    getchar();
}

void interface_obter_chave (char *chave){
    clear_screen();

    printf("Insira a palavra que deseja procurar: ");

    fflush(stdin);
    gets(chave);
}

void interface_imprimir_palavra (palavra_t *palavra){
    char *chave, *significado;

    clear_screen();

    chave = obtem_chave(palavra);
    significado = obtem_significado(palavra);

    printf("PALAVRA: %s\n\nSIGNIFICADO: %s\n\n", chave, significado);

    printf("Pressione enter para pesquisar outra palavra...\n");
    fflush(stdin);
    getchar();
}

void interface_imprimir_nao_encontrado (void){
    clear_screen();

    printf("Palavra não encontrada.\n\n");

    printf("Pressione enter para pesquisar outra palavra...\n");
    fflush(stdin);
    getchar();
}
