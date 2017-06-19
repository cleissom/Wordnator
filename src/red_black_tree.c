#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "red_black_tree.h"

struct rb_tree {
    rb_node_t* raiz;
    rb_node_t* sentinela;

};

struct rb_node {
    void*       dado;
    rb_node_t*  esquerda;
    rb_node_t*  direita;
    rb_node_t*  pai;
    cor_t      cor;
};

rb_node_t* cria_no_sentinela(void){
    rb_node_t* node = malloc(sizeof(rb_node_t));

    if(!node){perror("cria_no_sentinela"); exit(EXIT_FAILURE);};

    node->dado     = 0;
    node->esquerda = NULL;
    node->direita  = NULL;
    node->pai      = NULL;
    node->cor      = PRETO;

    return node;
}

rb_tree_t* cria_arvore(void){
    rb_tree_t* arvore = malloc(sizeof(rb_tree_t));
    if(!arvore){perror("cria_arvore"); exit(EXIT_FAILURE);};

    rb_node_t* sentinela = cria_no_sentinela();

    arvore->sentinela = sentinela;
    arvore->raiz = sentinela;

    return arvore;
}

rb_node_t* cria_no_arvore(rb_tree_t* arvore, void* dado){
    rb_node_t* node = malloc(sizeof(rb_node_t));

    if(!arvore){perror("cria_no_arvore: arvore"); exit(EXIT_FAILURE);};
    if(!node){perror("cria_no_arvore: node"); exit(EXIT_FAILURE);};

    node->dado     = dado;
    node->esquerda = arvore->sentinela;
    node->direita  = arvore->sentinela;
    node->pai      = arvore->sentinela;
    node->cor      = VERMELHO;

    return node;
}

rb_node_t* get_avo(rb_node_t* node){
    if ((node) && (node->pai)){
        return (node->pai)->pai;
    }
    else
        return NULL;
}

rb_node_t* get_tio(rb_node_t* node){
    rb_node_t* avo = get_avo(node);
    if (!avo){
        return NULL;
    } else if (node->pai == avo->esquerda){
        return avo->direita;
    }
    else
        return avo->esquerda;
}

void rotacao_esquerda (rb_tree_t* arvore, rb_node_t* node){
    rb_node_t* no_temp = NULL;
    no_temp = node->direita;
    node->direita = no_temp->esquerda;

    if(no_temp->esquerda != arvore->sentinela){
        no_temp->esquerda->pai = node;
    }
    no_temp->pai = node->pai;

    if(node->pai == arvore->sentinela)
        arvore->raiz = no_temp;
    else if(node == node->pai->esquerda)
        node->pai->esquerda = no_temp;
    else
        node->pai->direita = no_temp;

    no_temp->esquerda = node;
    node->pai         = no_temp;
}

void rotacao_direita (rb_tree_t* arvore, rb_node_t* node){
    rb_node_t* no_temp = NULL;
    no_temp = node->esquerda;
    node->esquerda = no_temp->direita;

    if(no_temp->direita != arvore->sentinela){
        no_temp->direita->pai = node;
    }
    no_temp->pai = node->pai;

    if(node->pai == arvore->sentinela)
        arvore->raiz = no_temp;
    else if(node == node->pai->esquerda)
        node->pai->esquerda = no_temp;
    else
        node->pai->direita = no_temp;

    no_temp->direita  = node;
    node->pai         = no_temp;
}

void inserir_no_arvore(rb_tree_t* arvore, rb_node_t* node){
    rb_node_t *no_anterior = arvore->sentinela;
    rb_node_t *no_temp = arvore->raiz;

    while(no_temp != arvore->sentinela){
        no_anterior = no_temp;
        if(compara_no(node,no_temp) < 0)
            no_temp = no_temp->esquerda;
        else
            no_temp = no_temp->direita;
    }

    node->pai = no_anterior;

    if(no_anterior == arvore->sentinela)
        arvore->raiz = node;
    else if(compara_no(node,no_anterior) < 0)
        no_anterior->esquerda = node;
    else
        no_anterior->direita = node;

    node->esquerda = arvore->sentinela;
    node->direita  = arvore->sentinela;
    node->cor      = VERMELHO;

    correcao_arvore(arvore,node);
}

