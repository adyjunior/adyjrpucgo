#ifndef FILME_H_
#define FILME_H_
#include"classeItemPersistencia.h"
#include<string>

//********************************************************************
//                                   Construida e testeda
//********************************************************************

class Filme: public ItemPersistencia
{
	//Atributos
		private:
			std::string titulo;
			int precoDeCompra;
			int precoDeLocacao;
			bool situacao;
	//Metodos
		public:
			Filme(	unsigned int identificador, const std::string &titulo, int precoDeCompra,
							int precoDeLocacao, bool situacao);
			void obter(	unsigned int &identificador, std::string &titulo, int &precoDeCompra,
										int &precoDeLocacao, bool &situacao)const;
			void atribuir(	unsigned int identificador, const std::string &titulo, int precoDeCompra,
											int precoDeLocacao, bool situacao);
			int obterPrecoDeCompra()const{return precoDeCompra;};
			int obterPrecoDeLocacao()const{return precoDeLocacao;};
			bool obterSituacao()const{return situacao;};
			void atribuirSituacao(bool situacao){this->situacao=situacao;};
};

Filme::Filme(	unsigned int identificador, const std::string &titulo, int precoDeCompra,
							int precoDeLocacao, bool situacao):
				ItemPersistencia(identificador),
				titulo(titulo),
				precoDeCompra(precoDeCompra),
				precoDeLocacao(precoDeLocacao),
				situacao(situacao)
{
	tipoDaClasse=1;
}

void Filme::obter(	unsigned int &identificador, std::string &titulo, int &precoDeCompra,
										int &precoDeLocacao, bool &situacao)const
{
	identificador= this->identificador;
	titulo=this->titulo;
	precoDeCompra=this->precoDeCompra;
	precoDeLocacao=this->precoDeLocacao;
	situacao=this->situacao;
}

void Filme::atribuir(	unsigned int identificador, const std::string &titulo, int precoDeCompra,
											int precoDeLocacao, bool situacao)
{
	this->identificador=identificador;
	this->titulo=titulo;
	this->precoDeCompra=precoDeCompra;
	this->precoDeLocacao=precoDeLocacao;
	this->situacao=situacao;
}

#endif /*FILME_H_*/
