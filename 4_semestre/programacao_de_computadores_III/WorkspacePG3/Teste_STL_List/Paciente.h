#ifndef PACIENTE_H_
#define PACIENTE_H_
#include<string>
//#include"CPF.h"
//#include"Data.h"
//#include"CDC.h"
namespace PSP {

class Paciente {
private:
	std::string nome;
	std::string endereco;
	long telefone;
	//PG2::CPF numeroCPF;
	//PG2::Data dataDeNascimento;
	std::string email;

public:
	void setNome(std::string nome){this->nome = nome;}
	void setEndereco(std::string endereco){this->endereco = endereco;}
	void setTelefone(long telefone){this->telefone = telefone;}
	//void setNumeroCPF(long long numeroCPF);
	//void setDataDeNascimento(int dia,int mes,int ano);
	//void setDataDeNascimento(std::string const & data);
	void setEmail(std::string email){this->email = email;}

	std::string getNome()const{return nome;}
	std::string getEndereco()const{return endereco;}
	long getTelefone()const{return telefone;}
	//long long int getNumeroCPF()const{numeroCPF.get();}
	//void getDataDeNascimento(int &dia,int &mes,int &ano)const{dataDeNascimento.get(dia,mes,ano);}
	//std::string getDataDeNascimento()const{dataDeNascimento.getDataStr();}
	std::string getEmail()const{return email;}

	void materializar(std::string const &linha);
	std::string desmaterializar()const;
	bool operator <(Paciente pa)const;
	//std::ostream *operator<<(std::ostream * Cout,const std::list<Paciente>& lista);



};

}

#endif /* PACIENTE_H_ */
