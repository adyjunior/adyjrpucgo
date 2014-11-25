#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "ItemPersistencia.h"
#include "Persistencia.h"

//Situacao: Testada
// Classe Cliente herdando a classe ItemPersistencia
// Tipo do Classe:  0   -  Classe Cliente
// Classe testada em C++ e modela no Jude
class Cliente : public ItemPersistencia
{
	//Atributos
	private:
		std::string nome;
		long telefone;
		std::string email;
	//Metodos
	public:
		Cliente():ItemPersistencia(0,0),nome(""),telefone(0),email(""){}
		Cliente(int identificador):ItemPersistencia(identificador,0),nome(""),telefone(0),email(""){}
		~Cliente(){}
		void atribuirNome(const std::string nome) {this->nome=nome;}
		std::string obterNome()const {return nome;}
		void atribuirTelefone(long telefone) {this->telefone=telefone;}
		long obterTelefone()const {return telefone;}
		void atribuirEmail(const std::string email) {this->email=email;}
		std::string obterEmail()const {return email;}
		void materializar(const std::string cdc);
		std::string desmaterializar()const;
};

class ControleCliente
{
	private:
		Persistencia *persistencia;
	public:
		ControleCliente(Persistencia *persistencia):persistencia(persistencia){}
		void incluirCliente(Cliente *pessoa);
		void consultarCliente(Cliente *pessoa);
		void alterarCliente(Cliente *pessoa);
		void excluirCliente(Cliente *pessoa);
};
#endif /*CLIENTE_H_*/
