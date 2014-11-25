#include "ULA.h"
#include"Controle.h"
#include<stdio.h>
#include<stdlib.h>

namespace Capsula {


void ULA::load(int endereco,int modulo){
	//std::cout<<"load("<<endereco<<")"<<std::endl;
	try{
		int resultado = std::atoi(memoria.getMemoria(endereco).c_str());
		//if(resultado < 0)//verificar se é negativo
		//{
			resultado = resultado*modulo;

			std::stringstream ss;
			ss << resultado;
			std::string ac =ss.str();

			this->acumulador.setDado( ac );
		//}
		//else{std::cout<<"resultado N ->"<<resultado<<std::endl;
			//this->acumulador.setDado(memoria.getMemoria(endereco));
		//}

		//std::cout<<"Load ="<<this->acumulador.getDado()<<std::endl;
	}catch(std::string msgErro){
		throw(msgErro);
	}
}

void ULA::load(int endereco){
	try{
		this->mq.setDado(this->memoria.getMemoria(endereco));
	}catch(std::string msgErro){
		throw(msgErro);
	}
}

bool ULA::isJumpRigth = false;
bool ULA::isJumpLeft = false;

void ULA::stor(int endereco,std::string parametro2){
	try{

		if(parametro2 == ""){
					//std::cout<<"stor("<<endereco<<parametro2<<")"<<std::endl;
			MemoriaPrincipal::setMemoria(endereco,acumulador.getDado());
		}
		else{
			std::string linha,ist,i1,i2,par,ac,final;
			int busca,busca2;


			///////////////////////////////////////////////////////////// ESQUERDA
			if(parametro2[0] == '8'){
				linha = MemoriaPrincipal::getMemoria(endereco);
				busca = linha.find(';');
				busca2 = linha.find(';',busca+1);
				i1 = linha.substr(0,busca);
				i2 = linha.substr(busca,busca2-busca+1);

				busca = i1.find('(');
				busca2 = i1.find(')');
				ist = i1.substr(0,busca);
				busca = i1.size()-1;
				final = i1.substr(busca2,busca-busca2+1);

				par = this->acumulador.getDado();
				ac = ist+"("+par+final+i2;

				MemoriaPrincipal::setMemoria(endereco,ac);

				//			 std::cout<<"Acumulador --> "<<this->acumulador.getDado()<<std::endl;
				//			 std::cout<<"Memoria -----> "<<this->memoria.getMemoria(endereco)<<std::endl;
			}
			else{///////////////////////////////////////////////// DIREITA

				linha = MemoriaPrincipal::getMemoria(endereco);  //17 - 8 = 9  -> (9,10)
				busca = linha.find(';');
				busca2 = linha.find(';',busca+1);
				i1 = linha.substr(0,busca+1);
				i2 = linha.substr(busca+1,busca2-busca+1);

				busca = i2.find('(');    // (0,4)
				busca2 = i2.find(')');
				ist = i2.substr(0,busca);
				busca = i2.size()-1;
				final = i2.substr(busca2,busca-busca2+1);
				par = this->acumulador.getDado();
				ac = i1+ist+"("+par+final;

				MemoriaPrincipal::setMemoria(endereco,ac);

				//			 std::cout<<"Acumulador --> "<<this->acumulador.getDado()<<std::endl;
				//			 std::cout<<"Memoria -----> "<<this->memoria.getMemoria(endereco)<<std::endl;

			}
					//std::cout<<"stor("<<endereco<<","<<parametro2<<")"<<std::endl;
		}

	}catch(std::string msgErro){
		throw(msgErro);
	}
}

void ULA::jump(int endereco,std::string parametro2){
	//std::cout<<"jump ("<<endereco<<","<<parametro2<<")"<<std::endl;
	try{
		//std::cout<<"Jump --> ("<<endereco<<","<<parametro2<<")"<<std::endl;
		if(parametro2[0] ==  '0'){
			Controle::setPc(endereco);
			isJumpLeft = true;
		}
		else{//std::cout<<"JUMP RIGTH"<<std::endl;
			Controle::setPc(endereco);
			isJumpRigth = true;
		}

	}catch(std::string msgErro){
		throw(msgErro);
	}
}

void ULA::add(int endereco,int modulo){
	//std::cout<<"add("<<endereco<<")"<<std::endl;
	try{
//		std::cout<<"M(X) ="<<this->memoria.getMemoria(endereco)<<std::endl;
//		std::cout<<"+"<<std::endl;
//		std::cout<<"AC ="<<this->acumulador.getDado()<<std::endl;

		int ac,dado,resultado;
		std::stringstream ss(acumulador.getDado());
		std::stringstream ss2(MemoriaPrincipal::getMemoria(endereco));
		std::stringstream add;
		ss >> ac;
		ss2 >> dado;

		resultado = dado + ac;

		//if(resultado%2 !=0)
			resultado = resultado*modulo;

		add << resultado;

		acumulador.setDado(add.str());

		//std::cout<<"ADD ="<<this->acumulador.getDado()<<std::endl;
	}catch(std::string msgErro){
		throw(msgErro);
	}
}

void ULA::sub(int endereco,int modulo){
	//std::cout<<"sub("<<endereco<<")"<<std::endl;
	try{
//		std::cout<<"M(X) ="<<this->memoria.getMemoria(endereco)<<std::endl;
//		std::cout<<"-"<<std::endl;
//		std::cout<<"AC ="<<this->acumulador.getDado()<<std::endl;

		int ac,dado,resultado;
		std::stringstream ss(acumulador.getDado());
		std::stringstream ss2(MemoriaPrincipal::getMemoria(endereco));
		std::stringstream sub;
		ss >> ac;
		ss2 >> dado;

		resultado = dado - ac;
		//if(resultado%2 !=0)
			resultado = resultado*modulo;

		sub << resultado;

		acumulador.setDado(sub.str());

		//std::cout<<"SUB ="<<this->acumulador.getDado()<<std::endl;
	}catch(std::string msgErro){
		throw(msgErro);
	}
}

void ULA::mul(int endereco){
	//std::cout<<"mul("<<endereco<<")"<<std::endl;
	try{
//		std::cout<<"M(X) ="<<this->memoria.getMemoria(endereco)<<std::endl;
//		std::cout<<"*"<<std::endl;
//		std::cout<<"AC ="<<this->acumulador.getDado()<<std::endl;

		int ac,dado,resultado;
		std::stringstream ss(acumulador.getDado());
		std::stringstream ss2(MemoriaPrincipal::getMemoria(endereco));
		std::stringstream mul;
		ss >> ac;
		ss2 >> dado;

		resultado = dado * ac;

		mul << resultado;

		acumulador.setDado(mul.str());

		//std::cout<<"MUL ="<<this->acumulador.getDado()<<std::endl;
	}catch(std::string msgErro){
		throw(msgErro);
	}

}

void ULA::div(int endereco){
	//std::cout<<"div("<<endereco<<")"<<std::endl;
	try{
//		std::cout<<"M(X) ="<<this->memoria.getMemoria(endereco)<<std::endl;
//		std::cout<<"/"<<std::endl;
//		std::cout<<"AC ="<<this->acumulador.getDado()<<std::endl;

		int ac,dado,resultado,resto;
		std::stringstream ss(acumulador.getDado());
		std::stringstream ss2(MemoriaPrincipal::getMemoria(endereco));
		std::stringstream div,rest;
		ss >> ac;
		ss2 >> dado;

		if(ac == 0)throw(std::string)("Nao eh permitido divisao por 0");

		resultado = dado / ac;

		resto = dado%ac;

		div << resultado;
		rest << resto;

		acumulador.setDado(div.str());
		mq.setDado(rest.str());
		//std::cout<<"DIV ="<<this->acumulador.getDado()<<std::endl;
	}catch(std::string msgErro){
		throw(msgErro);
	}

}

void ULA::lsh(){//multiplica o acumulador por 2
	//std::cout<<"lsh()"<<std::endl;
	//std::cout<<"LSH AC antes = "<<this->acumulador.getDado()<<std::endl;
	int numero;
	std::stringstream ac;
	numero = std::atoi(this->acumulador.getDado().c_str());
	numero = numero *2;

	ac << numero;

	this->acumulador.setDado(ac.str());
	//std::cout<<"LSH AC antes = "<<this->acumulador.getDado()<<std::endl;

}

void ULA::rsh(){// divide o acumulador por 2
	//std::cout<<"rsh()"<<std::endl;
	//std::cout<<" RSH AC antes = "<<this->acumulador.getDado()<<std::endl;
	int numero;
	std::stringstream ac;
	numero = std::atoi(this->acumulador.getDado().c_str());
	numero = numero /2;

	ac << numero;

	this->acumulador.setDado(ac.str());
	//std::cout<<"RSH AC antes = "<<this->acumulador.getDado()<<std::endl;

}


void ULA::ulaCarregaMemoria(std::string nomeDoArquivo){
	std::ifstream arquivo(nomeDoArquivo.c_str());
	std::string linha;
	if(!arquivo.is_open())throw std::string("Arquivo nao pode ser aberto !");

	for(int pos=0;!arquivo.eof();pos++){
		std::getline(arquivo,linha);std::cout<<linha<<std::endl;

		MemoriaPrincipal::setMemoria(pos,linha);
	}

}

std::string ULA::ulaGetMemoria(int endereco){
	return this->memoria.getMemoria(endereco);
}

void ULA::ulaSetMemoria(int endereco,std::string dado){
	this->memoria.setMemoria(endereco,dado);
}




///////////////////////////////////////////////////// BINARIOS //////////////////////////////////////////////////////////
void ULA::add(int endereco,int binario,int c){

	std::string a = MemoriaPrincipal::getMemoria(endereco);
	std::string b = acumulador.getDado();

	if(a.size() != b.size())equal(a,b);

	int tam=0;
	bool carry=false;
	std::string Add;
	tam = a.size();

	Add = a;

	for(int i=tam;i >= 0;i--){
		if(!carry){
			if(a.substr(i,1)== "0" && b.substr(i,1) == "0"){
				Add[i] = '0';
				carry = false;
			} else if(a.substr(i,1) != b.substr(i,1)){
				Add[i] = '1';
				carry = false;
			}else if(a.substr(i,1)== "1" && b.substr(i,1) == "1") {
				Add[i] = '0';
				carry = true;

			}
		}
		else{
			if(a.substr(i,1)== "0" && b.substr(i,1) == "0"){
				Add[i] = '1';
				carry = false;
			} else if(a.substr(i,1) != b.substr(i,1)){
				Add[i] = '0';
				carry = true;
			}else if(a.substr(i,1)== "1" && b.substr(i,1) == "1"){
				Add[i] = '1';
				carry = true;
			}


		}

	}

	acumulador.setDado( Add );

}


void ULA::sub(int endereco,int binario,int c){

	std::string a = MemoriaPrincipal::getMemoria(endereco);
	std::string b = acumulador.getDado();

	if(a.size() != b.size()) equal(a,b);

	int tam = a.size();
	std::string Sub;
	bool empresta = false;


	Sub = a;

	for(int i=tam;i >= 0;i--){
		if(!empresta){
			if(a.substr(i,1)  ==  b.substr(i,1)){
				Sub[i] = '0';
				empresta = false;
			} else if(a.substr(i,1) == "1" && b.substr(i,1) == "0"){
				Sub[i] = '1';
				empresta = false;
			}else if(a.substr(i,1)== "0" && b.substr(i,1) == "1") {
				Sub[i] = '1';
				empresta = true;

			}
		}
		else{
			if(a.substr(i,1) == "0" && b.substr(i,1) == "0"){
				Sub[i] = '0';
				empresta = false;
			} else if(a.substr(i,1) == "1" && b.substr(i,1) == "1"){
				Sub[i] = '1';
				empresta = true;
			}
			else if(a.substr(i,1) == "1" && b.substr(i,1) == "0"){
				Sub[i] = '0';
				empresta = true;
			}else if(a.substr(i,1)== "0" && b.substr(i,1) == "1"){
				Sub[i] = '1';
				empresta = true;
			}


		}

	}


	acumulador.setDado( Sub );
}


void ULA::equal(std::string &a,std::string &b){
	std::string resultante ;
	int diferenca,tam;
	if(a.size() > b.size()){

		diferenca = a.size() - b.size();
		tam = a.size();
		resultante = a;

		for(int i=0;i < tam;i++){
			if(i < diferenca)
				resultante[i] = '0';
			else
				resultante[i] = b[i-diferenca];
		}

		b = resultante;

	}
	else{

		diferenca = b.size() - a.size();

		tam = b.size();
		resultante = b;
		for(int i=0;i < tam;i++){
			if(i < diferenca)
				resultante[i] = '0';
			else
				resultante[i] = a[i-diferenca];
	}
		a = resultante;

	}




}

}
