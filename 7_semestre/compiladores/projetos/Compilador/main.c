#include "analex.h"
#include "sintatico.h"
struct Token *lookAHead;

int main(int argc, char *argv[]){

	if(argc != 2){
		argv[1] = "fonteNumeros.txt";
	}
    lookAHead = lerArquivo(argv[1]);
	struct Token *teste = lookAHead;

    //printf("%d",H());
	int Hh = 1;
	H(Hh);

    if(lookAHead != NULL){
		printf("ERRO : Análise ");
		exit(2);
    }

	return 0;
}
