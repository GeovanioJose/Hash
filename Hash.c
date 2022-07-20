#include "Hash.h"

void help(){
	printf("-h 				: mostra o help\n");
	printf("-o <arquivo> 			: redireciona a saida para o ‘‘arquivo’’\n");
	printf("-f <arquivo> 			: indica o ‘‘arquivo’’ que contém os dados a serem adicionados na Heap\n");
	printf("-m <inteiro> 			: o tamanho da hash (default=11)\n");
};

HASH* criarHash(int tam){
	int i;
	HASH *ha = (HASH *) malloc(sizeof(HASH));
	if(ha != NULL){
		ha->tam = tam;
		ha->lista = (no **) malloc(tam * sizeof(no*));			
	}
	ha->qtd = 0;
	for(i = 0; i < ha->tam; i++){
		ha->lista[i] = NULL;
	}
	
	return ha;
	
}

int H(int chave, int tam){
	return (chave & 0x7fffffff) % tam; ;
}

int insereHash(HASH *ha, int chave){
		
	no* novo = (no*) malloc(sizeof(no));
	novo->chave = chave;
	novo->prox = NULL;
	
	no* atual = ha->lista[H(chave, ha->tam)];
	no* ant = NULL;
	while(atual != NULL){
	        ant = atual;
	        atual = atual->prox;
	}
	if(ant == NULL){ 
	        ha->lista[H(chave, ha->tam)] = novo;   
	}else{
	        
	        ant->prox = novo;	            
	}
		
	ha->qtd++;
	return 1;
	
}


void lerArquivo(HASH *ha, char *argv){
	FILE *fp;	
	int dado = 0;		
	int cont = 0;
	
	fp = (FILE *) fopen(argv, "r");	
	if(fp != NULL) {
		while(fscanf(fp, "%i\n", &dado) != EOF){
			insereHash(ha, dado);
		}		
		fclose(fp);		
	}else{
		printf("Erro na abertura do arquivo!\n");
	}
	
	
};


void hashSalvar(HASH* ha, char *argv){
	FILE *fp;	
	fp = (FILE *) fopen(argv, "w");	
	if(fp != NULL) {
		lerHash(ha, fp);
		fclose(fp);		
	}else{
		printf("Erro na abertura do arquivo!\n");
	}
};

void lerHash(HASH *ha, FILE *fp){
	int tamanho = ha->tam;
	int i;
	for (i = 0;i < tamanho ;i++){
		fprintf(fp, "%d: ", i);		
		if(ha->lista[i] != NULL){		        
			no* temp = ha->lista[i];
			while(temp != NULL){				
				fprintf(fp, "%d ", temp->chave);
				temp = temp->prox;
			}
		}
	        fprintf(fp, "\n");
	}
}

void exibirHash(HASH *ha){
	int tamanho = ha->tam ;
	int i;
	
	for (i = 0;i < tamanho ;i++){
		printf("%d: ", i);		
		if(ha->lista[i] != NULL){		        
			no* temp = ha->lista[i];
			while(temp != NULL){				
				printf("%d ", temp->chave);
				temp = temp->prox;
			}
		}
	        printf("\n");
	}
}









