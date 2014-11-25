#include "Controle.h"
#include<iostream>
namespace Capsula {


int Controle::pc = 0;

void Controle::decodificacao(std::string identificador,int endereco,std::string parametro2,int modulo){
	try{
		if(identificador == "load(mq)")
			this->escolhaDeOperacoes(0,endereco,modulo);
		else if(identificador == "load()")
			this->escolhaDeOperacoes(1,endereco,modulo);
		else if(identificador == "load")
			this->escolhaDeOperacoes(2,endereco,modulo);
		else if(identificador == "stor")
			this->escolhaDeOperacoes(3,endereco,modulo,parametro2);
		else if(identificador == "jump")
			this->escolhaDeOperacoes(4,endereco,modulo,parametro2);
		else if(identificador == "add")
			this->escolhaDeOperacoes(5,endereco,modulo);
		else if(identificador == "sub")
			this->escolhaDeOperacoes(6,endereco,modulo);
		else if(identificador == "mul")
			this->escolhaDeOperacoes(7,endereco,modulo);
		else if(identificador == "div")
			this->escolhaDeOperacoes(8,endereco,modulo);
		else if(identificador == "lsh()")
			this->escolhaDeOperacoes(9,endereco,modulo);
		else if(identificador == "rsh()")
			this->escolhaDeOperacoes(10,endereco,modulo);
	}catch(std::string msgErro){
		throw(msgErro);
	}

}

void Controle::escolhaDeOperacoes(int opcao,int endereco,int modulo,std::string parametro2){
	try{
		switch(opcao){
		case 0:{
			this->ula.load(endereco);
			break;
		}
		case 1:{//std::cout<<"Controle Load()"<<std::endl;
			this->ula.load();
			break;
		}
		case 2:{//std::cout<<"Controle Load("<<endereco<<")"<<std::endl;
			this->ula.load(endereco,modulo);
			break;
		}
		case 3:{//std::cout<<"Controle Stor("<<endereco<<")"<<std::endl;
			this->ula.stor(endereco,parametro2);
			break;
		}
		case 4:{//std::cout<<"Controle Jump("<<endereco<<")"<<std::endl;
			this->ula.jump(endereco-1,parametro2);
			break;
		}
		case 5:{//std::cout<<"Controle Add("<<endereco<<")"<<std::endl;
			this->ula.add(endereco,modulo);
			break;
		}
		case 6:{//std::cout<<"Controle Sub("<<endereco<<")"<<std::endl;
			this->ula.sub(endereco,modulo);
			break;
		}
		case 7:{//std::cout<<"Controle Mul("<<endereco<<")"<<std::endl;
			this->ula.mul(endereco);
			break;
		}
		case 8:{//std::cout<<"Controle Div("<<endereco<<")"<<std::endl;
			this->ula.div(endereco);
			break;
		}
		case 9:{//std::cout<<"Controle Lsh("<<endereco<<")"<<std::endl;
			this->ula.lsh();
			break;
		}
		case 10:{//std::cout<<"Controle Rsh("<<endereco<<")"<<std::endl;
			this->ula.rsh();
			break;
		}
		default:{

		}

		}

	}catch(std::string msgErro){
		throw(msgErro);
	}


}

}
