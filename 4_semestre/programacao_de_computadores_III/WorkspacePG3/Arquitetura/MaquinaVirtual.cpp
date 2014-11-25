#include "MaquinaVirtual.h"

namespace Capsula {


void MaquinaVirtual::carregarMemoria(std::string nomeArquivo){
	try{
/*
		std::ifstream arquivo(nomeArquivo.c_str());
		std::string linha;
		if(!arquivo.is_open())throw std::string("Arquivo nao pode ser aberto !");

		for(int pos=0;!arquivo.eof();pos++){
			std::getline(arquivo,linha);std::cout<<linha<<std::endl;

			MemoriaPrincipal::setMemoria(pos,linha);
		}
*/
		this->controle.ula.ulaCarregaMemoria(nomeArquivo);
		//this->getVetor();
	}catch(std::string msgErro){
		throw(msgErro);
	}

}

void MaquinaVirtual::imprimeVetor(){
	try{
		std::cout<<"Tamanho usado de memoria -> "<<this->controle.ula.getIndeceDeUsoDaMemoria()<<std::endl;
		for(int i=0;i < this->controle.ula.getIndeceDeUsoDaMemoria();i++)//MemoriaPrincipal::getIndeceDeUso()
			std::cout<<"Posicao ("<<(i)<<") -> "<<this->controle.ula.ulaGetMemoria(i)<<std::endl;

/*		std::cout<<"PC = "<<Controle::getPc()<<std::endl;
		std::cout<<"IBR = "<<this->controle.getIbr()<<std::endl;
		std::cout<<"IR = "<<this->controle.getIr()<<std::endl;
		std::cout<<"MAR = "<<this->controle.getMar()<<std::endl;
		std::cout<<"MBR = "<<this->controle.getMbr()<<std::endl;
		std::cout<<"AC = "<<this->controle.ula.getAcumulador().getDado()<<std::endl;
*/
	}catch(std::string msgErro){
		throw(msgErro);
	}
}


void MaquinaVirtual::compilador(std::string nomeDoArquivoNoDisco){
	try{
		std::ifstream arquivo(nomeDoArquivoNoDisco.c_str());
		std::string linha;
		bool vj = false;
		if(!arquivo.is_open())throw std::string("Arquivo nao pode ser aberto !");

		Controle::setPc(0);
		for(int pos=0;pos < this->controle.ula.getIndeceDeUsoDaMemoria();pos++,Controle::setPc(pos)){

			linha = this->controle.ula.ulaGetMemoria(Controle::getPc());//MemoriaPrincipal::getMemoria(Controle::getPc());
			this->controle.ula.isJumpLeft = false;
			if(this->controle.ula.isJumpRigth)vj = true;

			if(isOperation(linha) != 0){
				std::cout<<"|--------------------------------------------------|"<<std::endl;//50

				std::cout<<"     PC = "<<Controle::getPc()<<std::endl;

				this->controle.setMbr(linha);

				std::string primeiraInstrucao,segundaInstrucao;

				separaPalavra(';',linha,primeiraInstrucao,segundaInstrucao);

				this->controle.setIbr(segundaInstrucao);

				if(!this->controle.ula.isJumpRigth){
					std::cout<<"|                PRIMEIRA INSTRUCAO                |"<<std::endl<<std::endl;
					std::cout<<"Tecle < ENTER > ..."<<std::endl;
					std::getchar();
					std::cout<<" 1 clock : "<<std::endl<<std::endl;
					std::cout<<"|---------------- CICLO DE BUSCA ------------------|"<<std::endl;
					std::cout<<"     MBR <- M(X)"<<std::endl;
					std::cout<<"     MBR = "<<this->controle.getMbr()<<std::endl<<std::endl;


					defineInstrucoes(primeiraInstrucao,Controle::getPc());

					std::getchar();
					system("cls");

					if(this->controle.ula.isJumpRigth){pos = Controle::getPc();continue;}
					if(this->controle.ula.isJumpLeft){pos = Controle::getPc();continue;}
				}




				std::cout<<"|                 SEGUNDA INSTRUCAO                 |"<<std::endl<<std::endl;
				std::cout<<"Tecle < ENTER > ..."<<std::endl;
				std::getchar();
				std::cout<<" 1 clock : "<<std::endl<<std::endl;
				std::cout<<"|---------------- CICLO DE BUSCA -------------------|"<<std::endl;
				std::cout<<"     MBR <- M(X)"<<std::endl;
				std::cout<<"     MBR = "<<this->controle.getMbr()<<std::endl<<std::endl;



				defineInstrucoes(segundaInstrucao,Controle::getPc());

				if(this->controle.ula.isJumpRigth == true && vj == true ){
					this->controle.ula.isJumpRigth = false;
					vj = false;
				}

				std::getchar();
				system("cls");
				/////////////////
			}
			else{
				if(linha != "")
					trataValor(linha,Controle::getPc());
			}

			pos = Controle::getPc();
		}

		std::cout<<"FINAL DAS INSTRUCOES !!!"<<std::endl<<std::endl;
		std::cout<<"Tecle < ENTER > ..."<<std::endl;
		std::getchar();
		std::cin.ignore();



	}catch(std::string msgErro){
		std::cout<<"Erro ->"<<msgErro<<std::endl;
	}

}

void MaquinaVirtual::defineInstrucoes(std::string instrucao,int pos){
	try{
		if(isOperation(instrucao)== 1){
			trataOperacao(instrucao,pos);
		}
		else if(isOperation(instrucao) == 2){
			trataModular(instrucao,pos);
		}
	}catch(std::string msgErro){
		throw(msgErro);
	}

}

void MaquinaVirtual::separaPalavra(char caracter,std::string linha,std::string &parte1,std::string &parte2){

	int div,div2;

	div = linha.find(caracter);
	div2 = linha.find(caracter,div+1);

	parte1 = linha.substr(0,div);
	//cout<<parte1<<endl;

	parte2 = linha.substr(div+1,div2-div-1);
}


int MaquinaVirtual::isOperation(std::string linha)const{
	for(unsigned int i=0;i < linha.size();i++){
		if(linha[i] == '|'){
			return 2;} //Operaco modular EX: add|(10)|
		else if(linha[i] == '(' || linha[i] == ')'){
			return 1;//Operacao EX: load(10)
		}
	}
	return 0; // se for Numero;
}

void MaquinaVirtual::trataValor(std::string linha,int pos){
	try{
		this->controle.ula.ulaSetMemoria(pos,linha);//MemoriaPrincipal::setMemoria(pos,linha);
	}catch(std::string msgErro){
		throw(msgErro);
	}

}

void MaquinaVirtual::trataModular(std::string instrucao,int pos){
	try{
		//std::cout<<"TRATA MODULAR"<<std::endl;
		int busca,busca2;
		std::string str,argumento1,argumento2;
		std::string Identificador;
		int parametro=0,sinal=-1;

		if(instrucao.find('-') != std::string::npos){
			instrucao.erase(instrucao.find('-'),1);
			sinal = 1;
		}

		if(instrucao.find('+') != std::string::npos)instrucao.erase(instrucao.find('+'),1);

		busca = instrucao.find('|');
		busca2 = instrucao.find('|',busca+1);


		Identificador = instrucao.substr(0,busca);
		str = instrucao.substr(busca+2,busca2-busca-3);
		parametro = std::atoi(str.c_str());

		if(str.find(',') != std::string::npos){
			this->separaPalavra(',',str,argumento1,argumento2);
			parametro = std::atoi(argumento1.c_str());

		}


		this->controle.setIr(Identificador);
		this->controle.setMar(str);


		std::cout<<"Tecle < ENTER > ..."<<std::endl;
		std::getchar();
		std::cout<<" 2 clock : "<<std::endl<<std::endl;
		std::cout<<"     MBR = "<<this->controle.getMbr()<<std::endl;
		std::cout<<"     IR ="<<this->controle.getIr()<<std::endl;
		std::cout<<"     MAR ="<<this->controle.getMar()<<std::endl;
		std::cout<<"     IBR = "<<this->controle.getIbr()<<std::endl<<std::endl;
		std::cout<<"     AC = "<<this->controle.ula.getAcumulador().getDado()<<std::endl<<std::endl;


		this->controle.decodificacao(Identificador,parametro,argumento2,sinal);
		std::cout<<"Tecle < ENTER > ..."<<std::endl;
		std::getchar();
		std::cout<<" 3 clock : "<<std::endl<<std::endl;
		std::cout<<"|---------------- CICLO DE EXECUCAO -----------------|"<<std::endl<<std::endl;

		std::cout<<"     MBR = "<<this->controle.getMbr()<<std::endl;
		std::cout<<"     IR = "<<this->controle.getIr()<<std::endl;
		std::cout<<"     MAR = "<<this->controle.getMar()<<std::endl;
		std::cout<<"     IBR = "<<this->controle.getIbr()<<std::endl<<std::endl;
		std::cout<<"     AC = "<<this->controle.ula.getAcumulador().getDado()<<std::endl<<std::endl;
		std::cout<<"     MQ = "<<this->controle.ula.getMq().getDado()<<std::endl<<std::endl;



	}catch(std::string msgErro){
		throw(msgErro);
	}

}

void MaquinaVirtual::trataOperacao(std::string instrucao ,int pos){
	try{
		//std::cout<<"TRATA OPERACAO"<<std::endl;
		int busca,busca2;
		std::string str, argumento1,argumento2;
		std::string Identificador;
		int parametro=0,sinal=1;

		if(instrucao.find('-') != std::string::npos){
			instrucao.erase(instrucao.find('-'),1);
			sinal = -1;
		}

		if(instrucao.find('+') != std::string::npos)instrucao.erase(instrucao.find('+'),1);

		busca = instrucao.find('(');
		busca2 = instrucao.find(')');

		if(instrucao[busca+1] == ')')
			Identificador = instrucao;
		else{
			Identificador = instrucao.substr(0,busca);
			str = instrucao.substr(busca+1,busca2-busca-1);
			parametro = std::atoi(str.c_str());

			if(str.find(',') != std::string::npos){
				this->separaPalavra(',',str,argumento1,argumento2);
				parametro = std::atoi(argumento1.c_str());

				if(argumento2 == "mq"){
					Identificador = Identificador+"(mq)";
					argumento2 = "";
				}
			}
		}

		this->controle.setIr(Identificador);
		this->controle.setMar(str);

		std::cout<<"Tecle < ENTER > ..."<<std::endl;
		std::getchar();
		std::cout<<" 2 clock : "<<std::endl<<std::endl;
		std::cout<<"|---------------------------------------------------|"<<std::endl<<std::endl;
		std::cout<<"     MBR = "<<this->controle.getMbr()<<std::endl;
		std::cout<<"     IR ="<<this->controle.getIr()<<std::endl;
		std::cout<<"     MAR ="<<this->controle.getMar()<<std::endl;
		std::cout<<"     IBR = "<<this->controle.getIbr()<<std::endl<<std::endl;
		std::cout<<"     AC = "<<this->controle.ula.getAcumulador().getDado()<<std::endl;
		std::cout<<"     MQ = "<<this->controle.ula.getMq().getDado()<<std::endl<<std::endl;


		this->controle.decodificacao(Identificador,parametro,argumento2,sinal);

		std::cout<<"Tecle < ENTER > ..."<<std::endl;
		std::getchar();
		std::cout<<" 3 clock : "<<std::endl<<std::endl;
		std::cout<<"|---------------- CICLO DE EXECUCAO -----------------|"<<std::endl<<std::endl;

		std::cout<<"     MBR = "<<this->controle.getMbr()<<std::endl;
		std::cout<<"     IR = "<<this->controle.getIr()<<std::endl;
		std::cout<<"     MAR = "<<this->controle.getMar()<<std::endl;
		std::cout<<"     IBR = "<<this->controle.getIbr()<<std::endl<<std::endl;
		std::cout<<"     AC = "<<this->controle.ula.getAcumulador().getDado()<<std::endl<<std::endl;
		std::cout<<"     MQ = "<<this->controle.ula.getMq().getDado()<<std::endl<<std::endl;


	}catch(std::string msgErro){
		throw(msgErro);
	}

}

void MaquinaVirtual::imprimeReg(){
	std::cout<<"     MBR = "<<this->controle.getMbr()<<std::endl;
	std::cout<<"     PC  = "<<Controle::getPc()<<std::endl;
	std::cout<<"     IR ="<<this->controle.getIr()<<std::endl;
	std::cout<<"     MAR ="<<this->controle.getMar()<<std::endl;
	std::cout<<"     IBR = "<<this->controle.getIbr()<<std::endl<<std::endl;
	std::cout<<"     AC = "<<this->controle.ula.getAcumulador().getDado()<<std::endl;
	std::cout<<"     MQ = "<<this->controle.ula.getMq().getDado()<<std::endl<<std::endl;
}




}
