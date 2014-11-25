#include "Paciente.h"
#include<iostream>

namespace PSP {


void Paciente::setDataDeNascimento(int dia,int mes,int ano){
	try{
		this->dataDeNascimento.set(dia,mes,ano);
	}catch(int valorErro){
			throw valorErro;
		}
}

void Paciente::setDataDeNascimento(std::string const & data){
	try{
		this->dataDeNascimento.setDataStr(data);
	}catch(int valorErro){
			throw valorErro;
		}
}

void Paciente::setNumeroCPF(long long numeroCPF){
	try{
		this->numeroCPF.set(numeroCPF);
	}catch(int valorErro){
		throw valorErro;
	}
}


std::string Paciente::desmaterializar()const{
	try{
		CadeiaCaracteres::CDC conversao;
		int d,m,a;
		std::string dA="",mA="";//dia e mes auxiliar para verificaçao
		this->getDataDeNascimento(d,m,a);
		if(d < 10)dA="0";
		if(m < 10)mA = "0";
		std::string strCPF = conversao.converteInteiroLongoLongoParaStr(this->getNumeroCPF());
		std::string strTelefone = conversao.converteInteiroLongoParaStr(this->telefone);
		std::string data = dA +  conversao.converteInteiroParaStr(d)+ mA + conversao.converteInteiroParaStr(m) + conversao.converteInteiroParaStr(a);



		std::string linha;

		linha = nome + ";" +  endereco + ";" + strCPF + ";" + data + ";" + email+ ";" + strTelefone;
		conversao.converteStringParaMaiuscula(linha);

		return linha;
	}catch(int valorErro){
		throw valorErro;
	}
}

void Paciente::materializar(std::string const &linha){

	try{
		CadeiaCaracteres::CDC conversao;

		unsigned int pos=0;
		int d,m,a;

		this->nome = conversao.buscarSubString(linha,pos,';');
		this->endereco = conversao.buscarSubString(linha,pos,';');
		this->setNumeroCPF( conversao.converteStrParaInteiroLongoLongo(conversao.buscarSubString(linha,pos,';')) );
		std::string data = conversao.buscarSubString(linha,pos,';') ;
		this->email = conversao.buscarSubString(linha,pos,';');
		this->telefone = conversao.converteStrParaInteiroLongo(conversao.buscarSubString(linha,pos,';'));

		//std::cout<<data<<std::endl;
		//this->setDataDeNascimento(data);
		d = conversao.converteStrParaInteiro(data.substr(0,2));
		m = conversao.converteStrParaInteiro(data.substr(2,2));
		a =  conversao.converteStrParaInteiro(data.substr(4,4));

		this->setDataDeNascimento(d,m,a);

	}catch(int valorErro){
		throw valorErro;
	}

}

bool Paciente::operator <(Paciente pa)const{// retorna se eh menor ou nao

	int tam;
	if(this->nome.size() > pa.nome.size())
		tam = pa.nome.size();
	else
		tam = this->nome.size();

	for(int i=0;i < tam;){
		if(this->nome[i] == pa.nome[i])
			i++;
		else if((static_cast<int>(this->nome[i])) < (static_cast<int>(pa.nome[i])))
					return true;
		else
			return false;


	}

return false;
}

}
