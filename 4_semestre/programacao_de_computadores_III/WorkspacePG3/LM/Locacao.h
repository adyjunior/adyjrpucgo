#ifndef LOCACAO_H_
#define LOCACAO_H_
#include"ItemPersistencia.h"

//********************************************************************
//                                   Construida e testeda
//********************************************************************

class Locacao: public ItemPersistencia
{
	private:
		unsigned int idCliente;
		unsigned int idFilme;
		int precoDeLocacao;
		bool situacao;
	public:
		Locacao(	unsigned int identificador, unsigned int idCliente, unsigned int idFilme,
							int precoDeLocacao, bool situacao);
		void obter(	unsigned int &identificador, unsigned int &idCliente, unsigned int &idFilme,
									int &precoDeLocacao, bool &situacao)const;
		bool obterSituacao()const{return situacao;};
		void atribuirSituacao(bool situacao){this->situacao=situacao;};
};

Locacao::Locacao(	unsigned int identificador, unsigned int idCliente, unsigned int idFilme,
										int precoDeLocacao, bool situacao):
					ItemPersistencia(identificador),
					idCliente(idCliente),
					idFilme(idFilme),
					precoDeLocacao(precoDeLocacao),
					situacao(situacao)

{
	tipoDaClasse=2;
}

void Locacao::obter(	unsigned int &identificador, unsigned int &idCliente, unsigned int &idFilme,
												int &precoDeLocacao, bool &situacao)const
{
	identificador=this->identificador;
	idCliente=this->idCliente;
	idFilme=this->idFilme;
	precoDeLocacao=this->precoDeLocacao;
	situacao=this->situacao;
}


#endif /*LOCACAO_H_*/
