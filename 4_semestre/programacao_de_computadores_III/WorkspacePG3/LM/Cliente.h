#ifndef CLASSECLIENTE_H_
#define CLASSECLIENTE_H_
#include"ItemPersistencia.h"
#include<string>

//********************************************************************
//                                   Construida e testeda
//********************************************************************

class Cliente: public ItemPersistencia
{
	private:
		std::string nome;
		long telefone;
		std::string email;
	public:
		Cliente():ItemPersistencia(0){tipoDaClasse=0;};
		Cliente(	unsigned int identificador, const std::string &nome,
							long telefone, const std::string &email);
		~Cliente(){};
		void obter(	unsigned int &identificador,std::string &nome,
									long &telefone,std::string &email)const;
		void atribuir(	unsigned int identificador, const std::string &nome,
										long telefone, const std::string &email);
		const std::string desmaterializar();
		void materializar(const std::string s);
};

Cliente::Cliente(	unsigned int identificador, const std::string &nome,long telefone, const std::string &email):
			ItemPersistencia(identificador),
			nome(nome),
			telefone(telefone),
			email(email)
{
	tipoDaClasse=0;
}

void Cliente::obter(	unsigned int &identificador,std::string &nome,long &telefone,std::string &email)const
{
	identificador = this->identificador;
	nome = this->nome;
	telefone = this->telefone;
	email = this->email;
}

void Cliente::atribuir(	unsigned int identificador,const std::string &nome,long telefone,const std::string &email)
{
	this->identificador=identificador;
	this->nome=nome;
	this->telefone=telefone;
	this->email=email;
}

const std::string Cliente::desmaterializar()
{
	std::string linha;
	std::string idString;
	for(unsigned int aux=identificador;aux;){
		char letra= (aux%10)+48;
		idString=letra+idString;
		aux=aux/10;
	}
	linha=idString;
	linha +=";";
	linha+=nome;
	linha+=";";
	std::string foneString;
	for(unsigned int aux=telefone;aux;){
		char letra= (aux%10)+48;
		foneString=letra+foneString;
		aux=aux/10;
	}
	linha+=foneString;
	linha+=";";
	linha+=email;
	linha+=";";
	return linha;
}#ifndef CLASSECLIENTE_H_
#define CLASSECLIENTE_H_
#include"ItemPersistencia.h"
#include<string>

//********************************************************************
//                                   Construida e testeda
//********************************************************************

class Cliente: public ItemPersistencia
{
	private:
		std::string nome;
		long telefone;
		std::string email;
	public:
		Cliente():ItemPersistencia(0){tipoDaClasse=0;};
		Cliente(	unsigned int identificador, const std::string &nome,
							long telefone, const std::string &email);
		~Cliente(){};
		void obter(	unsigned int &identificador,std::string &nome,
									long &telefone,std::string &email)const;
		void atribuir(	unsigned int identificador, const std::string &nome,
										long telefone, const std::string &email);
		const std::string desmaterializar();
		void materializar(const std::string s);
};

Cliente::Cliente(	unsigned int identificador, const std::string &nome,
									long telefone, const std::string &email):
			ItemPersistencia(identificador),
			nome(nome),
			telefone(telefone),
			email(email)
{
	tipoDaClasse=0;
}

void Cliente::obter(	unsigned int &identificador,std::string &nome,
											long &telefone,std::string &email)const
{
	identificador = this->identificador;
	nome = this->nome;
	telefone = this->telefone;
	email = this->email;
}

void Cliente::atribuir(	unsigned int identificador,const std::string &nome,
												long telefone,const std::string &email)
{
	this->identificador=identificador;
	this->nome=nome;
	this->telefone=telefone;
	this->email=email;
}

const std::string Cliente::desmaterializar()
{
	std::string linha;
	std::string idString;
	for(unsigned int aux=identificador;aux;){
		char letra= (aux%10)+48;
		idString=letra+idString;
		aux=aux/10;
	}
	linha=idString;
	linha +=";";
	linha+=nome;
	linha+=";";
	std::string foneString;
	for(unsigned int aux=telefone;aux;){
		char letra= (aux%10)+48;
		foneString=letra+foneString;
		aux=aux/10;
	}
	linha+=foneString;
	linha+=";";
	linha+=email;
	linha+=";";
	return linha;
}

void Cliente::materializar(const std::string s)
{
	unsigned int aux=0;
	unsigned int pos=0;
	for(;s[pos]!=';';pos++) aux=aux*10+(s[pos]-48);
	identificador=aux;
	std::string strAux="";
	for(pos++;s[pos]!=';';pos++) strAux+=s[pos];
	nome=strAux;
	long aux2=0;
	for(pos++;s[pos]!=';';pos++) aux2=aux2*10+(s[pos]-48);
	telefone=aux2;
	strAux="";
	for(pos++;s[pos]!=';';pos++) strAux+=s[pos];
	email=strAux;
}

#endif /*CLASSECLIENTE_H_*/


void Cliente::materializar(const std::string s)
{
	unsigned int aux=0;
	unsigned int pos=0;
	for(;s[pos]!=';';pos++) aux=aux*10+(s[pos]-48);
	identificador=aux;
	std::string strAux="";
	for(pos++;s[pos]!=';';pos++) strAux+=s[pos];
	nome=strAux;
	long aux2=0;
	for(pos++;s[pos]!=';';pos++) aux2=aux2*10+(s[pos]-48);
	telefone=aux2;
	strAux="";
	for(pos++;s[pos]!=';';pos++) strAux+=s[pos];
	email=strAux;
}

#endif /*CLASSECLIENTE_H_*/
