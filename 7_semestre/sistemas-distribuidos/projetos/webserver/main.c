#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define CTE_MUDALINHA 12

	//char vetEstados[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_";
	char * PALAVRAS_RESERVADAS[50] = {"se","senao","inicio","fim","enquanto","principal","inteiro","real","literal"};
	int qtdPalavrasReservadas = 9;
	int vetEstados[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
	char vetAfabeto[50] = "ld.\"c<bpx!>eouna=-";
	int qtdEstados = 29;
	int qtdAlfabeto = 18;
	//char vetFinais[50] = "BCFGIJKPQRSTUVYZ_";
	int vetFinais[50] = {2,3,4,6,7,9,10,11,16,17,18,19,20,21,22,25,27,28,29};
	int qtdEstadosFinais = 19;
	int tamCadeia = 0;

struct Token{
		char *lexema;
		int tipo;
		struct Token *prox;
	};

int qtdElementosVetor(char *vetor){
	int i;

	for(i=0;vetor[i]!='\0' && i<strlen(vetor);i++);

	return i;
}

void zeraVetor(char *vetor){
	int i;

	for(i=0;i<qtdElementosVetor(vetor) && i<strlen(vetor);i++){
		vetor[i]='\0';
	}
}

void insereLista(char *lexema,int tipo,struct Token **lstInicio,struct Token **lstFim){
	struct Token *aux;

	if((aux=(struct Token *)malloc(sizeof(struct Token)))==NULL){
		printf("memoria insuficiente!!!");
	}

    aux->lexema=malloc((qtdElementosVetor(lexema)+1)*sizeof(char));

    int i;

    zeraVetor(aux->lexema);

    for(i=0;lexema[i]!='\0';i++){
        aux->lexema[i]=lexema[i];
    }

    aux->lexema[i]='\0';
	aux->tipo=tipo;

	if(*lstInicio==NULL){
		aux->prox=NULL;
		*lstInicio=aux;
		*lstFim=aux;
	}else{
		aux->prox=NULL;
        (*lstFim)->prox=aux;
		*lstFim=aux;
	}
}
int buscarVetStr(char *str,int tam){
	int i;
	for(i = 0;i < tam;i++){
		printf("\n######## %s\n",PALAVRAS_RESERVADAS[i]);
		if(strcmp(str,PALAVRAS_RESERVADAS[i])){
			return 1;
		}
	}
	zeraVetor(str);
	return 0;
}

int codigoCategoria(int estado,char *lexema){

	if(estado == 2){//var if
		if(buscarVetStr(lexema,qtdPalavrasReservadas)){
			return 13;
		}else{
			return 1;
		}
	}else if(estado == 6 || estado == 7 || estado == 17 || estado == 19 || estado == 20){// <= <
		return 2;
	}else if(estado == 9){// + -
		return 3;
	}else if(estado == 10 || estado == 4 ){ // , ;
		return 4;
	}else if(estado == 11){// { ]
		return 5;
	}else if(estado == 16){// "string"
		return 6;
	}else if(estado == 18){// <-
		return 7;
	}else if(estado == 3){// 12
		return 8;
	}else if(estado == 21){// 50.2
		return 9;
	}else if(estado == 22 || estado == 25 || estado == 27){// .e. .ou. .nao.
		return 10;
	}else if(estado == 28){// =
		return 11;
	}else if(estado == 29){ // \n ou \0
		return 12;
	}

	return 0;
}

void nomeCategoria(int estado,char *lexema){

	if(estado == 2){
		if(buscarVetStr(lexema,qtdPalavrasReservadas)){
			printf("CATEGORIA: Palavras reservadas\n"); // var if
		}else{
			printf("CATEGORIA: Identificadores\n"); // var if
		}
	}else if(estado == 6 || estado == 7 || estado == 17 || estado == 19 || estado == 20){
		printf("CATEGORIA: Operador condicional\n");// <= <
	}else if(estado == 9){// + -
		printf("CATEGORIA: Operador aritmetico\n");
	}else if(estado == 10 || estado == 4 ){ // , ;
		printf("CATEGORIA: Pontuacao\n");
	}else if(estado == 11){// { ]
		printf("CATEGORIA: Delimitador\n");
	}else if(estado == 16){// "string"
		printf("CATEGORIA: Caracteres\n");
	}else if(estado == 18){// <-
		printf("CATEGORIA: Operador de atribuicao\n");
	}else if(estado == 3){// 12
		printf("CATEGORIA: Inteiro\n");
	}else if(estado == 21){// 50.2
		printf("CATEGORIA: Ponto flutuante\n");
	}else if(estado == 22 || estado == 25 || estado == 27){// .e. .ou. .nao.
		printf("CATEGORIA: Operador logico\n");
	}else if(estado == 28){// =
		printf("CATEGORIA: Operador de comparacao\n");
	}else if(estado == 29){ // \n ou \0
		printf("CATEGORIA: \\n ou \\0\n");
	}
}


int AFD(char *cadeia,int *pos,char *lexema);
int buscarVet(int c,int *vetor,int tam);
char ehLetra(char c){

	if(( c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z')){
		return 'l';
	}
	return '*';
}

char ehDigito(char c){
	if(c >= '0' && c <= '9'){
		return 'd';
	}
	return '*';
}

char ehCaractere(char c){
	if(c !=  '\"'  ){
		if(c != '\n' && c != '\0'){
			return 'c';
		}else{
			return c;
		}
	}
	return '\"';
}

char tipoCaractere(char c){

	if(ehDigito(c) == 'd'){
		return 'd';
	}

	if(ehLetra(c) == 'l'){
		return 'l';
	}

	if(c == ',' || c == ';'){
		return 'p';
	}

	if(c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']'){
		return 'b';
	}

	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
		return 'x';
	}


	return c;
}

int verificaDefault(char *lexema,char *cadeia,int i,int j,int *pos,int estado){
	if(buscarVet(estado,vetFinais,qtdEstadosFinais) != -1){
		lexema[j] = '\0';
		(*pos) = i;
		return buscarVet(estado,vetEstados,qtdEstados);
	}else{
		lexema[j] = cadeia[i];
		(*pos) = ++i;
		j++;
		lexema[j] = '\0';
		return -(buscarVet(estado,vetEstados,qtdEstados));
	}
}



int main(){

	int i = 0;
	int posAceitacao = 0;
	char cadeia[50] = ".nao.";

	for(i = 0;cadeia[i] != '\0';i++,tamCadeia++);


	int pos,c=0;
	FILE *entrada;
	char linha[255],lexema[255];
	struct Token *lstTokenIni=NULL, *lstTokenFim=NULL;

	entrada = fopen("fonte1.txt","rt");

	zeraVetor(linha);
	zeraVetor(lexema);

	for(fgets(linha,255,entrada);!feof(entrada);fgets(linha,255,entrada)){
		pos = 0;

		posAceitacao = AFD(linha,&pos,lexema);

		if(posAceitacao > 0){
			c = codigoCategoria(vetEstados[posAceitacao],lexema);
			insereLista(lexema,vetEstados[posAceitacao],&lstTokenIni,&lstTokenFim);
		}else{
			printf("ERRO TOKEN: %s\n",lexema);
			exit(0);

			c=0;
		}
		for(;c != CTE_MUDALINHA;){
			if(posAceitacao > 0){
				//printf("TOKEN: %s, cat %d\n",lexema,c);
				printf("TOKEN: %s ",lexema);
				nomeCategoria(vetEstados[posAceitacao],lexema);
				c=0;
			}

			posAceitacao = AFD(linha,&pos,lexema);

			if(posAceitacao > 0){
				c = codigoCategoria(vetEstados[posAceitacao],lexema);
				insereLista(lexema,vetEstados[posAceitacao],&lstTokenIni,&lstTokenFim);
			}else{
				printf("ERRO TOKEN: %s\n",lexema);
				exit(0);
			}
		}

		zeraVetor(linha);
		zeraVetor(lexema);
	}

	fclose(entrada);
	printf("\n");

	struct Token *aux;
	bool loop=true, categoria=true;

    for(pos=2;pos<30;pos++){
        aux=lstTokenIni;

        while(loop){
        	if(aux->tipo==pos && categoria==true){
				nomeCategoria(pos,lexema);
				categoria=false;
        	}
        	if(aux->tipo==pos){
				if(strcmp(aux->lexema,"\n")!=0){
					printf("\t%s\n",aux->lexema);
				}
        	}

			aux=aux->prox;

        	if(aux==NULL){
				loop=false;

				if(categoria==false){
					printf("\n");
				}
			}
        }

        loop=true;
        categoria=true;
    }

	return 0;
}


int AFD(char *cadeia,int *pos,char *lexema){

	int estado = 1;
	int i = *pos;
	int j = 0;
	//int i = *pos;
	for(;;){

		if(cadeia[i] == ' ' || cadeia[i] == '\t'){
			i++;
			continue;
		}

		switch(estado){
			case 1:

				switch(tipoCaractere(cadeia[i])){
					case 'l'  :
						estado = 2;
					break;

					case 'd':
						estado = 3;
					break;

					case '.':
						estado = 4;
					break;

					case '\"':
						estado = 5;
					break;

					case '<':
						estado = 6;
					break;

					case 'b':
						estado = 11;
					break;

					case 'p':
						estado = 10;
					break;

					case 'x':
						estado = 9;
					break;

					case '!':
						estado = 8;
					break;

					case '>':
						estado = 7;
					break;

					case '=':
						estado = 28;
					break;

					case '\n':
						estado = 29;
					break;

					case '\0':
						estado = 29;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 2:

				switch(tipoCaractere(cadeia[i])){
					case 'l':
						estado = 2;
					break;

					case 'd':
						estado = 2;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 3:

				switch(tipoCaractere(cadeia[i])){
					case 'd':
						estado = 3;
					break;

					case '.':
						estado = 12;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 4:

				switch(cadeia[i]){
					case 'e':
						estado = 13;
					break;

					case 'o':
						estado = 14;
					break;

					case 'n':
						estado = 15;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 5:

				switch(ehCaractere(cadeia[i])) {
					case '\"':
						estado = 16;
					break;

					case 'c':
						estado = 5;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 6:

				switch(cadeia[i]){
					case '=':
						estado = 17;
					break;

					case '-':
						estado = 18;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 7:

				switch(cadeia[i]){
					case '=':
						estado = 19;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 8:

				switch(cadeia[i]){
					case '=':
						estado = 20;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 9:

				switch(tipoCaractere(cadeia[i])){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 10:

				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 11:

				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 12:

				switch(tipoCaractere(cadeia[i])){
					case 'd':
						estado = 21;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 13:

				switch(cadeia[i]){
					case '.':
						estado = 22;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 14:

				switch(cadeia[i]){
					case 'u':
						estado = 24;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 15:

				switch(cadeia[i]){
					case 'a':
						estado = 23;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 16:

				switch(ehCaractere(cadeia[i])){
					case '\"':
						estado = 5;
					break;

					case 'c'://exception
						estado = 5;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 17:

				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 18:

				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 19:

				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 20:

				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 21:

				switch(tipoCaractere(cadeia[i])){
					case 'd':
						estado = 21;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 22:

				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 23:

				switch(cadeia[i]){
					case 'o':
						estado = 26;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 24:

				switch(cadeia[i]){
					case '.':
						estado = 25;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
			}

			break;

			case 25:

				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 26:

				switch(cadeia[i]){
					case '.':
						estado = 27;
					break;

					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 27:

				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 28:

				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}

			break;

			case 29:
				switch(cadeia[i]){
					default:
						return verificaDefault(lexema,cadeia,i,j,pos,estado);
					break;
				}
			break;

			default:
				return 0;
			break;

		}

		lexema[j] = cadeia[i];
		i++;
		j++;
	}

	return 0;
}

int buscarVet(int c,int *vetor,int tam){
	int i;
	for(i=0;i < tam;i++){
	if(vetor[i] == c)
		return i;
	}
	return -1;
}
