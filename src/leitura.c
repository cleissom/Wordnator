#include <stdio.h>
#include <stdlib.h>
#

#include <string.h>
#include "leitura.h"
#include "palavra.h"

rb_tree_t* leitura_arquivo (char* nome_arq){

    char chave [50];
    char significado [2500];
    int  i = 0;

    FILE * fp = fopen (nome_arq, "r");
    if (fp == NULL){
        perror (nome_arq);
        exit(EXIT_FAILURE);
    }

    while (i<300){
        fscanf (fp, "\"%50[^\"]",chave);
        fgetc (fp);
        fgetc (fp);
        fscanf (fp, "\"%1100[^\"]",significado);
        fgetc (fp);
        fgetc (fp);

        printf("chave: .%s. significado: .%s.\n\n", chave, significado);
        if (feof(fp)){
            break;
        }
        i++;

    }
    printf ("%d", i);


}
