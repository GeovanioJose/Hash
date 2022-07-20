#include"Hash.h"
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv){
	int c;
	int aflag = 0;
	int tamanho = 11;	
	HASH *ha;	
	opterr = 0;		
//	ha = criarHash(11); 
	//insereHash(ha, 110);
//	insereHash(ha, 93);
//	insereHash(ha, 60);
//	exibirHash(ha);
	
	
	while ((c = getopt (argc, argv, "hf:o:m:")) != -1){
  
	        switch (c){
	              
                        case 'h':
                                aflag = 0;			
                                help();
                                break;
                        
                        case 'f':                        
                                aflag = 2;                                
                                ha = criarHash(tamanho);                            
                                lerArquivo(ha, optarg);         
                                break; 
                                               
                        case 'o':		          	
                                aflag = 0;		     	     	
                                hashSalvar(ha, optarg);
                                break;  
                        
                        case 'm':          
                                aflag = 0;
                                tamanho = atoi(optarg);
                                break;         	
	          													 
                        case '?':
			if (optopt == 'c')
				fprintf (stderr, "Opção -%c requer um argumento.\n", optopt);
	        	else if (isprint (optopt))
				fprintf (stderr, "Opção desconhecida `-%c'.\n", optopt);
		        else
				fprintf (stderr,"Caractere de opção desconhecida `\\x%x'.\n", optopt);
			
				return 1;
		        default:
		                abort ();
			
			}
	}		

	if(aflag == 2){
	    exibirHash(ha);	        
	}
	
	return 0;
 
}
