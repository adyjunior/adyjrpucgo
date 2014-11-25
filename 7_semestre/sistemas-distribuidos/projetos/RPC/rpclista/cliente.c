#include<stdio.h>
#include <rpc/rpc.h>
#include  <rpc/xdr.h>
#include "lista.h"
/* -----------------------------------------*/ 
/* Programa cliente para teste */  
/* -----------------------------------------*/ 
#define OK 0 
#define ERRO 1

int main()
{
  CLIENT *cl;
 int dado;
 int     valor;
 char  opcao; 
 int  * result;
 char  server[255];
int lixo;
/* le nome do servidor */
 printf(" Entre com o nome do servidor ->");
  scanf("%s",&server);

 /* ---------------------------------------- */ 
/* realiza conexao com o servidor */
/* cria handle do client */
 cl = clnt_create (server, LISTAPROG, LISTAVER, "tcp");
 if ( cl == NULL)
  { /* nao pode estabelecer conexao */
   printf(" Nao consegui estabelecer conexao\n"); 
   clnt_pcreateerror(server);
   exit (1);
   }
 /* ---------------------------------------- */ 

/* incializar lista remota  */ 
 result= ( int * ) init_1(&lixo,cl);
 if ( result == NULL )  { clnt_perror(cl,server); exit(1);} 
 /* ---------------------------------------- */ 
 
printf(" P3\n"); 
do{ 
    printf(" \n\n 1 - Insercao \n 2-remocao \n 3-consulta \n 4-imprima \n  x - sai ->");

    do     scanf("%c",&opcao); 
    while ( opcao != '1' && opcao != '2' && opcao != '3' && opcao !='4' && opcao != 'x');
    switch ( opcao) {
     case '1': /* insercao */ 
		printf(" Valor a inserir ->");
  		scanf("%d",&valor);
  		result = ( int * ) insere_1(&valor,cl); 
                if ( result == NULL )  { clnt_perror(cl,server); exit(1);} 
                if ( * result == ERRO) 
                  printf(" erro na insercao !\n");
                break; 
   case '2': /* remocao */ 
		printf(" Valor a ser removido ->\n");
		scanf("%d",&valor);
  		result = ( int * ) deleta_1(&valor,cl); 
                if ( result == NULL )  { clnt_perror(cl,server); exit(1);} 
		if ( *result == ERRO)
		  printf(" Erro na remocao !\n");
                break;
   case '3': /* consulta */ 
  		printf(" Valor a ser consultado ->");
		scanf("%d",&valor);
  		result = ( int * ) consulta_1(&valor,cl); 
                if ( result == NULL )  { clnt_perror(cl,server); exit(1);} 
         	if ( * result == ERRO )
                   printf(" Valor nao encontrado !\n");
                else 
                   printf(" Valor encontrado !\n");
                break; 
   case '4': /* imprime */
             printf(" Imprime a lista \n");
             result = ( int * ) imprima_1(&lixo,cl); 
             if ( result == NULL )  { clnt_perror(cl,server); exit(1);} 
             break;
   default:    break; }
  }
  while ( opcao != 'x'); 

  /* faz a limpeza de valore alocados ... remove todos os 
     elementos da lista */ 
  return OK; 
}
 


