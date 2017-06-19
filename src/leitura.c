#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "leitura.h"
#include "palavra.h"
#include "red_black_tree.h"

#define CHAVE_SIZE       50
#define SIGNIFICADO_SIZE 300


rb_tree_t* leitura_arquivo (char* nome_arq){
    rb_tree_t* arvore = cria_arvore();

    wchar_t chave[CHAVE_SIZE];
    wchar_t significado[SIGNIFICADO_SIZE];
    int  i = 0;

    FILE* fp = fopen (nome_arq, "r");
    if(!fp){perror("leitura_arquivo: fp"); exit(EXIT_FAILURE);};

    char teste[] = "Bananão";

    while (1){
        fwscanf (fp, L"\"%[^\"]\",\"%[^\"]\"", chave, significado);
        fgetc (fp);

        palavra_t* palavra = cria_palavra(chave, significado);

        inserir_arvore(arvore, palavra);

        printf("chave: .%s. significado: .%s.\n\n", chave, significado);
        if (feof(fp)){
            break;
        }
    }
    return arvore;
}

