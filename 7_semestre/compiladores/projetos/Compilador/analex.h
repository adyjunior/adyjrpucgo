#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#ifndef ANALEX_H_
#define ANALEX_H_

#define CTE_MUDALINHA 12
#define CTE_NUMERO

struct Token{
	char *lexema;
	int tipo;
	struct Token *prox;
	struct Simbolo *simbolo;
};

struct Simbolo{
	struct Token *token;
	int valor;
	struct Simbolo *prox;
};

struct Token *lerArquivo();
int qtdElementosVetor(char *vetor);
void zeraVetor(char *vetor);
void insereLista(char *lexema,int tipo,struct Token **lstInicio,struct Token **lstFim);
int comparaListaSimbolo(char *lexema,struct Simbolo *simbolo);
struct Simbolo * alocaSimbolo(struct Token *token);
void insereListaSimbolo(struct Token *token,struct Simbolo **iniSimb);
int buscarPalavrasReservadasVetStr(char *str,int tam);
int codigoCategoria(int estado,char *lexema);
void separaIdentificadores(struct Simbolo **iniSimb,struct Token **lstTokenIni);
int AFD(char *cadeia,int *pos,char *lexema);
int buscarVet(int c,int *vetor,int tam);
char ehLetra(char c);
char tipoCaractere(char c);
int verificaDefault(char *lexema,char *cadeia,int i,int j,int *pos,int estado);
void separaTokens(char *linha,char *lexema,FILE *entrada,struct Token **lstTokenIni,struct Token **lstTokenFim);
void divideLexemaPorCategoria(struct Token **lstTokenIni,char *lexema);


#endif /* ANALEX_H_ */
