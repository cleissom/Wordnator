#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "red_black_tree.h"

struct rb_tree {
    rb_node_t* raiz;
};

struct rb_node {
    void*       dado;
    rb_node_t*  esquerda;
    rb_node_t*  direita;
    rb_node_t*  pai;
    cor_t      cor;
};

rb_tree_t* cria_arvore(void){
    rb_tree_t* arvore = malloc(sizeof(rb_tree_t));

    if(!arvore){perror("cria_arvore"); exit(EXIT_FAILURE);};

    return arvore;
}

rb_node_t* cria_no_arvore(void* dado){
    rb_node_t* node = malloc(sizeof(rb_node_t));

    if(!node){perror("cria_no_arvore"); exit(EXIT_FAILURE);};

    node->dado     = dado;
    node->esquerda = NULL;
    node->direita  = NULL;
    node->pai      = NULL;
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

    if(no_temp->esquerda){
        no_temp->esquerda->pai = node;
    }
    no_temp->pai = node->pai;

    if(!node->pai)
        arvore->raiz = no_temp;
    else if(node == node->pai->esquerda)
        node->pai->esquerda = no_temp;
    else
        node->pai->direita = no_temp;

    no_temp->esquerda = node;
    node->pai         = no_temp;
}

void rotacao_direita (rb_tree_t* arvore, rb_node_t* node){

}

void inserir_no_arvore(rb_tree_t* arvore, rb_node_t* node){
    rb_node_t *no_anterior = NULL;
    rb_node_t *no_temp = NULL;

    while(node){
        no_anterior = no_temp;
        if(compara_no(node,no_temp) < 0)
            no_temp = no_temp->esquerda;
        else
            no_temp = no_temp->direita;
    }

    node->pai = no_anterior;

    if(!no_anterior)
        arvore->raiz = node;
    else if(compara_no(node,no_anterior) < 0)
        no_anterior->esquerda = node;
    else
        no_anterior->direita = node;

    node->esquerda = NULL;
    node->direita  = NULL;
    node->cor      = VERMELHO;

    correcao_arvore(arvore,node);
}

int compara_no(rb_node_t* node_1, rb_node_t* node_2){
    int ret;
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
            }
            else if(node == node->pai->pai->direita){
                node = node->pai;
                rotacao_esquerda(arvore,node);
            }
            node->pai->cor = PRETO;
            node->pai->pai->cor = VERMELHO;
            rotacao_direita(arvore,get_avo(node));
        }
        else{
            no_temp = node->pai->pai->direita;
            if(no_temp->cor == VERMELHO){
                node->pai->cor = PRETO;
                no_temp->cor   = PRETO;
                node = get_avo(node);
            }
            else if(node == node->pai->pai->direita){
                node = node->pai;
                rotacao_direita(arvore,node);
            }
            node->pai->cor = PRETO;
            node->pai->pai->cor = VERMELHO;
            rotacao_esquerda(arvore,get_avo(node));
        }
    }
    arvore->raiz->cor = PRETO;
}
