#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_
#include<string>
#include<iostream>
#include<fstream>
#include"Cliente.h"

//***********************************************************************************
//			CLASSE MAPEADOR DE DADOS DA PERSISTENCIA
//***********************************************************************************

class MapeadorDeDados
{
	//Metodos
		public:
		   MapeadorDeDados() {};
		   virtual ~MapeadorDeDados(){};
			virtual bool gravarDados(ItemPersistencia *item);
			virtual bool recuperarDados(ItemPersistencia *item);
			virtual bool removerDados(ItemPersistencia *item);
			//  criar
		protected:
			virtual void gravarNoArmazenamento(ItemPersistencia *item)=0;
			virtual bool buscarNoArmazenamento(unsigned int id,ItemPersistencia *item) =0;
			virtual void removerNoArmazenamento(ItemPersistencia *item)=0;
};

bool MapeadorDeDados::gravarDados(ItemPersistencia *item)
{
	if(!buscarNoArmazenamento(item->obterIdentificador(),item)) {
		gravarNoArmazenamento(item);
		return true;
	}return false;
}

bool MapeadorDeDados::recuperarDados(ItemPersistencia *item)
{
	if(buscarNoArmazenamento(item->obterIdentificador(),item)) return true;
		else return false;
}

bool MapeadorDeDados::removerDados(ItemPersistencia *item)
{
	if(buscarNoArmazenamento(item->obterIdentificador(),item)){
		removerNoArmazenamento(item);
		return true;
	}
		else return false;
}
