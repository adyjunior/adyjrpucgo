#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************** VARIAVEIS GLOBAIS BEGIN**********************************/

struct noEstado * transicao[50][50];
int qtdEstadosFinais = 0;
int qtdAlfabeto = 0;
int qtdEstados = 0;
int selecao = 0;


/*************************** VARIAVEIS GLOBAIS END**********************************/


/*************************** FUNCOES AUXILIARES BEGIN**********************************/

int buscarVet(char c,char *vetor,int tam);
int tabulacao(int size,int maior);
int isEstadoValido(char c,char *vetEstados,int tam);
void imprimeVetorCorrente(int posCorrente,char *vet);
void imprimeVetor(int size,char *vet);
void ordenaVetor(char *vet,int tam);

/*************************** FUNCOES AUXILIARES END**********************************/


/*************************** LISTA NO ESTADO BEGIN**********************************/

typedef struct noEstado {
	char estado;
	struct noEstado *prox;
}noEstado;
void insereLista(char c, struct noEstado **inicio);
int buscar(struct noEstado *inicio,char c);
void imprimiLista(struct noEstado *inicio);
int contaElementos(struct noEstado *lista);
struct noEstado *trucaLista(struct noEstado *lista);
int comparaListas(struct noEstado *listaA,struct noEstado *listaB);
int maiorLista();

/*************************** LISTA NO ESTADO END**********************************/


/*************************** LISTA PASSO CONV BEGIN**********************************/

typedef struct passoConv {
	char estado;
	char estadoPai;
	int ehFinal;
	int ehRepetida;
	char caminho;
	struct noEstado *endLista;
	struct passoConv *prox;
}passoConv;

void insereListaNaLista(char c, char estadoPai, int caminho,char *vetEstadosFinais, struct noEstado *lista, struct passoConv **inicio,int ehRepetida);
int contaElementosConv(struct passoConv *lista);
void imprimiListaConv(struct passoConv *inicio);
struct passoConv *buscarConv(struct passoConv *inicio,struct noEstado *listaNoEstado);
char *contaAndInsereElementosNaoRepetidos(int *contador,struct passoConv *lista);

/*************************** LISTA PASSO CONV END**********************************/

/*************************** LISTA PAR ESTADO BEGIN**********************************/

typedef struct parEstado{
	char estado1;
	char estado2;
	struct lstAcusados *acusado;
	struct parEstado *prox;
	int marcado;
}parEstado;

void insereListaParEstado(char estado1, char estado2, struct lstAcusados *acusado, int marcado,struct parEstado **inicio);
void imprimiListaParEstado(struct parEstado *inicio);
int contaElementosListaParEstado(struct parEstado *lista);
struct parEstado *buscarListaParEstado(struct parEstado *inicio,char estado1,char estado2);

/*************************** LISTA PAR ESTADO END**********************************/


/*************************** LISTA LST ACUSADOS BEGIN**********************************/

typedef struct lstAcusados{
	struct parEstado *par;
	struct lstAcusados *prox;
}lstAcusados;

void insereListaAcusados(struct parEstado *par,struct lstAcusados **inicio);
void marcaDois(struct parEstado *parAux);
void marcaListaAcusados(struct lstAcusados *listaAcusados);

/*************************** LISTA LST ACUSADOS END**********************************/


/*************************** FUNCOES PRINCIPAIS BEGIN**********************************/

struct noEstado *fechamento(char estado,char *vetEstado,char *vetAlfabeto,struct noEstado **lista);
struct noEstado *mov(int posElemento,char *vetEstado,char *vetAlfabeto,struct noEstado *lista);
void imprimeEstados(char *vetEstados,char *vetAlfabeto,char * vetEstadosFinais,int qtdEstadosFinais,char estadoInicial);
void imprimeTabelaAFD(struct passoConv *listaFechamentos,char *vetAlfabeto);
void leituraDeEstadosAltomatica();
void leituraEstados();
void interface();
void minimizacao(char matrizAFD[50][50],char *vetEstados,char *vetAlfabeto,char *vetEstadosFinais,char estadoInicial);
void imprimeTabelaAFDMinimizado(struct parEstado *par,char *vetEstados);
void alimentacaoAltomaticaAFD();
void imprimeAFDMinimizado(struct parEstado *par,char *vetEstados,char *vetAlfabeto,char matrizAFD[50][50],char *vetEstadosFinais,char estadoInicial);
void geraAutomato(char *vetEstados,char *vetAfabeto,char *vetEstadosFinais,char estadoInicial,char matrizTransicao[50][50]);

/*************************** FUNCOES PRINCIPAIS END**********************************/



/*************************** MAIN BEGIN**********************************/

int main(){
	//leituraDeEstadosAltomatica();
	interface();
	//minimizacao();
	//alimentacaoAltomaticaAFD();
	return EXIT_SUCCESS;
}

/*************************** MAIN END**********************************/


/*************************** CORPO DAS FUNCOES AUXILIARES BEGIN**********************************/

int buscarVet(char c,char *vetor,int tam){
	int i;
	for(i=0;i < tam;i++){
		if(vetor[i] == c)
			return i;
	}

	return -1;
}

int tabulacao(int size,int maior){
	int tam;
	tam = (maior+(maior-1)) - (size+(size-1));
	if(size == 0)--tam;

	return tam;
}

int isEstadoValido(char c,char *vetEstados,int tam){
	int i;

	for(i=0;i < tam;i++){
		if(vetEstados[i] == c){
			return 1;
		}
	}

	return 0;
}

void imprimeVetorCorrente(int posCorrente,char *vet){
	int i;
	printf("{");
	for(i=0;i <posCorrente;i++){
		char ch;
		if(i  < posCorrente-1)
			ch = ',';
		else
			ch = ' ';
		printf("%c%c",vet[i],ch);
	}
	printf("}\n");
}

void imprimeVetor(int size,char *vet){
	int i;
	printf("{");
	for(i=0;i < size;i++){
		char ch;
		if(i  < size-1)
			ch = ',';
		else
			ch = ' ';
		printf("%c%c",vet[i],ch);
	}
	printf("}\n");
}

void ordenaVetor(char *vet, int tam){
	int menor, i, j, temp;
	for (i = 0; i < (tam - 1); i++){

		for (j = i + 1, menor = i; j < tam; j++)
			if (vet[j] < vet[menor])
				menor = j;
		temp = vet[menor];
		vet[menor] = vet[i];
		vet[i] = temp;
	}
}

/*************************** CORPO DAS FUNCOES AUXILIARES END**********************************/



/*************************** CORPO DA LISTA NO-ESTADO BEGIN**********************************/

void insereLista(char c, struct noEstado **inicio){
	struct noEstado *novo;

	if((novo=(struct noEstado*) malloc(sizeof(struct noEstado)))==NULL){
		printf("MemÃƒÂ³ria insuficiente!!!\n");
	}

	novo->estado=c;

	if(*inicio==NULL){
		novo->prox=NULL;
		*inicio=novo;

	} else{
		struct noEstado *noEstadoAux=*inicio;

		for(;noEstadoAux->prox != NULL;noEstadoAux = noEstadoAux->prox);

		novo->prox=NULL;
		noEstadoAux->prox=novo;
	}
}


int buscar(struct noEstado *inicio,char c){
	struct noEstado *noAux = inicio;

	if(noAux == NULL)return 0;

	if(noAux->estado == c)return 1;
	for(;noAux->prox != NULL;noAux = noAux->prox){
		if(noAux->prox->estado == c)
			return 1;
	}

	return 0;
}

void imprimiLista(struct noEstado *inicio){
	struct noEstado *noEstadoAux=inicio;

	if(inicio == NULL){printf("{}"); return;}

	printf("{");
	printf("%c",noEstadoAux->estado);
	if(noEstadoAux->prox != NULL)printf(",");
	for(;noEstadoAux->prox != NULL;noEstadoAux = noEstadoAux->prox){
		printf("%c",noEstadoAux->prox->estado);
		if(noEstadoAux->prox->prox != NULL)
			printf(",");
	}printf("}");
}

int contaElementos(struct noEstado *lista){
	int cont=0;

	if(lista==NULL) return 0;

	for(;lista!=NULL;lista=lista->prox,cont++);

	return cont;
}

struct noEstado *trucaLista(struct noEstado *lista){

	if(lista ==NULL)return NULL;

	struct noEstado *listaTruncada = NULL;

	for(;lista != NULL;lista = lista->prox){

		if(buscar(listaTruncada,lista->estado) == 0){
			insereLista(lista->estado,&listaTruncada);
		}

	}

	return listaTruncada;

}

