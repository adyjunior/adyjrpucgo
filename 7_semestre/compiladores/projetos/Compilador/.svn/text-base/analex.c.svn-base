#include"analex.h"

	char * PALAVRAS_RESERVADAS[50] = {"se","senao","inicio","fim","enquanto","principal","inteiro","real","literal","escreva"};
	int qtdPalavrasReservadas = 10;
	int vetEstados[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
	char vetAfabeto[50] = "ld.\"c<bpx!>eouna=-";
	int qtdEstados = 29;
	int qtdAlfabeto = 18;
	int vetFinais[50] = {2,3,4,6,7,9,10,11,16,17,18,19,20,21,22,25,27,28,29};
	int qtdEstadosFinais = 19;
	int tamCadeia = 0;





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
		printf("MEMÓRIA INSUFICIENTE!!!");
	}

    aux->lexema=malloc((qtdElementosVetor(lexema)+1)*sizeof(char));

    int i;

    zeraVetor(aux->lexema);

    for(i=0;lexema[i]!='\0';i++){
        aux->lexema[i]=lexema[i];
    }

    aux->lexema[i]='\0';
	aux->tipo=tipo;
	aux->simbolo=NULL;

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

int comparaListaSimbolo(char *lexema,struct Simbolo *simbolo){
	if(simbolo==NULL){
		return 0;
	}

	return strcmp(lexema,simbolo->token->lexema);
}

struct Simbolo * alocaSimbolo(struct Token *token){
	struct Simbolo *aux;

	if((aux=(struct Simbolo *)malloc(sizeof(struct Simbolo)))==NULL){
		printf("memoria insuficiente!!!");
	}

	aux->token=token;
	aux->valor=0;
	token->simbolo=aux;

	return aux;
}

void impSimb ( struct Simbolo *   p )
{
	printf("***************************************************");
	while ( p ) {
		printf("%s %d", p->token->lexema, p->valor );
		p = p->prox;
	}
	printf("***************************************************");
}

void insereListaSimbolo(struct Token *token,struct Simbolo **iniSimb){
	if(*iniSimb==NULL){
		struct Simbolo *aux=alocaSimbolo(token);

		aux->prox=NULL;
		*iniSimb=aux;

		return;
	}else{
		struct Simbolo *auxOrdenacao=*iniSimb, *auxAnterior=*iniSimb;

		while(auxOrdenacao!=NULL){
			if(comparaListaSimbolo(token->lexema,auxOrdenacao)>0){
				auxAnterior=auxOrdenacao;
				auxOrdenacao=auxOrdenacao->prox;
			}else{
				if(comparaListaSimbolo(token->lexema,auxOrdenacao)<0){
					struct Simbolo *aux=alocaSimbolo(token);

					if(auxOrdenacao==*iniSimb){
						aux->prox=auxOrdenacao;
						*iniSimb=aux;
					}else{
						auxAnterior->prox=aux;
						aux->prox=auxOrdenacao;
					}

					return;
				}else{
					token->simbolo=auxOrdenacao;

					return;
				}
			}
		}

		if(auxOrdenacao==NULL){
			struct Simbolo *aux=alocaSimbolo(token);

			aux->prox=NULL;
			auxAnterior->prox=aux;
		}
	}
}

int buscarPalavrasReservadasVetStr(char *str,int tam){
	int i;
	for(i = 0;i < tam;i++){
		if(strcmpi(str,PALAVRAS_RESERVADAS[i])==0){
			return 1;
		}
	}

	return 0;
}

