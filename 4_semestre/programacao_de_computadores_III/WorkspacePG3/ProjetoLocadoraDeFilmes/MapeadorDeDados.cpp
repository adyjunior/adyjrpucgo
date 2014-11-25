#include "MapeadorDeDados.h"

bool MapeadorDeDados::gravarDados(ItemPersistencia *objeto)
{
	try{
		if(!buscarNoArmazenamento(objeto->obterIdentificador(),objeto)) {
			gravarNoArmazenamento(objeto);
			return true;
		}return false;
	}catch(int valorErro){
		throw valorErro;
	}
}

bool MapeadorDeDados::recuperarDados(ItemPersistencia *objeto)
{
	try{
		if(buscarNoArmazenamento(objeto->obterIdentificador(),objeto)) return true;
		else return false;
	}catch(int valorErro){
		throw valorErro;
	}

}

bool MapeadorDeDados::removerDados(ItemPersistencia *objeto)
{
	try{
		if(buscarNoArmazenamento(objeto->obterIdentificador(),objeto)){
			removerNoArmazenamento(objeto);
			return true;
		}
		else return false;
	}catch(int valorErro){
		throw valorErro;
	}

}

