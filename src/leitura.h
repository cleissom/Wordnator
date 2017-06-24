#ifndef LEITURA_H_INCLUDED
#define LEITURA_H_INCLUDED

#include "red_black_tree.h"
#include "palavra.h"

#define CHAVE_SIZE       50
#define SIGNIFICADO_SIZE 6200

rb_tree_t* leitura_arquivo (char* nome_arq);

palavra_t* procura_palavra (rb_tree_t* arvore, char* chave);

#endif // LEITURA_H_INCLUDED
