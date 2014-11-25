#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_

#include"MapeadorDeDados.h"

class Persistencia
{
	//Atributos
		private:
			MapeadorDeDados  *baseDeDados[3];
	//Metodos
		public:
			Persistencia();
			~Persistencia();
			bool gravar(ItemPersistencia *item);
			bool recuperar(ItemPersistencia *item);
			bool remover(ItemPersistencia *item);

};

Persistencia::Persistencia()
{
	baseDeDados[0] = new MapeadorDeCliente();
		    	//baseDeDados[1] = new MapeadorFilme();
		    	//baseDeDados[2] = new MapeadorLocacao();
}

Persistencia::~Persistencia()
{
				delete baseDeDados[0];
}

bool Persistencia::gravar(ItemPersistencia *item)
{
				 return baseDeDados[item->obterTipoDaClasse()]->gravarDados(item);
}

bool Persistencia::recuperar(ItemPersistencia *item)
{
				 return baseDeDados[item->obterTipoDaClasse()]->recuperarDados(item);
}

bool Persistencia::remover(ItemPersistencia *item)
{
				 return baseDeDados[item->obterTipoDaClasse()]->removerDados(item);
}

#endif /*PERSISTENCIA_H_*/
