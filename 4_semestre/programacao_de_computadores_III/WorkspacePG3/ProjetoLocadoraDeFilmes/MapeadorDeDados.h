#ifndef MAPEADORDEDADOS_H_
#define MAPEADORDEDADOS_H_
#include"ItemPersistencia.h"

class MapeadorDeDados
{
	//Metodos
	public:
		MapeadorDeDados(){}
		virtual ~MapeadorDeDados(){}
		virtual bool gravarDados(ItemPersistencia *objeto);
		virtual bool recuperarDados(ItemPersistencia *objeto);
		virtual bool removerDados(ItemPersistencia *objeto);

	protected:
		virtual void gravarNoArmazenamento(ItemPersistencia *objeto)=0;
		virtual bool buscarNoArmazenamento(int id,ItemPersistencia *objeto) =0;
		virtual void removerNoArmazenamento(ItemPersistencia *objeto)=0;
};

#endif /*MAPEADORDEDADOS_H_*/