int comparaListas(struct noEstado *listaA,struct noEstado *listaB){

	if(contaElementos(listaA) != contaElementos(listaB)){
		return 0;
	}

	struct noEstado *a = listaA;
	struct noEstado *b = listaB;
	int cont =0;
	int sucesso =0;

	for (; a != NULL;a = a->prox) {

		cont = 0;
		for(b = listaB;b != NULL;b = b->prox){

			if(buscar(listaA,b->estado)){
				cont++;
			}
		}

		if(cont == contaElementos(listaA)){
			sucesso++;
		}
	}

	if(sucesso == contaElementos(listaB)){
		return 1;
	}
	return 0;

}

int maiorLista(){
	int i,j,maior = 0;

	for(i = 0; i < qtdEstados;i++)
		for(j = 0;j < qtdAlfabeto;j++){
			struct noEstado *aux = transicao[i][j];

			if(contaElementos(aux) > maior){
				maior = contaElementos(aux);
			}
		}

	return maior;
}
/*************************** CORPO DA LISTA NO-ESTADO END**********************************/


/*************************** CORPO DA LISTA PASSO CONV BEGIN**********************************/

void insereListaNaLista(char c, char estadoPai, int caminho,char *vetEstadosFinais, struct noEstado *lista, struct passoConv **inicio,int ehRepetida){
	struct passoConv *novo;

	if((novo=(struct passoConv*) malloc(sizeof(struct passoConv)))==NULL){
		printf("MemÃƒÂ³ria insuficiente!!!\n");
	}

	novo->estado=c;
	novo->endLista = lista;
	novo->estadoPai = estadoPai;
	novo->caminho = caminho;
	novo->ehFinal = 0;
	novo->ehRepetida = ehRepetida;

	struct noEstado *listaAux = lista;

	for(;listaAux != NULL;listaAux = listaAux->prox){
		if(buscarVet(listaAux->estado,vetEstadosFinais,qtdEstadosFinais) != -1){
			novo->ehFinal =  1;
		}

	}


	if(*inicio==NULL){
		novo->prox=NULL;
		*inicio=novo;

	} else{
		struct passoConv *noEstadoAux=*inicio;

		for(;noEstadoAux->prox != NULL;noEstadoAux = noEstadoAux->prox);

		novo->prox=NULL;
		noEstadoAux->prox=novo;
	}
}

int contaElementosConv(struct passoConv *lista){
	int cont=0;

	if(lista==NULL) return 0;

	for(;lista->prox!=NULL;lista=lista->prox,cont++);

	return cont;
}

void imprimiListaConv(struct passoConv *inicio){
	struct passoConv *noAux=inicio;

	if(inicio == NULL){ return;}

	printf("%c ->",noAux->estado);
	imprimiLista(noAux->endLista);
	printf("\nEstado pai : %c \nCaminho : %i",noAux->estadoPai,noAux->caminho);
	if(noAux->prox != NULL)printf("\n");
	for(;noAux->prox != NULL;noAux = noAux->prox){
		printf("%c ->",noAux->prox->estado);
		imprimiLista(noAux->prox->endLista);
		printf("\nEstado pai : %c \nCaminho : %c",noAux->prox->estadoPai,noAux->prox->caminho);

		if(noAux->prox->prox != NULL)
			printf("\n");
	}
}

struct passoConv *buscarConv(struct passoConv *inicio,struct noEstado *listaNoEstado){
	struct passoConv *noAux = inicio;

	if(inicio == NULL)return 0;

	struct noEstado *listaNoEstadoAux = listaNoEstado;

	for(;noAux != NULL;noAux = noAux->prox){
		if(comparaListas(noAux->endLista,listaNoEstadoAux) &&
				comparaListas(listaNoEstadoAux,noAux->endLista)){
			//return noAux->estado;
			return noAux;
		}
	}

	return 0;

}

char *contaAndInsereElementosNaoRepetidos(int *contador,struct passoConv *lista){

	int tam = 0,i,j;
	*contador = 0;
	char *vet;
	if(lista == NULL)return 0;

	struct passoConv *listaAux = lista;

	tam = contaElementosConv(lista);

	vet = (char*) malloc(tam*sizeof(char*));

	for(i=0;i < tam; i++)
		vet[i] = '\0';


	for(listaAux = listaAux->prox,i=0,j=0;listaAux != NULL;listaAux = listaAux->prox,i++){
		if(buscarVet(listaAux->estadoPai,vet,i) == -1){
			vet[j] = listaAux->estadoPai;
			*contador = *contador +1;
			j++;
		}
	}

	return vet;
}

/*************************** CORPO DA LISTA PASSO CONV END**********************************/

/*************************** CORPO DA LISTA PAR ESTADO BEGIN**********************************/

void insereListaParEstado(char estado1, char estado2, struct lstAcusados *acusado, int marcado,struct parEstado **inicio){
	struct parEstado *novo;

	if((novo=(struct parEstado*) malloc(sizeof(struct parEstado)))==NULL){
		printf("MemÃƒÂ³ria insuficiente!!!\n");
	}

	novo->estado1 = estado1;
	novo->estado2 = estado2;
	novo->acusado = acusado;
	novo->marcado = marcado;

	if(*inicio==NULL){
		novo->prox=NULL;
		*inicio=novo;

	} else{
		struct parEstado *parEstadoAux=*inicio;

		if(buscarListaParEstado(parEstadoAux,estado1,estado2) != NULL)return;

		for(;parEstadoAux->prox != NULL;parEstadoAux = parEstadoAux->prox);

		novo->prox=NULL;
		parEstadoAux->prox=novo;
	}
}

void imprimiListaParEstado(struct parEstado *inicio){

	struct parEstado *parEstadoAux=inicio;

	if(inicio == NULL){printf("{}"); return;}

	printf("{");
	printf(" {%c,%c|%i}",parEstadoAux->estado1,parEstadoAux->estado2,parEstadoAux->marcado);
	if(parEstadoAux->prox != NULL)printf(",");
	for(;parEstadoAux->prox != NULL;parEstadoAux = parEstadoAux->prox){
		printf(" {%c,%c|%i}",parEstadoAux->prox->estado1,parEstadoAux->prox->estado2,parEstadoAux->prox->marcado);
		if(parEstadoAux->prox->prox != NULL)
			printf(",");
	}printf(" }");
}

int contaElementosListaParEstado(struct parEstado *lista){
	int cont=0;

	if(lista==NULL) return 0;

	for(;lista!=NULL;lista=lista->prox,cont++);

	return cont;

}

struct parEstado *buscarListaParEstado(struct parEstado *inicio,char estado1,char estado2){
	struct parEstado *noAux = inicio;

	if(noAux == NULL)return NULL;

	if((noAux->estado1 == estado1  && noAux->estado2 == estado2)||
			(noAux->estado2 == estado1  && noAux->estado1 == estado2))return noAux;
	for(;noAux->prox != NULL;noAux = noAux->prox){
		if((noAux->prox->estado1 == estado1  && noAux->prox->estado2 == estado2) ||
				(noAux->prox->estado1 == estado2  && noAux->prox->estado2 == estado1) )
			return noAux->prox;
	}

	return NULL;
}

/*************************** CORPO DA LISTA PAR ESTADO END**********************************/

/*************************** CORPO DA LISTA LST ACUSADOS BEGIN**********************************/
void insereListaAcusados(struct parEstado *par,struct lstAcusados **inicio){

	struct lstAcusados *novo;

	if((novo=(struct lstAcusados*) malloc(sizeof(struct lstAcusados)))==NULL){
		printf("MemÃƒÂ³ria insuficiente!!!\n");
	}

	novo->par = par;

	if(*inicio==NULL){
		novo->prox=NULL;
		*inicio=novo;

	} else{
		struct lstAcusados *noAux=*inicio;

		for(;noAux!=NULL;noAux=noAux->prox){
			if((noAux->par->estado1==novo->par->estado1 && noAux->par->estado2==novo->par->estado2) ||
					(noAux->par->estado2==novo->par->estado1 && noAux->par->estado1==novo->par->estado2))return;
		}

		noAux=*inicio;

		for(;noAux->prox != NULL;noAux = noAux->prox);

		novo->prox=NULL;
		noAux->prox=novo;
	}
}

/*************************** CORPO DA LISTA LST ACUSADOS END**********************************/



/*************************** CORPO DAS FUNCOES PRINCIPAIS BEGIN**********************************/

struct noEstado *fechamento(char estado,char *vetEstado,char *vetAlfabeto,struct noEstado **lista){

	struct noEstado *p = NULL;

	int indiceEstado,numDeSimbolosAlfabeto;

	indiceEstado = buscarVet(estado,vetEstado,qtdEstados);
	if(indiceEstado == -1)return NULL;

	numDeSimbolosAlfabeto = qtdAlfabeto-1;

	p = transicao[indiceEstado][numDeSimbolosAlfabeto];

