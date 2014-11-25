#include "Persistencia.h"
#include "MapeadorDeDadosCliente.h"
#include "MapeadorDeDadosFilme.h"
#include "MapeadorDeDadosLocacao.h"

Persistencia::Persistencia()
{
	try{
		baseDeDados[0] = new MapeadorDeDadosCliente();
		baseDeDados[1] = new MapeadorDeDadosFilme();
		baseDeDados[2] = new MapeadorDeDadosLocacao();
	}catch(std::bad_alloc&){
		throw(9);
	}
}

Persistencia::~Persistencia()
{
	if(baseDeDados[0])delete baseDeDados[0];
	if(baseDeDados[1])delete baseDeDados[1];
	if(baseDeDados[2])delete baseDeDados[2];
}

bool Persistencia::gravar(ItemPersistencia *objeto)
{
	try{
		return baseDeDados[objeto->obterTipoDaClasse()]->gravarDados(objeto);
	}catch(int valorErro){
		throw valorErro;
	}

}

bool Persistencia::recuperar(ItemPersistencia *objeto)
{
	try{
		return baseDeDados[objeto->obterTipoDaClasse()]->recuperarDados(objeto);
	}catch(int valorErro){
		throw valorErro;
	}

}

bool Persistencia::remover(ItemPersistencia *objeto)
{
	try{
		return baseDeDados[objeto->obterTipoDaClasse()]->removerDados(objeto);
	}catch(int valorErro){
		throw valorErro;
	}

}
