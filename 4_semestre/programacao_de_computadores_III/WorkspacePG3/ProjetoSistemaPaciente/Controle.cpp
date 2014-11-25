#include "Controle.h"
#include<iostream>

namespace PSP {



void Controle::inclusaoPaciente(Paciente &paciente)const{
	try{
		PG2::Data data,dataAtual;
		int d,m,a;
		paciente.getDataDeNascimento(d,m,a);
		data.set(d,m,a);
		dataAtual.set(30,10,2010);
		int idade = data.quantidadeDeAnos(dataAtual);
		std::cout<<"Idade :"<<idade<<std::endl;


		if(gravar->buscar(paciente.getNome())) throw(10);//Ja existe
		if(true);//verifica se a data de nascimento foi digitada
		if(idade > 18){//calcula a idade se for menor de 18 entra
			if(paciente.getNumeroCPF() == 0)throw(7);//verifica se o campo de cpf foi preenxido
		}
		if(paciente.getTelefone() == 0)throw(8);//verifica se campo telefone foi preenchido


		gravar->gravar(paciente);
	}catch(int valorErro){
		throw valorErro;
	}

}
void Controle::alteracaoPaciente(Paciente &paciente)const{
	try{
		PG2::Data data,dataAtual;
		int d,m,a;
		paciente.getDataDeNascimento(d,m,a);
		data.set(d,m,a);
		dataAtual.set(30,10,2010);
		int idade = data.quantidadeDeAnos(dataAtual);

		if(!gravar->buscar(paciente.getNome())) throw(11);//Nao existe
		if(true);//verifica se a data de nascimento foi digitada
		if(idade > 18){//calcula a idade se for menor de 18 entra
			if(paciente.getNumeroCPF() == 0)throw(7);//verifica se o campo de cpf foi preenxido
		}
		if(paciente.getTelefone() == 0)throw(8);//verifica se campo telefone foi preenchido


		gravar->alterar(paciente);
	}catch(int valorErro){
		throw valorErro;
	}

}

void Controle::recuperarPaciente(Paciente & paciente)const{
	try{
		if(!this->gravar->buscar(paciente.getNome()))throw (11);//se o paciente a ser excluido nao existe no arquivo lança excecao.
		this->gravar->recuperar(paciente);

	}catch(int valorErro){
		throw valorErro;
	}
}

void Controle::exclusaoPaciente( std::string const & nome )const{
	try{
		if(!this->gravar->buscar(nome))throw(11);// Nao existe paciente
		gravar->apagar(nome);
	}catch(int valorErro){
		throw valorErro;
	}
}

Container::Iterator<Paciente*> *Controle::listarPaciente()const{
	try{
		return gravar->listar();

	}catch(int valorErro){
		throw valorErro;
	}
}



}
