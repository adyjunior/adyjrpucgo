#include "Lista.h"

namespace VilaNova {

void Lista::inserir(int tipo){
No* gravar;

	if(primeiro == 0){
	primeiro = new No;
	primeiro->proximo = gravar;
	primeiro->anterior = gravar;
	gravar->anterior = primeiro;
	gravar->proximo = primeiro;
	}
	else{
	if(tipo == 'M'){
	atual = primeiro->proximo;

	while(strcmp(gravar->nome,atual->nome) > 0){
	if(atual != primeiro)
	atual = atual->proximo;
	else
	break;
	}
	anterior = atual->anterior;

	proximo = atual; /* o endereço de atual vai para proximo */

	anterior->proximo = gravar; /* Os dados contidos em "gravar" serão inseridos entre */
	gravar->anterior = anterior; /* as os nodos referencia "anterior" e "proximo" */
	gravar->proximo = proximo;
	proximo->anterior = gravar;
	}
	if(tipo == 'F'){
	anterior = primeiro->anterior;
	proximo = primeiro;

	anterior->proximo = gravar; /* Os dados contidos em "gravar" serão inseridos entre */
	gravar->anterior = anterior; /* as os nodos referencia "anterior" e "proximo" */
	gravar->proximo = proximo;
	proximo->anterior = gravar;
	}
	}



}

}
