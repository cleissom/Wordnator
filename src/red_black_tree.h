#ifndef RED_BLACK_TREE_H_INCLUDED
#define RED_BLACK_TREE_H_INCLUDED

typedef struct rb_tree rb_tree_t;

typedef struct rb_node rb_node_t;

typedef enum cor {PRETO, VERMELHO} cor_t;

rb_tree_t* cria_arvore(void);

rb_node_t* cria_no_arvore(void* dado);

rb_node_t* get_avo(rb_node_t* node);

rb_node_t* get_tio(rb_node_t* node);

void rotacao_esquerda (rb_tree_t* arvore, rb_node_t* node);

void rotacao_direita (rb_tree_t* arvore, rb_node_t* node);

void inserir_no_arvore(rb_tree_t* arvore, rb_node_t* node);

int compara_no(rb_node_t* node_1, rb_node_t* node_2);

void correcao_arvore(rb_tree_t* arvore, rb_node_t* node);

#endif // RED_BLACK_TREE_H_INCLUDED