int codigoCategoria(int estado,char *lexema){

	if(estado == 2){//var if
		if(buscarPalavrasReservadasVetStr(lexema,qtdPalavrasReservadas)){
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

void nomeCategoria(int codigoCategoria,char *lexema){

	if(codigoCategoria == 1){
		printf("CATEGORIA: Identificadores\n"); // var if
	}else if(codigoCategoria == 2){
		printf("CATEGORIA: Operador condicional\n");// <= <
	}else if(codigoCategoria == 3){// + -
		printf("CATEGORIA: Operador aritmetico\n");
	}else if(codigoCategoria == 4 ){ // , ;
		printf("CATEGORIA: Pontuacao\n");
	}else if(codigoCategoria == 5){// { ]
		printf("CATEGORIA: Delimitador\n");
	}else if(codigoCategoria == 6){// "string"
		printf("CATEGORIA: Caracteres\n");
	}else if(codigoCategoria == 7){// <-
		printf("CATEGORIA: Operador de atribuicao\n");
	}else if(codigoCategoria == 8){// 12
		printf("CATEGORIA: Inteiro\n");
	}else if(codigoCategoria == 9){// 50.2
		printf("CATEGORIA: Ponto flutuante\n");
	}else if(codigoCategoria == 10){// .e. .ou. .nao.
		printf("CATEGORIA: Operador logico\n");
	}else if(codigoCategoria == 11){// =
		printf("CATEGORIA: Operador de comparacao\n");
	}else if(codigoCategoria == 29){ // \n ou \0
		printf("CATEGORIA: \\n ou \\0\n");
	}else if(codigoCategoria == 13){
		printf("CATEGORIA: Palavras reservadas\n");
	}
}

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
	if(c ==  '\"'  ){
		return '\"';
	}

	if(c != '\n' && c != '\0'){
		return 'c';
	}else{
		return c;
	}
}

char ehAspas(char c){
	if(c ==  '\"'  ){
		return '\"';
	}

	if(c == ' '){
		return c;
	}

	return 'c';
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

	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
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

void separaTokens(char *linha,char *lexema,FILE *entrada,struct Token **lstTokenIni,struct Token **lstTokenFim){
	int pos, c=0, posAceitacao;

	for(fgets(linha,255,entrada);!feof(entrada);fgets(linha,255,entrada)){
		pos = 0;

		posAceitacao = AFD(linha,&pos,lexema);

		if(posAceitacao > 0){
			c = codigoCategoria(vetEstados[posAceitacao],lexema);
			insereLista(lexema,c,&(*lstTokenIni),&(*lstTokenFim));
		}else{
			printf("ERRO TOKEN: %s\n",lexema);
			exit(0);
		}
		for(;c != CTE_MUDALINHA;){
			if(posAceitacao > 0){
				//printf("TOKEN: %s ",lexema);
				//nomeCategoria(c,lexema);
				c=0;
			}

			posAceitacao = AFD(linha,&pos,lexema);

			if(posAceitacao > 0){
				c = codigoCategoria(vetEstados[posAceitacao],lexema);
				insereLista(lexema,c,&(*lstTokenIni),&(*lstTokenFim));
			}else{
				printf("ERRO TOKEN: %s\n",lexema);
				exit(0);
			}
		}

		zeraVetor(linha);
		zeraVetor(lexema);
	}
}

void divideLexemaPorCategoria(struct Token **lstTokenIni,char *lexema){
	int i;
	struct Token *aux;
	bool loop=true, categoria=true;

	for(i=1;i<14;i++){
		aux=*lstTokenIni;

		while(loop){
			if(aux == NULL){
				printf("Ponteiro NULO");
				exit(2);
			}
			if(aux->tipo==i && categoria==true && aux->tipo!=29){
				//nomeCategoria(i,lexema);
				categoria=false;
			}
			if(aux->tipo==i && aux->tipo!=29){
				if(strcmp(aux->lexema,"\n")!=0){
					//printf("\t   %s\n",aux->lexema);
				}
			}

			aux=aux->prox;

			if(aux==NULL){
				loop=false;

				if(categoria==false){
					//printf("\n");
				}
			}
		}

		loop=true;
		categoria=true;
	}
}

void separaIdentificadores(struct Simbolo **iniSimb,struct Token **lstTokenIni){
	struct Token *aux;

	for(aux=*lstTokenIni;aux!=NULL;aux=aux->prox){
	    	if(aux->tipo==1){
	    		insereListaSimbolo(aux,&(*iniSimb));
	    	}
	    }
}

int AFD(char *cadeia,int *pos,char *lexema){

	int estado = 1;
	int i = *pos;
	int j = 0;

	while (cadeia[i] == ' ' || cadeia[i] == '\t'){
/*
		if(ehDigito(cadeia[i-1]) == 'd' && ehDigito(cadeia[i+1]) == 'd'){
			printf("ERRO : espaco entre numeros");
			exit(2);
		}
*/
		i++;
		//continue;
	}




	for(;;){


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

				if(cadeia[i-1] == '\"' && ((j-1) == 0)){
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
				}else{
					return verificaDefault(lexema,cadeia,i,j,pos,estado);
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


struct Token *lerArquivo(char *nomeArquivo){
	FILE *entrada;
	char linha[255],lexema[255];
	struct Token *lstTokenIni=NULL, *lstTokenFim=NULL;

	entrada = fopen(nomeArquivo,"rt");

	if(entrada==NULL){
		printf("ARQUIVO TEXTO NÃO ENCONTRADO!!!");
		exit(0);
	}

	zeraVetor(linha);
	zeraVetor(lexema);
	separaTokens(linha,lexema,entrada,&lstTokenIni,&lstTokenFim);

	fclose(entrada);
	//printf("\n");

	divideLexemaPorCategoria(&lstTokenIni,lexema);

    struct Simbolo *iniSimb=NULL, *auxSimb;

    separaIdentificadores(&iniSimb,&lstTokenIni);

    for(auxSimb=iniSimb;auxSimb!=NULL;auxSimb=auxSimb->prox){
    	//printf("LEXEMA: %s %d\n",auxSimb->token->lexema, auxSimb->valor );
    }

    return lstTokenIni;
}
