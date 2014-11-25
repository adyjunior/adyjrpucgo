#ifndef FILME_H_
#define FILME_H_

#include "ItemPersistencia.h"
#include "Persistencia.h"

//Situacao: Testada
// Classe Filme herdando a classe ItemPersistencia
// Tipo do Classe sera  1  -  Classe Filme
// Classe testada em C++ e modela no Jude
class Filme : public ItemPersistencia
{
	//Atributos
	private:
		std::string titulo;
		int valorDeCompra;
		bool situacao;// true - livre   false - locada
	//Metodos
	public:
		Filme():ItemPersistencia(0,0),titulo(""),valorDeCompra(0),situacao(true){}
		Filme(int identificador):ItemPersistencia(identificador,1),titulo(""),valorDeCompra(0),situacao(true){}
		~Filme(){}
		void atribuirTitulo(std::string titulo){this->titulo=titulo;}
		std::string obterTitulo()const{return titulo;}
		void atribuirValorDeCompra(int valorDeCompra){this->valorDeCompra=valorDeCompra;}
		int obterValorDeCompra(){return valorDeCompra;}
		void atribuirSituacao(bool situacao){this->situacao=situacao;}
		bool obterSituacao(){return situacao;}
		void materializar(const std::string cdc);
		std::string desmaterializar()const;

};

class ControleFilme
{
	private:
		Persistencia *persistencia;
	public:
		ControleFilme(Persistencia *persistencia):persistencia(persistencia){}
		void incluirFilme(Filme *pessoa);
		void consultarFilme(Filme *pessoa);
		void alterarFilme(Filme *pessoa);

};


#endif /*FILME_H_*/
