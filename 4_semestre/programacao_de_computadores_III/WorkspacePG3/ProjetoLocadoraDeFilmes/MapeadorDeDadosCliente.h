#ifndef MAPEADORDEDADOSCLIENTE_H_
#define MAPEADORDEDADOSCLIENTE_H_

#include "MapeadorDeDados.h"
#include"ItemPersistencia.h"
#include<string>
#include<iostream>
#include<fstream>
#include"Cliente.h"
#include"Iterator.h"


//*******************************************************************************************
//	CLASSE MAPEADOR DE DADOS DO CLIENTE NA PERSISTENCIA
//*******************************************************************************************
class MapeadorDeDadosCliente : public MapeadorDeDados
{
	//Atributos
	private:
		const std::string nomeDoArquivoNoDisco;
public:
	MapeadorDeDadosCliente();
	virtual ~MapeadorDeDadosCliente(){}
	void gravarNoArmazenamento(ItemPersistencia *objeto);
	bool buscarNoArmazenamento(int id,ItemPersistencia *objeto);
	void removerNoArmazenamento(ItemPersistencia *objeto);
	Container::Iterator<Cliente*> *listarNoArmazenamento();

	
};

#endif /*MAPEADORDEDADOSCLIENTE_H_*/