	for(;p != NULL;p = p->prox){

		if(!buscar(*lista,p->estado)){
			insereLista(p->estado,lista);
			fechamento(p->estado,vetEstado,vetAlfabeto,lista);
		}

	}

	return NULL;
}


struct noEstado *mov(int posElemento,char *vetEstado,char *vetAlfabeto,struct noEstado *lista){

	int posEstado;

	struct noEstado *listaNova = NULL;
	struct noEstado * aux = NULL;

	for(;lista != NULL;lista = lista->prox){

		posEstado = buscarVet(lista->estado,vetEstado,qtdEstados);

		if(posEstado == -1){
			printf("ERRO : Estado %c nao foi encontrado na lista : \n",lista->estado);
			imprimeVetor(qtdEstados,vetEstado);
			exit(1);
		}

		aux = transicao[posEstado][posElemento];

		for(;aux != NULL;aux = aux->prox){
			insereLista(aux->estado,&listaNova);
		}
	}

	struct noEstado *listaCompleta = NULL;

	listaCompleta = trucaLista(listaNova);

	struct noEstado *listaFechada = NULL;

	listaFechada = listaCompleta;

	for(;listaCompleta!= NULL;listaCompleta = listaCompleta->prox){
		fechamento(listaCompleta->estado,vetEstado,vetAlfabeto,&listaFechada);
	}


	return listaFechada;
}

