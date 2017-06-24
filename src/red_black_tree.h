#ifndef RED_BLACK_TREE_H_INCLUDED
#define RED_BLACK_TREE_H_INCLUDED

typedef struct rb_tree rb_tree_t;

typedef struct rb_node rb_node_t;

typedef enum cor {PRETO, VERMELHO} cor_t;

rb_tree_t* cria_arvore(void);

rb_node_t* cria_no_arvore(rb_tree_t* arvore, void* dado);

rb_node_t* obtem_raiz (rb_tree_t* arvore);

rb_node_t* obtem_sentinela (rb_tree_t* arvore);

void inserir_arvore(rb_tree_t* arvore, void* dado);

void exportar_arvore_dot(char* filename, rb_tree_t* arvore);

#endif // RED_BLACK_TREE_H_INCLUDED