void inserir_arvore(rb_tree_t* arvore, void* dado){
    if(!arvore){perror("inserir_arvore: arvore"); exit(EXIT_FAILURE);};
    if(!dado){perror("inserir_arvore: dado"); exit(EXIT_FAILURE);};

    rb_node_t* node = cria_no_arvore(arvore, dado);
    if(!node){perror("inserir_arvore: node"); exit(EXIT_FAILURE);};

    inserir_no_arvore(arvore,node);
}

int compara_no(rb_node_t* node_1, rb_node_t* node_2){
    int ret;

    if(!node_1 || !node_2) {return -1;};

    ret = strcmp(obtem_chave(node_1->dado),obtem_chave(node_2->dado));
    return ret;
}

void correcao_arvore(rb_tree_t* arvore, rb_node_t* node){
    rb_node_t* no_temp = NULL;

    while(node->pai->cor == VERMELHO){
        if(node->pai == node->pai->pai->esquerda){
            no_temp = node->pai->pai->direita;
            if(no_temp->cor == VERMELHO){
                node->pai->cor = PRETO;
                no_temp->cor   = PRETO;
                node = get_avo(node);
                node->cor = VERMELHO;
            }
            else{
                if(node == node->pai->direita){
                    node = node->pai;
                    rotacao_esquerda(arvore,node);
                }
                node->pai->cor = PRETO;
                node->pai->pai->cor = VERMELHO;
                rotacao_direita(arvore,get_avo(node));
            }
        }
        else{
            no_temp = node->pai->pai->esquerda;
            if(no_temp->cor == VERMELHO){
                node->pai->cor = PRETO;
                no_temp->cor   = PRETO;
                node = get_avo(node);
                node->cor = VERMELHO;
            }
            else{
                if(node == node->pai->esquerda){
                    node = node->pai;
                    rotacao_direita(arvore,node);
                }
                node->pai->cor = PRETO;
                node->pai->pai->cor = VERMELHO;
                rotacao_esquerda(arvore,get_avo(node));
            }
        }
    }
    arvore->raiz->cor = PRETO;
}

int print_dot(FILE* file, rb_tree_t* arvore, rb_node_t* node, int number)
{
    int next_number = number;

    if(node->cor == VERMELHO)
        fprintf(file,"\tnode_%d[label=\"%s\" fontcolor=\"white\" style=\"filled\" fillcolor=\"red3\"];\n", number, obtem_chave(node->dado));
    else
        fprintf(file,"\tnode_%d[label=\"%s\" fontcolor=\"white\" style=\"filled\" fillcolor=\"black\"];\n", number, obtem_chave(node->dado));

    if(node->esquerda != arvore->sentinela){
        fprintf(file,"\tnode_%d -> node_%d;\n", number, next_number+1);
        next_number = print_dot(file, arvore, node->esquerda, next_number+1);
    }

    if(node->direita != arvore->sentinela){
        fprintf(file,"\tnode_%d -> node_%d;\n", number, next_number+1);
        next_number = print_dot(file, arvore, node->direita, next_number+1);
    }

    return next_number++;
}

void exportar_arvore_dot(const char* filename, rb_tree_t* arvore)
{
    if(!filename || !arvore){perror("leitura_arquivo: fp"); exit(EXIT_FAILURE);};

	FILE* file = fopen(filename,"w");

    if(!file){perror("leitura_arquivo: file"); exit(EXIT_FAILURE);};

	fprintf(file, "digraph {\n");

    print_dot(file, arvore, arvore->raiz, 0);

	fprintf(file, "}\n");
	fclose(file);
}
