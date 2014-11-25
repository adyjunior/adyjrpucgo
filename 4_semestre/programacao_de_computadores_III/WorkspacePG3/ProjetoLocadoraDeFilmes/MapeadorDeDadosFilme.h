/*
 * MapeadorDeDadosFilmes.h
 *
 *  Created on: 11/12/2010
 *      Author: RafaeL
 */

#ifndef MAPEADORDEDADOSFILME_H_
#define MAPEADORDEDADOSFILME_H_
#include "MapeadorDeDados.h"
#include"ItemPersistencia.h"
#include<string>
#include<iostream>
#include<fstream>
#include"Filme.h"
#include"Iterator.h"

//*******************************************************************************************
//	CLASSE MAPEADOR DE DADOS DO CLIENTE NA PERSISTENCIA
//*******************************************************************************************
class MapeadorDeDadosFilme : public MapeadorDeDados
{
	//Atributos
	private:
		const std::string nomeDoArquivoNoDisco;
public:
	MapeadorDeDadosFilme();
	virtual ~MapeadorDeDadosFilme(){}
	void gravarNoArmazenamento(ItemPersistencia *objeto);
	bool buscarNoArmazenamento(int id,ItemPersistencia *objeto);
	void removerNoArmazenamento(ItemPersistencia *objeto);
	Container::Iterator<Filme*> *listarNoArmazenamento();

};


#endif /* MAPEADORDEDADOSFILMES_H_ */