void interface(){
	int opcao = 50;


	printf("                \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	printf("                \xba             CIENCIA DA COMPUTACAO             \xba\n");
	printf("                \xba                    PUC-GO                     \xba\n");
	printf("                \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
	printf("                \xba            ALUNO : ADY JUNIOR                 \xba\n");
	printf("                \xba            ALUNO : MURILLO IVAMOTO            \xba\n");
	printf("                \xba            ALUNO : LUCAS MARTINS              \xba\n");
	printf("                \xba            ALUNO : JOHNNY GONCALVES           \xba\n");
	printf("                \xba            PROFESSOR : IAMAR ZUZA             \xba\n");
	printf("                \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

	printf("ENTER para continuar...");
	getchar();
	system("cls");

	while(opcao){
		selecao = 0;


		printf("     \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
		printf("     \xba                      CONVERSOR DE AUTOMATOS                     \xba\n");
		printf("     \xba                                                                 \xba\n");
		printf("     \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
		printf("     \xba  (1) - CONVERTER AUTOMATO COM ALIMENTACAO DE FORMA AUTOMATICA   \xba\n");
		printf("     \xba  (2) - CONVERTER AUTOMATO COM ALIMENTACAO DE FORMA MANUAL       \xba\n");
		printf("     \xba  (3) - MINIMIZAR AUTOMATO                                       \xba\n");
		printf("     \xba  (0) - SAIR                                                     \xba\n");
		printf("     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

		printf("OPCAO :");
		scanf("%d",&opcao);
		getchar();
		system("cls");

		switch (opcao) {
		case 1:
			leituraDeEstadosAltomatica();
			break;
		case 2:
			leituraEstados();
			break;
		case 3:{
			//selecao = 1;
			//leituraEstados();
			alimentacaoAltomaticaAFD();
			break;
		}
		case 0:
			exit(1);
			break;
		default:
			printf("Opcao invalida !!!\n");
			printf("ENTER para continuar...\n\n");
			getchar();
			system("cls");
			break;
		}

	}


}


void imprimeEstados(char *vetEstados,char *vetAlfabeto,char * vetEstadosFinais,int qtdEstadosFinais,char estadoInicial){
	int i,j,k,tamMaiorLista=0,deslocamento =0;

	tamMaiorLista = maiorLista();

	printf("     \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	printf("     \xba                           AUTOMATO AFN                          \xba\n");
	printf("     \xba                                                                 \xba\n");
	printf("     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

	printf("%20c Estado(s) :{",' ');
	for(i = 0;i < qtdEstados; i++){
		if(buscarVet(vetEstados[i],vetEstadosFinais,qtdEstadosFinais) != -1){
			printf("(%c)",vetEstados[i]);
		}else if(vetEstados[i] == estadoInicial){
			printf("%c*",vetEstados[i]);
		}else{
			printf("%c",vetEstados[i]);
		}
		if((i+1) != qtdEstados)
			printf(",");
	}
	printf("}\n");



	printf("%20c Estado Inicial : %c\n",' ',estadoInicial);

	printf("%20c Estado(s) Finai(s) :{",' ');
	for(i = 0;i < qtdEstadosFinais; i++){
		printf("%c",vetEstadosFinais[i]);
		if((i+1) != qtdEstadosFinais)
			printf(",");
	}
	printf("}\n");


	printf("%20c   & ",' ');
	for(i=0;i<qtdAlfabeto;i++){
		deslocamento = tabulacao(1,tamMaiorLista);
		for(j = 0;j < (deslocamento+tamMaiorLista+2)/2;j++)printf(" ");
		printf("%c",vetAlfabeto[i]);
		for(j = 0;j < (deslocamento+tamMaiorLista+2)/2;j++)printf(" ");

	}
	printf("\n");

	deslocamento = 0;

	for(i =0; i < qtdEstados;i++){
		for (j = 0; j < qtdAlfabeto; j++) {
			if(j == 0){
				printf("%22c %c",vetEstados[i],' ');
			}

			deslocamento = tabulacao(contaElementos(transicao[i][j]),tamMaiorLista);
			printf(" | ");
			for(k = 0; k < deslocamento;k++)printf(" ");
			imprimiLista(transicao[i][j]);
		}
		printf("|");
		printf("%22c\n",' ');
	}

	printf("\n\n");

}

void imprimeTabelaAFD(struct passoConv *listaFechamentos,char *vetAlfabeto){

	int qtdEstadosAFD =0,i,j,qtdEstadosFinaisAFD=0;
	char *estadosAFD;
	char *estadosFinaisAFD;
	char *alfabetoAFD;

	char transDeter[50][50];
	char *vet;

	for(i=0;i < 50;i++)
		for(j=0;j < 50;j++)
			transDeter[i][j] = '\0';

	vet = contaAndInsereElementosNaoRepetidos(&qtdEstadosAFD,listaFechamentos);

	estadosAFD = (char*) malloc(qtdEstadosAFD*sizeof(char*));
	alfabetoAFD = (char*) malloc((qtdAlfabeto-1)*sizeof(char*));

	for(i = 0; i < qtdAlfabeto-1;i++)
		alfabetoAFD[i] = vetAlfabeto[i];

	for(i = 0;i < qtdEstadosAFD;i++)
		estadosAFD[i] = '\0';

	for(i = 0;i < qtdEstadosAFD;i++)
		estadosAFD[i] = vet[i];

	struct passoConv *listaAux = listaFechamentos;

	for(listaAux = listaAux->prox;listaAux != NULL;listaAux = listaAux->prox){
		int elemento,estado;

		elemento = buscarVet(listaAux->estadoPai,estadosAFD,qtdEstadosAFD);
		estado = listaAux->caminho;

		transDeter[elemento][estado] = listaAux->estado;

	}

	listaAux = listaFechamentos;
	for(;listaAux != NULL;listaAux = listaAux->prox)
		if(listaAux->ehFinal)
			qtdEstadosFinaisAFD++;

	estadosFinaisAFD = (char*) malloc(qtdEstadosFinaisAFD*sizeof(char*));

	listaAux = listaFechamentos;
	for(i=0;listaAux != NULL;listaAux = listaAux->prox)
		if(listaAux->ehFinal){
			estadosFinaisAFD[i] = listaAux->estado;
			i++;
		}

	printf("     \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	printf("     \xba                           AUTOMATO AFD                          \xba\n");
	printf("     \xba                                                                 \xba\n");
	printf("     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");


	printf("%20c Estado(s) :{",' ');
	for(i = 0;i < qtdEstadosAFD; i++){
		if(buscarVet(estadosAFD[i],estadosFinaisAFD,qtdEstadosFinaisAFD) != -1){
			printf("(%c)",estadosAFD[i]);
		}else if(estadosAFD[i] == listaFechamentos->estado){
			printf("%c*",estadosAFD[i]);
		}else{
			printf("%c",estadosAFD[i]);
		}
		if((i+1) != qtdEstadosAFD)
			printf(",");
	}
	printf("}\n");


	printf("%20c Estado Inicial : %c\n",' ',listaFechamentos->estado);


	printf("%20c Estado(s) Finai(s) :{",' ');
	for(i = 0;i < qtdEstadosFinaisAFD; i++){
		printf("%c",estadosFinaisAFD[i]);
		if((i+1) != qtdEstadosFinaisAFD)
			printf(",");
	}
	printf("}\n\n");


	printf("%20c &  ",' ');
	for(i=0;i<qtdAlfabeto-1;i++){
		printf("    %c    ",vetAlfabeto[i]);
	}
	printf("\n");

	for (i = 0; i < qtdEstadosAFD; ++i){
		printf("%20c %c ||",' ',estadosAFD[i]);
		for (j = 0; j < qtdAlfabeto-1; ++j) {
			printf("   %c   |",transDeter[i][j]);
		}
		printf("|\n");

	}




	free(vet);

	for(i = 0; i < qtdEstados;i++)
		for(j = 0; j < qtdAlfabeto;j++){
			free(transicao[i][j]);
		}

	for(;listaFechamentos != NULL;listaFechamentos = listaFechamentos->prox){
		free(listaFechamentos->endLista);
		free(listaFechamentos);
	}

	if(selecao){
		//minimizacao(transDeter,estadosAFD,alfabetoAFD,estadosFinaisAFD,estadoInicial);
	}else{

		printf("\n\nENTER para continuar...");
		getchar();
		system("cls");
	}

}



void leituraDeEstadosAltomatica(){

	/*
	 * Dados a serem modificados na alimentacao de automatos diferentes :
	 * estadoInicial
	 * vetAlfabeto
	 * vetEstados
	 * vetEstadosFinais
	 * qtdEstados
	 * qtdAlfabeto
	 * qtdEstadosFinais
	 * transicoes da matriz transicao[][]
	 */

	char gerarEstadoInicial = 'I';

	int i,j,k;

	for(i=0;i < 50;i++)
		for(j=0;j < 50;j++)
			transicao[i][j] = NULL;


	/*
	char estadoInicial = 'F';
	char vetAlfabeto[50] = "01e";
	char vetEstados[50] = "ABCDEFG";
	char vetEstadosFinais[50] = "CE";
	qtdAlfabeto = 3;
	qtdEstados = 7;
	qtdEstadosFinais = 2;

	insereLista('A',&transicao[0][0]);//A,0
	insereLista('B',&transicao[0][0]);//A,0
	insereLista('A',&transicao[0][1]);//A,1
	insereLista('A',&transicao[0][2]);//A,e

	insereLista('C',&transicao[1][0]);//B,0
	insereLista('C',&transicao[1][1]);//B,1
	insereLista('B',&transicao[1][2]);//B,e

	insereLista('C',&transicao[2][2]);//C,e

	insereLista('E',&transicao[3][0]);//D,0
	insereLista('E',&transicao[3][1]);//D,1
	insereLista('D',&transicao[3][2]);//D,e

	insereLista('E',&transicao[4][2]);//E,e

	insereLista('A',&transicao[5][2]);//F,e
	insereLista('G',&transicao[5][2]);//F,e
	insereLista('F',&transicao[5][2]);//F,e

	insereLista('G',&transicao[6][0]);//G,0
	insereLista('G',&transicao[6][1]);//G,1
	insereLista('D',&transicao[6][1]);//G,1
	insereLista('G',&transicao[6][2]);//G,e
	 */



	char estadoInicial = 'A';
	char vetAlfabeto[50] = "01e";
	char vetEstados[50] = "ABCDEFGHIJKLMNOPQR";
	char vetEstadosFinais[50] = "R";
	qtdAlfabeto = 3;
	qtdEstados = 18;
	qtdEstadosFinais = 1;

	insereLista('B',&transicao[0][2]);//A
	insereLista('J',&transicao[0][2]);
	insereLista('A',&transicao[0][2]);

	insereLista('C',&transicao[1][2]);//B
	insereLista('G',&transicao[1][2]);
	insereLista('B',&transicao[1][2]);

	insereLista('D',&transicao[2][0]);//C
	insereLista('C',&transicao[2][2]);

	insereLista('E',&transicao[3][2]);//D
	insereLista('D',&transicao[3][2]);

	insereLista('F',&transicao[4][0]);//E
	insereLista('E',&transicao[4][2]);

	insereLista('I',&transicao[5][2]);//F
	insereLista('F',&transicao[5][2]);

	insereLista('H',&transicao[6][1]);//G
	insereLista('G',&transicao[6][2]);

	insereLista('I',&transicao[7][2]);//H
	insereLista('H',&transicao[7][2]);

	insereLista('B',&transicao[8][2]);//I
	insereLista('J',&transicao[8][2]);

	insereLista('K',&transicao[9][2]);//J
	insereLista('J',&transicao[9][2]);

	insereLista('L',&transicao[10][2]);//K
	insereLista('N',&transicao[10][2]);
	insereLista('K',&transicao[10][2]);

	insereLista('M',&transicao[11][0]);//L
	insereLista('L',&transicao[11][2]);

	insereLista('R',&transicao[12][2]);//M
	insereLista('M',&transicao[12][2]);

	insereLista('O',&transicao[13][1]);//N
	insereLista('N',&transicao[13][2]);

	insereLista('P',&transicao[14][2]);//O
	insereLista('O',&transicao[14][2]);

	insereLista('Q',&transicao[15][1]);//P
	insereLista('P',&transicao[15][2]);

	insereLista('R',&transicao[16][2]);//Q
	insereLista('Q',&transicao[16][2]);

	insereLista('R',&transicao[17][2]);//R



	/*
 	char estadoInicial = 'A';
	char vetAlfabeto[50] = "01e";
	char vetEstados[50]= "AB";
	char vetEstadosFinais[50] = "B";
	qtdAlfabeto = 3;
	qtdEstados = 2;
	qtdEstadosFinais = 1;

	insereLista('A',&transicao[0][0]);//R
	insereLista('B',&transicao[0][0]);//R
	insereLista('A',&transicao[0][1]);//R
	insereLista('A',&transicao[0][2]);//R

	insereLista('B',&transicao[1][2]);//R
	 */



	/*
	char estadoInicial = 'A';
	char vetAlfabeto[50] = "01e";
	char vetEstados[50]= "ABCDEF";
	char vetEstadosFinais[50] = "F";
	qtdAlfabeto = 3;
	qtdEstados = 6;
	qtdEstadosFinais = 1;

	insereLista('A',&transicao[0][0]);
	insereLista('B',&transicao[0][2]);
	insereLista('A',&transicao[0][2]);

	insereLista('B',&transicao[1][0]);
	insereLista('C',&transicao[1][2]);
	insereLista('B',&transicao[1][2]);

	insereLista('C',&transicao[2][0]);
	insereLista('D',&transicao[2][2]);
	insereLista('C',&transicao[2][2]);

	insereLista('D',&transicao[3][0]);
	insereLista('E',&transicao[3][2]);
	insereLista('D',&transicao[3][2]);

	insereLista('E',&transicao[4][0]);
	insereLista('F',&transicao[4][2]);
	insereLista('E',&transicao[4][2]);

	insereLista('F',&transicao[5][0]);
	insereLista('A',&transicao[5][2]);
	insereLista('F',&transicao[5][2]);
	 */



	imprimeEstados(vetEstados,vetAlfabeto,vetEstadosFinais,qtdEstadosFinais,estadoInicial);


	struct noEstado *lista = NULL;
	fechamento(estadoInicial,vetEstados,vetAlfabeto,&lista);

	struct passoConv *listaDeFechamentos = NULL;

	insereListaNaLista(gerarEstadoInicial,'x',-1,vetEstadosFinais,lista,&listaDeFechamentos,0);

	struct passoConv *listaConvAux = listaDeFechamentos;
	struct passoConv *listaConvBusca = listaDeFechamentos;

	struct passoConv *listaRepetida = NULL;

	for(i=1,k=0;listaConvAux != NULL;listaConvAux = listaConvAux->prox,k++){

		for(j =0;j < qtdAlfabeto-1 && listaConvAux->ehRepetida == 0;j++,i++){

			lista = mov(j,vetEstados,vetAlfabeto,listaConvAux->endLista);

			listaRepetida = buscarConv(listaConvBusca,lista);
			if(!listaRepetida){
				insereListaNaLista(gerarEstadoInicial+i,gerarEstadoInicial+k,j,vetEstadosFinais,lista,&listaConvAux->prox,0);
			}else{
				insereListaNaLista(listaRepetida->estado,gerarEstadoInicial+k,j,vetEstadosFinais,NULL,&listaConvAux->prox,1);

			}

		}

	}

	listaConvAux = listaDeFechamentos;

	imprimeTabelaAFD(listaConvAux,vetAlfabeto);

}


void leituraEstados(){
	char gerarEstadoInicial = 'A';
	char vetEstadosFinais[50];
	char vetAlfabeto[50];
	char vetEstados[50];
	char estadoInicial;
	char c;
	int i,j,k,flag=0;

	for(i=0;i<50;i++){
		vetAlfabeto[i]=vetEstados[i]=vetEstadosFinais[i]='\0';
	}

	for(i=0;; i++){
		printf("Digite o Elemento do Alfabeto, ENTER para terminar:\n");
		imprimeVetorCorrente(i,vetAlfabeto);
		c=getchar();
		if(c == '\n')break;
		getchar();
		if(buscarVet(c,vetAlfabeto,i) == -1){
			vetAlfabeto[i] = c;
		}else{i--;}

		system("cls");
	}
	vetAlfabeto[i] = 'e';
	qtdAlfabeto = ++i;

	printf("\n");
	printf("CONJUNTO DE ELEMENTOS DO ALFABETO: ");imprimeVetor(qtdAlfabeto,vetAlfabeto);
	printf("\n");
	printf("\n");
	printf("ENTER para continuar...");
	getchar();
	system("cls");

	c = '*';

	for(i=0;; i++){
		printf("Digite o Estado, ENTER para terminar:\n");
		imprimeVetorCorrente(i,vetEstados);
		c=getchar();
		if(c == '\n')break;
		getchar();

		if(buscarVet(c,vetEstados,i) == -1){
			vetEstados[i] = c;
		}else{i--;}
		system("cls");
	}
	qtdEstados = i;

	printf("\n");
	printf("CONJUNTO DE ESTADOS: ");imprimeVetor(qtdEstados,vetEstados);
	printf("\n");
	printf("\n");
	printf("ENTER para continuar...");
	getchar();
	system("cls");

	c = '*';

	for(i = 0;;i++){
		printf("CONJUNTO DE ESTADOS: ");
		printf("{");
		for(j = 0;j < qtdEstados; j++){
			flag=1;
			for(k=0;k<qtdEstadosFinais;k++){
				if(vetEstadosFinais[k]==vetEstados[j]){
					printf("(%c)",vetEstados[j]);
					flag=0;
				}
			}
			if(flag){
				printf("%c",vetEstados[j]);
			}
			if((j+1) != qtdEstados)
				printf(",");
		}
		printf("}\n");
		printf("\nDigite o Estado FINAL:\n");
		c=getchar();

		if(c == '\n'){
			if(i==0){printf("Deve existir pelo menos 1 estado FINAL\n");--i;continue; }
			else{
				break;
			}
		}

		getchar();

		if(buscarVet(c,vetEstados,qtdEstados) != -1 && buscarVet(c,vetEstadosFinais,i) == -1){
			vetEstadosFinais[i] = c;
			qtdEstadosFinais++;
		}else {i--;}

		system("cls");
	}

	printf("\n");
	printf("CONJUNTO DE ESTADOS FINAIS: ");imprimeVetor(qtdEstadosFinais,vetEstadosFinais);
	printf("\n");
	printf("\n");
	printf("ENTER para continuar...");
	getchar();
	system("cls");

	flag=0;

	for(;!flag;){
		printf("CONJUNTO DE ESTADOS: ");imprimeVetor(qtdEstados,vetEstados);
		printf("\nDigite o estado Inicial : ");
		scanf("%c%*c", &estadoInicial);
		flag = isEstadoValido(estadoInicial,vetEstados,qtdEstados);
		if(flag==0){
			system("cls");
		}
	}

	printf("\n");
	printf("ESTADO INICIAL DIGITADO : %c",estadoInicial);
	printf("\n");
	printf("\n");
	printf("ENTER para continuar...");
	getchar();
	system("cls");

	for(i=0;i < 50;i++)
		for(j=0;j < 50;j++)
			transicao[i][j] = NULL;

	for(i=0;i<qtdEstados;i++){
		insereLista(vetEstados[i],&transicao[i][qtdAlfabeto-1]);
	}

	c = '*';

	for(i=0;i < qtdEstados;i++){
		for(j=0;j < qtdAlfabeto;j++){
			flag = 0;
			for(;;){

				printf("Digite o Estado da transicao (%c,%c), ENTER para terminar:\n",vetEstados[i],vetAlfabeto[j]);
				imprimiLista(transicao[i][j]);
				c=getchar();

				if(c == '\n')break;
				getchar();

				if(isEstadoValido(c,vetEstados,qtdEstados)){
					if(!buscar(transicao[i][j],c))
						insereLista(c,&transicao[i][j]);
				}
				imprimiLista(transicao[i][j]);
				printf("\n");
				system("cls");
			}
			printf("\n");
			printf("\n");
			printf("\n");
			system("cls");
		}
	}

	for(i=0;i<qtdEstados;i++){
		for(j=0;j<qtdAlfabeto;j++){
			printf("CONJUNTO DE ESTADOS DA TRANSICAO (%c,%c) : ",vetEstados[i],vetAlfabeto[j]);
			imprimiLista(transicao[i][j]);
			printf("\n\n");
		}
	}

	printf("\n");
	printf("\n");
	printf("ENTER para continuar...");
	getchar();
	system("cls");

	imprimeEstados(vetEstados,vetAlfabeto,vetEstadosFinais,qtdEstadosFinais,estadoInicial);


	struct noEstado *lista = NULL;
	fechamento(estadoInicial,vetEstados,vetAlfabeto,&lista);

	struct passoConv *listaDeFechamentos = NULL;

	insereListaNaLista(gerarEstadoInicial,'x',-1,vetEstadosFinais,lista,&listaDeFechamentos,0);

	struct passoConv *listaConvAux = listaDeFechamentos;
	struct passoConv *listaConvBusca = listaDeFechamentos;

	struct passoConv *listaRepetida = NULL;

	for(i=1,k=0;listaConvAux != NULL;listaConvAux = listaConvAux->prox,k++){

		for(j =0;j < qtdAlfabeto-1 && listaConvAux->ehRepetida == 0;j++,i++){

			lista = mov(j,vetEstados,vetAlfabeto,listaConvAux->endLista);


			listaRepetida = buscarConv(listaConvBusca,lista);
			if(!listaRepetida){
				insereListaNaLista(gerarEstadoInicial+i,gerarEstadoInicial+k,j,vetEstadosFinais,lista,&listaConvAux->prox,0);
			}else{
				insereListaNaLista(listaRepetida->estado,gerarEstadoInicial+k,j,vetEstadosFinais,NULL,&listaConvAux->prox,1);
			}

		}

	}

	listaConvAux = listaDeFechamentos;

	imprimeTabelaAFD(listaConvAux,vetAlfabeto);

}

void marcaListaAcusados(struct lstAcusados *listaAcusados){
	struct lstAcusados *listaAcusadosAux=listaAcusados;

	while(listaAcusadosAux!=NULL){
		marcaDois(listaAcusadosAux->par);

		listaAcusadosAux=listaAcusadosAux->prox;
	}
}

void marcaDois(struct parEstado *parAux){
	if(parAux!=NULL && parAux->marcado==0){
		parAux->marcado=2;
	}

	if(parAux->acusado!=NULL){
		marcaListaAcusados(parAux->acusado);
	}

	return;
}

void minimizacao(char matrizAFD[50][50],char *vetEstados,char *vetAlfabeto,char *vetEstadosFinais,char estadoInicial){

	struct parEstado *par = NULL;
	int linha,coluna;
	qtdAlfabeto = 2;

	for(linha = 0;linha < qtdEstados;linha++){
		for(coluna = 1;coluna < qtdEstados;coluna++){

			if(linha < coluna){
				insereListaParEstado(vetEstados[linha],vetEstados[coluna],NULL,0,&par);
			}
		}
	}


	struct parEstado *parAux = par;

	for(;parAux != NULL; parAux = parAux->prox){

		if( (buscarVet(parAux->estado1,vetEstadosFinais,qtdEstadosFinais) == -1 && //se estado1 nao eh final
				buscarVet(parAux->estado2,vetEstadosFinais,qtdEstadosFinais) != -1 ) || //se estado2 eh final
				(buscarVet(parAux->estado1,vetEstadosFinais,qtdEstadosFinais) != -1 && // se estado1 eh final
						buscarVet(parAux->estado2,vetEstadosFinais,qtdEstadosFinais) == -1) ){ //se estado2 nao eh final

			parAux->marcado = 1;
		}
	}

	parAux = par;
	for(linha = 0;parAux != NULL; parAux = parAux->prox,linha++){

		if(parAux->marcado == 1)continue;

		for (coluna = 0;coluna < qtdAlfabeto;coluna++) {
			char estadoTemp1,estadoTemp2;
			struct parEstado *parEstadoBusca = NULL;

			int linhaEstado1 = buscarVet(parAux->estado1,vetEstados,qtdEstados);
			estadoTemp1 = matrizAFD[linhaEstado1][coluna];

			int linhaEstado2 = buscarVet(parAux->estado2,vetEstados,qtdEstados);
			estadoTemp2 = matrizAFD[linhaEstado2][coluna];

			if(estadoTemp1 != estadoTemp2){
				parEstadoBusca = buscarListaParEstado(par,estadoTemp1,estadoTemp2);
				if(parEstadoBusca == NULL){


					printf("[%c , %c]\n",estadoTemp1,estadoTemp2);
				}

				if(parEstadoBusca->marcado == 1){
					marcaDois(parAux);
				}else {

					if(parEstadoBusca->marcado == 1){// || parEstadoBusca->marcado == 2
						if(parAux->acusado == NULL)
							parAux->marcado = 2;
					}else{
						if(parEstadoBusca->marcado == 0){
							insereListaAcusados(parAux,&parEstadoBusca->acusado);
						}
					}
				}
			}
		}

	}



	printf("\n");
	printf("\n");


	imprimeTabelaAFDMinimizado(par,vetEstados);

	imprimeAFDMinimizado(par,vetEstados,vetAlfabeto,matrizAFD,vetEstadosFinais,estadoInicial);


}

char verificaIgualdade(char c,struct parEstado *par,char *vetorParalelo){

	struct parEstado *parAux = par;
	int i;

	for(i = 0;parAux != NULL;parAux = parAux->prox,i++){

		if(parAux->marcado == 0 && (c == parAux->estado1 || c == parAux->estado2) && vetorParalelo[i] != '-'){
			return vetorParalelo[i];
		}
	}

	return '-';

}

/*void marcaFinal(char a,char b,char c,char d,char *vetFinal){

	int pos=0;

	if((pos = buscarVet(a,vetFinal,qtdEstadosFinais)) != -1){
		vetFinal[pos] = a;
	}else if((pos = buscarVet(b,vetFinal,qtdEstadosFinais)) != -1){

		if(buscarVet(a,vetFinal,qtdEstadosFinais) == -1){
			vetFinal[pos] = a;
		}
	}else if((pos = buscarVet(c,vetFinal,qtdEstadosFinais)) != -1){

		if(buscarVet(a,vetFinal,qtdEstadosFinais) == -1){
			vetFinal[pos] = a;
		}
	}else if((pos = buscarVet(d,vetFinal,qtdEstadosFinais)) != -1){

		if(buscarVet(a,vetFinal,qtdEstadosFinais) == -1){
			vetFinal[pos] = a;
		}
	}

}*/

void geraAutomato(char *vetEstados,char *vetAfabeto,char *vetEstadosFinais,char estadoInicial,char matrizTransicao[50][50]){


/*	char vetEstados[50] = "RS";
	char vetAfabeto[50] = "01";
	char vetEstadosFinais[50] = "S";
	char estadoInicial = 'R';
	char matrizTransicao[50][50];
	char cadeia[50] = "1010100";

	int qtdEstados = 2;
	int qtdAlfabeto = 2;
	int qtdEstadosFinais = 1;
	int i=0;
	int j=0;
	int cont = 0;

	matrizTransicao[0][0] = 'S';
	matrizTransicao[0][1] = 'R';

	matrizTransicao[1][0] = 'S';
	matrizTransicao[1][1] = 'R';


 */

/*	char vetEstados[50] = "ABCDEF";
	char vetAfabeto[50] = "01";
	char vetEstadosFinais[50] = "CDE";
	char estadoInicial = 'A';
	char matrizTransicao[50][50];
	char cadeia[50] = "10000";

	int qtdEstados = 6;
	int qtdAlfabeto = 2;
	int qtdEstadosFinais = 3;

	matrizTransicao[0][0] = 'B';
	matrizTransicao[0][1] = 'C';

	matrizTransicao[1][0] = 'A';
	matrizTransicao[1][1] = 'D';

	matrizTransicao[2][0] = 'E';
	matrizTransicao[2][1] = 'F';

	matrizTransicao[3][0] = 'E';
	matrizTransicao[3][1] = 'F';

	matrizTransicao[4][0] = 'E';
	matrizTransicao[4][1] = 'F';

	matrizTransicao[5][0] = 'F';
	matrizTransicao[5][1] = 'F';


	*/

	char cadeia[50] = "10000";
	int i=0;
	int j=0;
	int cont = 0;

	for(i = 0;cadeia[i] != '\0';i++,cont++);


	printf("%i",cont);


	FILE *arq = fopen("fonte.c","wt");

	if (arq==NULL) return;

	fprintf(arq,"#include<stdio.h> \n\n");

	fprintf(arq,"int AFD(char *c,int tam,char *vetFinais,int qtdEstadosFinais,char *vetEstados,int qtdEstados);\n");
	fprintf(arq,"int buscarVet(char c,char *vetor,int tam);\n\n");

	fprintf(arq,"int main(){ \n\n");

	fprintf(arq,"	char vetEstados[50] = \"%s\";\n",vetEstados);
	fprintf(arq,"	int qtdEstados = %i;\n",qtdEstados);
	fprintf(arq,"	char cadeia[50] = \"%s\";\n",cadeia);
	fprintf(arq,"	char vetFinais[50] = \"%s\";\n",vetEstadosFinais);
	fprintf(arq,"	int qtdEstadosFinais = %i;\n",qtdEstadosFinais);

	fprintf(arq,"	int i = 0;\n");
	fprintf(arq,"	int tam = 0;\n");
	fprintf(arq,"	int posAceitacao = 0;\n\n");
	fprintf(arq,"	for(i = 0;cadeia[i] != '\\0';i++,tam++);\n\n");

	fprintf(arq,"	posAceitacao = AFD(cadeia,tam,vetFinais,qtdEstadosFinais,vetEstados,qtdEstados);\n");
	fprintf(arq,"	printf(\"%%i\",posAceitacao);\n\n");

	fprintf(arq,"return 0;\n");
	fprintf(arq,"}\n\n\n");

	fprintf(arq,"int AFD(char *c,int tam,char *vetFinais,int qtdEstadosFinais,char *vetEstados,int qtdEstados){\n\n");


	fprintf(arq,"	char estado = '%c';\n",estadoInicial);
	fprintf(arq,"	int i = 0;\n\n");

	fprintf(arq,"	for(;;){\n\n");

	fprintf(arq,"		switch(estado){\n");

	for(i = 0;i < qtdEstados;i++){

	fprintf(arq,"			case '%c':\n\n",vetEstados[i]);

	fprintf(arq,"				switch(c[i]){\n");

		for(j = 0;j < qtdAlfabeto;j++){

	fprintf(arq,"					case '%c':{\n",vetAfabeto[j]);

	fprintf(arq,"						estado = '%c'; \n",matrizTransicao[i][j]);
	fprintf(arq,"						i++; \n");
	//fprintf(arq,"						if(i == tam)\n");
	//fprintf(arq,"							return '%c';\n",matrizTransicao[i][j]);

	fprintf(arq,"					break;\n");
	fprintf(arq,"					}\n\n");

		}
	fprintf(arq,"					case '\\0':\n");
	fprintf(arq,"						return 0;\n");

	fprintf(arq,"					default:\n");
	fprintf(arq,"						return 0;\n");
	fprintf(arq,"					break;\n");

	fprintf(arq,"				}\n\n");
	fprintf(arq,"			break;\n\n");

	}

	fprintf(arq,"			default:\n");
	fprintf(arq,"				return 0;\n");
	fprintf(arq,"			break;\n\n");

	fprintf(arq,"		}\n\n");
	fprintf(arq,"		if(i == tam)\n");
	fprintf(arq,"		break;\n");
	fprintf(arq,"	}\n\n");

	fprintf(arq,"	if(buscarVet(estado,vetFinais,qtdEstadosFinais) != -1){;\n");
	fprintf(arq,"		return buscarVet(estado,vetEstados,qtdEstados)+1;\n");
	fprintf(arq,"	}else{\n");
	fprintf(arq,"		return -buscarVet(estado,vetEstados,qtdEstados)+1;\n");
	fprintf(arq,"	}\n\n");

	fprintf(arq,"}\n\n");

	fprintf(arq,"int buscarVet(char c,char *vetor,int tam){\n");
	fprintf(arq,"	int i;\n");
	fprintf(arq,"	for(i=0;i < tam;i++){\n");
	fprintf(arq,"	if(vetor[i] == c)\n");
	fprintf(arq,"		return i;\n");
	fprintf(arq,"	}\n");
	fprintf(arq,"	return -1;\n");
	fprintf(arq,"}\n");


}

void imprimeAFDMinimizado(struct parEstado *par,char *vetEstados,char *vetAlfabeto,char matrizAFD[50][50],char *vetEstadosFinais,char estadoInicial){

	struct parEstado *parAux = par;
	struct noEstado *equivalentes = NULL;



	//imprimiListaParEstado(parAux);

	int i,j,size=0;
	char *vetorParalelo;
	char *vetMinimizado;
	char *vetFinalMinimizado;
	char matrizMinimizada[50][50];
	char estadoInicialMinimizado = '\0';
	int qtdVetMinimizado = 0;
	int qtdVetFinalMinimizado = 0;

	if(parAux == NULL)return;

	size = contaElementosListaParEstado(parAux);

	vetorParalelo = (char*) malloc(size*sizeof(char*));

	vetMinimizado = (char*) malloc(qtdEstados*sizeof(char*));

	vetFinalMinimizado = (char*) malloc(qtdEstadosFinais*sizeof(char*));



	for(i=0;i < qtdEstadosFinais;i++){
		vetFinalMinimizado[i] = '\0';
	}


	for(i=0;i < size;i++){
		vetorParalelo[i] = '-';
	}

	for(j=0;parAux != NULL;parAux = parAux->prox,j++){ //Percorre a lista pela primeira vez

		if(parAux->marcado == 0){ // so entra se nao estiver marcado
			struct parEstado *parBusca = parAux;
			char a,b;
			a = parAux->estado1;
			b = parAux->estado2;
			for(i=j;parBusca != NULL;parBusca = parBusca->prox,i++){ //Percorre a lista pela segunda vez pra buscar as igualdades

				if(parBusca->marcado == 0){
					if((a == parBusca->estado1 || a == parBusca->estado2 ||
							b == parBusca->estado1 || b == parBusca->estado2) && vetorParalelo[i] == '-'){ // se encontra algum igual e o vetor paralelo na posicao corrente nao estiver marcado deve-se inserir o elemento no vetor
						vetorParalelo[i] = a;
						insereLista(parBusca->estado1,&equivalentes);// insere os equivalentes para busca
						insereLista(parBusca->estado2,&equivalentes);

					}
				}
			}
		}
	}


/*	printf("\n");
	printf("\n");

	for(i=0;i < size;i++){
		printf("%c,",vetorParalelo[i]);
	}*/
	printf("\n");
	printf("\n");


	parAux = par;

	for(i=0,j=0;parAux != NULL;parAux = parAux->prox,j++){//percorre a lista para preencher o vetor Final

		if(parAux->marcado == 0){
			if(buscarVet(vetorParalelo[j],vetMinimizado,i) == -1){// se nao estiver marcado usa-se o elemento do vetor paralelo
				vetMinimizado[i] = vetorParalelo[j];
				i++;
			}
		}else{// se estiver marcado

			if( (buscarVet(parAux->estado1,vetMinimizado,i) == -1) && (buscar(equivalentes,parAux->estado1)  == 0) ){//Estado 1 ->nao inserir elemento repetido e so insere elemento que NAO tem na lista de EQUIVALENTES
				vetMinimizado[i] = parAux->estado1;
				i++;
			}

			if( (buscarVet(parAux->estado2,vetMinimizado,i) == -1) && (buscar(equivalentes,parAux->estado2)  == 0) ){//Estado 2 ->nao inserir elemento repetido e so insere elemento que NAO tem na lista de EQUIVALENTES

				vetMinimizado[i] = parAux->estado2;
				i++;
			}
		}
	}
	qtdVetMinimizado = i;

	ordenaVetor(vetMinimizado,qtdVetMinimizado);// ordena o vetor

	printf("\n");
	printf("     \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	printf("     \xba                         AFD MINIMIDADO                          \xba\n");
	printf("     \xba                                                                 \xba\n");
	printf("     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	printf("\n");

	for(i = 0;i < qtdEstadosFinais;i++){
		char c = verificaIgualdade(vetEstadosFinais[i],par,vetorParalelo);
		if(c == '-'){
			if(buscarVet(vetEstadosFinais[i],vetFinalMinimizado,i) == -1){
				vetFinalMinimizado[i] = vetEstadosFinais[i];
				qtdVetFinalMinimizado++;
			}
		}else{
			if(buscarVet(c,vetFinalMinimizado,i) == -1){
				vetFinalMinimizado[i] = c;
				qtdVetFinalMinimizado++;
			}
		}
	}

	char c = verificaIgualdade(estadoInicial,par,vetorParalelo);
	if(c == '-'){
		estadoInicialMinimizado = estadoInicial;
	}else{
		estadoInicialMinimizado = c;
	}


	printf("%10c Estado(s) :{",' ');
	for(i = 0;i < qtdVetMinimizado; i++){

		if(buscarVet(vetMinimizado[i],vetFinalMinimizado,qtdVetFinalMinimizado) != -1 && vetMinimizado[i] == estadoInicialMinimizado){
			printf("(%c)*",vetMinimizado[i]);
		}else if(vetMinimizado[i] == estadoInicialMinimizado){
			printf("%c*",vetMinimizado[i]);
		}else if(buscarVet(vetMinimizado[i],vetFinalMinimizado,qtdVetFinalMinimizado) != -1){
			printf("(%c)",vetMinimizado[i]);
		}else{
			printf("%c",vetMinimizado[i]);
		}

		if((i+1) != qtdVetMinimizado)
			printf(",");
	}
	printf("}\n");


	printf("\n");


	for(i=0;i < qtdVetMinimizado;i++){
		int pos;
		pos = buscarVet(vetMinimizado[i],vetEstados,qtdEstados);

		for(j=0;j < qtdAlfabeto;j++){
			char c = verificaIgualdade(matrizAFD[pos][j],par,vetorParalelo);
			if( c == '-' ){
				matrizMinimizada[i][j] = matrizAFD[pos][j];
			}else{
				matrizMinimizada[i][j] = c;
			}
		}
	}





/*	for(i=0;i < qtdVetFinalMinimizado;i++){
		printf("%c,",vetFinalMinimizado[i]);
	}*/


	printf("\n");
	printf("\n");
	printf("     \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	printf("     \xba               TABELA DE TRANSICAO AFD MINIMIDADO                \xba\n");
	printf("     \xba                                                                 \xba\n");
	printf("     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	printf("\n");


	printf("%12c& ",' ');
	for(i = 0;i < qtdAlfabeto;i++){
		printf("  %c  ",vetAlfabeto[i]);
	}
	printf("\n");
	for(i = 0; i < qtdVetMinimizado;i++){
		printf("%12c|",vetMinimizado[i]);
		for(j = 0;j < qtdAlfabeto;j++){
			printf("| %c |",matrizMinimizada[i][j]);
		}
		printf("\n");
	}



	for(i=0;vetFinalMinimizado[i] != '\0';i++){
		printf("%c|",vetFinalMinimizado[i]);
	}
	printf("\n");
	for(i=0;i < qtdVetFinalMinimizado;i++){
		printf("%c/",vetFinalMinimizado[i]);
	}


	char *vetFinaisMinimizado;
	vetFinaisMinimizado = (char*) malloc(qtdVetFinalMinimizado*sizeof(char*));
	for(i=0;i < qtdVetFinalMinimizado;i++)
		vetFinaisMinimizado[i] = '\0';

	for(i=0;i < qtdVetFinalMinimizado;i++)
		vetFinaisMinimizado[i] = vetFinalMinimizado[i];

	geraAutomato(vetMinimizado,vetAlfabeto,vetFinaisMinimizado,estadoInicial,matrizMinimizada);



	printf("\n");
	printf("ENTER para continuar...");
	getchar();
	system("cls");

	free(vetMinimizado);
	free(vetorParalelo);

	for(;par != NULL;){
		struct parEstado *parX = par;
		par = par->prox;
		free(parX);
	}

	for(;equivalentes != NULL;){
		struct noEstado *noX = equivalentes;
		equivalentes = equivalentes->prox;
		free(noX);
	}
}


void imprimeTabelaAFDMinimizado(struct parEstado *par,char *vetEstados){

	struct parEstado *parAux = par;
	int linha,coluna;

	int matEstado[qtdEstados-1][qtdEstados-1];//qtdEst -1

	for(linha = 0;linha < qtdEstados-1;linha++)
		for(coluna = 0;coluna < qtdEstados-1;coluna++)
			matEstado[linha][coluna] = '\0';


	for(coluna = 0; coluna < qtdEstados-1;coluna++){
		for(linha = 0; linha < qtdEstados-1;linha++){
			if(linha >= coluna){
				matEstado[linha][coluna] = parAux->marcado;
				parAux = parAux->prox;
			}
		}
	}

	int delim=1;

	printf("     \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	printf("     \xba                        TABELA MINIMIZACAO                       \xba\n");
	printf("     \xba                                                                 \xba\n");
	printf("     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

	for(coluna = 0;coluna < qtdEstados-1;coluna++,delim++){
		for(linha = 0;linha < qtdEstados-1;linha++){

			if(linha <= coluna){
				if(linha == 0){
					printf("            %c | %i |",vetEstados[delim],matEstado[coluna][linha]);
				}else{
					printf("| %i |",matEstado[coluna][linha]);
				}
			}
		}
		printf("\n");
	}
	printf("              ");
	for(linha = 0;linha < qtdEstados-1;linha++)
		printf("  %c  ",vetEstados[linha]);

	printf("\n");
	printf("\n");



	//imprime lista de acusados
	printf("     \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	printf("     \xba                   LISTAS QUE CONTEM ACUSADOS                    \xba\n");
	printf("     \xba                                                                 \xba\n");
	printf("     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

	parAux = par;
	for(;parAux != NULL;parAux = parAux->prox){

		struct lstAcusados *lstAux = parAux->acusado;
		if(lstAux != NULL)printf("           {%c,%c} = ",parAux->estado1/*lstAux->par->estado1*/,parAux->estado2/*lstAux->par->estado2*/);

		for(;lstAux != NULL;lstAux = lstAux->prox){

			if(lstAux->prox == NULL){
				printf("{%c,%c} ;\n",lstAux->par->estado1,lstAux->par->estado2);
			}else{
				printf("{%c,%c} ->",lstAux->par->estado1,lstAux->par->estado2);
			}
		}

	}


	//libera memoria

	parAux = par;
	for(;parAux != NULL;parAux = parAux->prox){

		struct lstAcusados *lstAux = parAux->acusado;

		free(lstAux);

	}
	free(parAux);

}


void alimentacaoAltomaticaAFD(){

	char estadoInicial = 'A';
	char vetAlfabeto[50] = "01";
	char matrizAFD[50][50];
	qtdAlfabeto = 2;
	qtdEstados = 6;
	qtdEstadosFinais = 3;
	char vetEstados[50];
	char vetEstadosFinais[50];
	int opcao=50;

	while(opcao){

		printf("     \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
		printf("     \xba               ESCOLHA DE AUTOMATO PARA MINIMIZACAO              \xba\n");
		printf("     \xba                                                                 \xba\n");
		printf("     \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
		printf("     \xba  (1) - EXERCICIO 1                                              \xba\n");
		printf("     \xba  (2) - EXERCICIO 2                                              \xba\n");
		printf("     \xba  (3) - EXERCICIO 3                                              \xba\n");
		printf("     \xba  (4) - EXERCICIO DA PROVA                                       \xba\n");
		printf("     \xba  (5) - EXERCICIO 5                                              \xba\n");
		printf("     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

		printf("OPCAO :");
		scanf("%d",&opcao);
		getchar();
		system("cls");

		switch (opcao) {
		case 1:{
			vetEstados[0] = 'A';
			vetEstados[1] = 'B';
			vetEstados[2] = 'C';
			vetEstados[3] = 'D';
			vetEstados[4] = 'E';
			vetEstados[5] = 'F';

			vetEstadosFinais[0] = 'A';
			vetEstadosFinais[1] = 'E';
			vetEstadosFinais[2] = 'F';

			matrizAFD[0][0] = 'C';//A,0
			matrizAFD[0][1] = 'B';//A,1

			matrizAFD[1][0] = 'B';//B,0
			matrizAFD[1][1] = 'A';//B,1

			matrizAFD[2][0] = 'E';//C,0
			matrizAFD[2][1] = 'F';//C,1

			matrizAFD[3][0] = 'F';//D,0
			matrizAFD[3][1] = 'E';//D,1

			matrizAFD[4][0] = 'D';//E,0
			matrizAFD[4][1] = 'C';//E,1

			matrizAFD[5][0] = 'C';//F,0
			matrizAFD[5][1] = 'D';//F,1

			opcao=0;
			break;
		}
		case 2:{
			vetEstados[0] = 'A';
			vetEstados[1] = 'B';
			vetEstados[2] = 'C';
			vetEstados[3] = 'D';
			vetEstados[4] = 'E';
			vetEstados[5] = 'F';

			vetEstadosFinais[0] = 'C';
			vetEstadosFinais[1] = 'D';
			vetEstadosFinais[2] = 'E';

			matrizAFD[0][0] = 'B';//A,0
			matrizAFD[0][1] = 'C';//A,1

			matrizAFD[1][0] = 'A';//B,0
			matrizAFD[1][1] = 'D';//B,1

			matrizAFD[2][0] = 'E';//C,0
			matrizAFD[2][1] = 'F';//C,1

			matrizAFD[3][0] = 'E';//D,0
			matrizAFD[3][1] = 'F';//D,1

			matrizAFD[4][0] = 'E';//E,0
			matrizAFD[4][1] = 'F';//E,1

			matrizAFD[5][0] = 'F';//F,0
			matrizAFD[5][1] = 'F';//F,1

			opcao=0;
			break;
		}
		case 3:{
			vetEstados[0] = 'A';
			vetEstados[1] = 'B';
			vetEstados[2] = 'C';
			vetEstados[3] = 'D';
			vetEstados[4] = 'E';
			vetEstados[5] = 'X';

			vetEstadosFinais[0] = 'D';
			vetEstadosFinais[1] = 'E';

			matrizAFD[0][0] = 'B';//A,0
			matrizAFD[0][1] = 'X';//A,1

			matrizAFD[1][0] = 'D';//B,0
			matrizAFD[1][1] = 'C';//B,1

			matrizAFD[2][0] = 'E';//C,0
			matrizAFD[2][1] = 'C';//C,1

			matrizAFD[3][0] = 'D';//D,0
			matrizAFD[3][1] = 'C';//D,1

			matrizAFD[4][0] = 'D';//E,0
			matrizAFD[4][1] = 'C';//E,1

			matrizAFD[5][0] = 'X';//X,0
			matrizAFD[5][1] = 'X';//X,1

			opcao=0;
			break;
		}
		case 4:{
			qtdAlfabeto = 2;
			qtdEstados = 8;
			qtdEstadosFinais = 1;

			vetEstados[0] = 'A';
			vetEstados[1] = 'B';
			vetEstados[2] = 'C';
			vetEstados[3] = 'D';
			vetEstados[4] = 'E';
			vetEstados[5] = 'F';
			vetEstados[6] = 'G';
			vetEstados[7] = 'H';

			vetEstadosFinais[0] = 'C';

			matrizAFD[0][0] = 'B';//A,0
			matrizAFD[0][1] = 'F';//A,1

			matrizAFD[1][0] = 'G';//B,0
			matrizAFD[1][1] = 'C';//B,1

			matrizAFD[2][0] = 'A';//C,0
			matrizAFD[2][1] = 'C';//C,1

			matrizAFD[3][0] = 'C';//D,0
			matrizAFD[3][1] = 'G';//D,1

			matrizAFD[4][0] = 'H';//E,0
			matrizAFD[4][1] = 'F';//E,1

			matrizAFD[5][0] = 'C';//F,0
			matrizAFD[5][1] = 'G';//F,1

			matrizAFD[6][0] = 'G';//G,0
			matrizAFD[6][1] = 'E';//G,1

			matrizAFD[7][0] = 'G';//H,0
			matrizAFD[7][1] = 'C';//H,1

			opcao=0;
			break;
		}
		case 5:{
			qtdAlfabeto = 2;
			qtdEstados = 10;
			qtdEstadosFinais = 1;

			vetEstados[0] = 'A';
			vetEstados[1] = 'B';
			vetEstados[2] = 'C';
			vetEstados[3] = 'D';
			vetEstados[4] = 'E';
			vetEstados[5] = 'F';
			vetEstados[6] = 'G';
			vetEstados[7] = 'H';
			vetEstados[8] = 'I';
			vetEstados[9] = 'J';

			vetEstadosFinais[0] = 'J';

			matrizAFD[0][0] = 'B';//A,0
			matrizAFD[0][1] = 'C';//A,1

			matrizAFD[1][0] = 'D';//B,0
			matrizAFD[1][1] = 'E';//B,1

			matrizAFD[2][0] = 'D';//C,0
			matrizAFD[2][1] = 'E';//C,1

			matrizAFD[3][0] = 'F';//D,0
			matrizAFD[3][1] = 'G';//D,1

			matrizAFD[4][0] = 'F';//E,0
			matrizAFD[4][1] = 'G';//E,1

			matrizAFD[5][0] = 'H';//F,0
			matrizAFD[5][1] = 'I';//F,1

			matrizAFD[6][0] = 'H';//G,0
			matrizAFD[6][1] = 'I';//G,1

			matrizAFD[7][0] = 'J';//H,0
			matrizAFD[7][1] = 'I';//H,1

			matrizAFD[8][0] = 'J';//I,0
			matrizAFD[8][1] = 'I';//I,1

			matrizAFD[9][0] = 'J';//J,0
			matrizAFD[9][1] = 'I';//J,1

			opcao=0;
			break;
		}
		default:
			printf("Opcao invalida !!!\n");
			printf("ENTER para continuar...\n\n");
			getchar();
			system("cls");
			opcao=50;
			break;
		}

	}

	minimizacao(matrizAFD,vetEstados,vetAlfabeto,vetEstadosFinais,estadoInicial);

}



/*************************** CORPO DAS FUNCOES PRINCIPAIS END**********************************/

