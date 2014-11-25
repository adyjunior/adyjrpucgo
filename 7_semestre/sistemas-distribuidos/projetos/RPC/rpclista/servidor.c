#include<stdio.h>
#include<malloc.h>
#include <rpc/rpc.h>
#include <rpc/xdr.h>
#include "lista.h"

#define OK 0 
#define ERRO 1 
struct no * lista;
int    dados=1;
/* inicializar estruturas do servidor */

int * init_1( res ) 
 int * res;
{
static int result;
  printf(" TESTE INIT_1 \n");
  if (dados==1) 
  { 
   lista=NULL;
   dados=0;
   }
 result=OK;
 printf(" SAIDA INIT_1"); 
return(&result);
}

/* -----------------------------------------*/ 
/* Insere um valor em uma lista */
/* Ordenada */ 
/* -----------------------------------------*/ 

int * insere_1 (valor)
   int * valor;
{
 struct no * aux; 
 struct no * p;  
 struct no * q; 
 static int result;

 /* aloca o espaco para o novo no */  
 if (( aux= (struct no * ) malloc ( sizeof ( struct no)))== NULL)
   {
    result=ERRO;
    return ( &result);
   }
 
 /* faz a atribuicao */ 
  aux->dado = *valor;

 /* verifica se a lista esta vazia */ 
 if ( lista == NULL) 
  {
   lista = aux;
   aux->next = NULL;
   result=OK;
   return (&result); 
  }
 
 /*  faz a pesquisa ate achar o elemento */ 
 p=lista;
 q=p;
 while ( p != NULL ) 
   if ( *valor <= p->dado ) 
    {
     /* verifica se eh insercao no inicio */ 
     if ( p==q)
       lista=aux;
     else
       q->next = aux;
     aux->next = p;
     result=OK;
     return ( &result); 
    } 
    else{
         q = p;
         p = p->next; 
       } 
 
 /* insere no final */
  aux->next = NULL;
  q->next = aux;
  result=OK;
  return ( &result);
}
          
   
/* -----------------------------------------*/ 
/* Remove um valor de uma lista */  
/* -----------------------------------------*/ 

int * deleta_1 (valor)
  int * valor;
{
 struct no *p;
 struct no  *q;
 static int result;

 /* inicio da lista */ 
 p = lista;
 q =p;

 /* faz a pesquisa */ 
 while ( p != NULL ) 
  if ( p->dado == *valor )
   { 
   if ( p == q )  
     lista= p->next; /* primeiro da lista */ 
   else
    q->next = p->next; 

   free( p);
   result=OK;
   return ( &result ) ; 
  } 
   else{ 
       q=p; 
       p = p->next; 
       } 

/* nao pertence a lista  e/ou lista vazia */
 result=ERRO;
 return ( &result ); 
} 

/* -----------------------------------------*/ 
/* Verifica se um dado valor pertence a uma lista */
/* -----------------------------------------*/ 

int  * consulta_1 (valor )
 int * valor;
{
 struct no * p; 
 static int result;

/* pega o header da lista */ 
 printf(" Valor=%d\n", valor);
 p = lista; 
 while ( p != NULL)
   if ( p->dado == *valor )
    { 
     result=OK;
    return (&result);
    }
   else
       p =  p->next; 
/* nao pertence a lista */
 result=1;
 return (&result ) ; /* ou nao pertence */  

}

/* 
 * Imprime a lista 
 *
*/ 
int * imprima_1 ( ) 
{
struct no * p;
static int result;
 printf(" _____________________________________________________________________________\n");
 p = lista; 
 while ( p != NULL ) 
  {
   printf("%d ",p->dado);
   p = p->next;
  }
 printf(" _____________________________________________________________________________\n");
result=OK;
return ( &result);
}


