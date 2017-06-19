#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define _UNICODE

#include "src/red_black_tree.h"
#include "src/leitura.h"

int main()
{
    char* local;
    local = setlocale(LC_ALL, "portuguese");

    rb_tree_t* arvore;

    arvore = leitura_arquivo("dic_one_line.csv");
    exportar_arvore_dot("tree.dot", arvore);
    system("pause");

}
