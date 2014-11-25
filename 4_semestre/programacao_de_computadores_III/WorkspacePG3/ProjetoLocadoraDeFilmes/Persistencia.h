#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_
#include"MapeadorDeDados.h"
#include"ItemPersistencia.h"

class Persistencia
{
	//Atributos
	private:
		MapeadorDeDados *baseDeDados[3];
	//Metodos
	public:
		Persistencia();
		virtual ~Persistencia();
		bool gravar(ItemPersistencia *objeto);
		bool recuperar(ItemPersistencia *objeto);
		bool remover(ItemPersistencia *objeto);
};

#endif /*PERSISTENCIA_H_*/
