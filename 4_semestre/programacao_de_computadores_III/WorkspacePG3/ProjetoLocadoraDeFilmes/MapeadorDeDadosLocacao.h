#ifndef MAPEADORDEDADOSLOCACAO_H_
#define MAPEADORDEDADOSLOCACAO_H_

#include "MapeadorDeDados.h"
#include"ItemPersistencia.h"
#include<string>
#include<iostream>
#include<fstream>
#include"Locacao.h"

class MapeadorDeDadosLocacao : public MapeadorDeDados
{
	//Atributos
	private:
		const std::string nomeDoArquivoNoDisco;
public:
	MapeadorDeDadosLocacao();
	virtual ~MapeadorDeDadosLocacao(){}
	void gravarNoArmazenamento(ItemPersistencia *objeto);
	bool buscarNoArmazenamento(int id,ItemPersistencia *objeto);
	void removerNoArmazenamento(ItemPersistencia *objeto);
	
};

#endif /*MAPEADORDEDADOSLOCACAO_H_*/ 
