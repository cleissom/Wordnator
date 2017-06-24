#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leitura.h"
#include "palavra.h"
#include "red_black_tree.h"

//#define PRINT_TREE

rb_tree_t* leitura_arquivo (char* nome_arq){
    rb_tree_t* arvore = cria_arvore();

    char chave[CHAVE_SIZE];
    char significado[SIGNIFICADO_SIZE];

    #ifdef PRINT_TREE
    int i = 0;
    char buffer [10];
    #endif // PRINT_TREE

    FILE* fp = fopen (nome_arq, "r");
    if(!fp){perror("leitura_arquivo:"); exit(EXIT_FAILURE);};

    while (1){
        fscanf (fp, "\"%[^\"]\",\"%[^\"]\"", chave, significado);
        fgetc (fp);

        palavra_t* palavra = cria_palavra(chave, significado);

        inserir_arvore(arvore, palavra);

        #ifdef PRINT_TREE
        sprintf(buffer,"%d.dot",i++);
        exportar_arvore_dot(buffer, arvore);
        #endif // PRINT_TREE

//        printf("chave: .%s. significado: .%s.\n\n", chave, significado);

        if (feof(fp)){ break; }
    }

    return arvore;
}

palavra_t* procura_palavra (rb_tree_t* arvore, char* chave){
    if(!arvore){perror("procura_palavra: arvore"); exit(EXIT_FAILURE);};
    if(!chave) {perror("leitura_arquivo: chave");  exit(EXIT_FAILURE);};

    rb_node_t* percursor       = NULL;
    rb_node_t* sentinela       = NULL;
    palavra_t* palavra         = NULL;
    char*      chave_percursor = NULL;

    percursor = obtem_raiz(arvore);
    sentinela = obtem_sentinela(arvore);

    while (percursor != sentinela){
        palavra         = obtem_dado (percursor);
        chave_percursor = obtem_chave (palavra);
        if (strcmp (chave, chave_percursor) == 0)
            return palavra;
        else if (strcmp(chave, chave_percursor) < 0)
            percursor = obtem_no_esquerda(percursor);
        else
            percursor = obtem_no_direita(percursor);
    }
    return NULL;
}
