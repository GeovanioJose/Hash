#ifndef __HASH_H__
#define __HASH_H__

#include<stdio.h>
#include<stdlib.h>

#define MAX 2000000

typedef struct no{
	int chave;
	struct no* prox;
}no;

typedef struct HASH{
	int qtd, tam;
	struct no **lista;
}HASH;


void help();
HASH* criarHash(int tam);
void destruirHash(HASH * hash);
int insereHash(HASH * ha, int chave);
no* buscarHash(HASH *ha, int chave);
int H(int chave, int tam);
void lerArquivo(HASH *ha, char *argv);
void hashSalvar(HASH* ha, char *argv);
void lerHash(HASH *ha, FILE *fp);
void exibirHash(HASH *ha);



#endif
