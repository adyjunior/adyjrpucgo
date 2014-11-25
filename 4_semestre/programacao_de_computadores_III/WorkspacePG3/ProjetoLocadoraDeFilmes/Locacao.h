#ifndef LOCACAO_H_
#define LOCACAO_H_

#include "ItemPersistencia.h"
#include "Persistencia.h"

//Situacao: Testada
// Classe Locacao herdando a classe ItemPersistencia
// Tipo do Classe sera  2  -  Classe Locacao
// Classe testada em C++ e modela no Jude
class Locacao : public ItemPersistencia
{
	//Atributos
	private:
		int idCliente;
		int idFilme;
		int valorDeCompra;
		bool situacao;
	//Metodos	
	public:
        Locacao():ItemPersistencia(0,0),idCliente(0),idFilme(0),valorDeCompra(0),situacao(false){}
		Locacao(int identificador):	ItemPersistencia(identificador,2),idCliente(0),idFilme(0),valorDeCompra(0),situacao(true){}
		virtual ~Locacao(){};
		void atribuirIdCliente(int idCliente){this->idCliente=idCliente;}
		int obterIdCliente(){return idCliente;}
		void atribuirIdFilme(int idFilme){this->idFilme=idFilme;}
		int obterIdFilme(){return idFilme;}
		void atribuirValorDeCompra(int valorDeCompra){this->valorDeCompra=valorDeCompra;}
		int obterValorDeCompra(){return valorDeCompra;}
		void atribuirSituacao(bool situacao){this->situacao=situacao;}
		bool obterSituacao(){return situacao;}
		void materializar(const std::string cdc);
		std::string desmaterializar()const;
};

class ControleLocacao
{
	private:
		Persistencia *persistencia;
	public:
		ControleLocacao(Persistencia *persistencia):persistencia(persistencia){}
		void locarFilme(Locacao *locacao);
		void devolverFilme(Locacao *locacao);
		void cancelarLocacao(Locacao *locacao);

};

#endif /*LOCACAO_H_*/

