#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "src/red_black_tree.h"
#include "src/leitura.h"
#include "src/palavra.h"
#include "src/interface.h"

int main()
{
    setlocale(LC_ALL, "portuguese");

    rb_tree_t* arvore;
    palavra_t* palavra;
    char chave[CHAVE_SIZE];

    interface_intro();

    arvore = leitura_arquivo("src/dic_one_line.csv");

    while(1){
        interface_obter_chave(chave);

        palavra = procura_palavra(arvore, chave);

        if(!palavra)
            interface_imprimir_nao_encontrado();
        else
            interface_imprimir_palavra(palavra);
    }

    return 0;
}
