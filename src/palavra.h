#ifndef PALAVRA_H_INCLUDED
#define PALAVRA_H_INCLUDED

typedef struct palavra palavra_t;

palavra_t* cria_palavra (char* chave, char* significado);

char* obtem_chave (palavra_t* palavra);

char* obtem_significado(palavra_t* palavra);

void libera_palavra (palavra_t* palavra);

#endif // PALAVRA_H_INCLUDED
