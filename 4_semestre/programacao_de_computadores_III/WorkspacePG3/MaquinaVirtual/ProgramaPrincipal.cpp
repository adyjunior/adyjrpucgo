#include"MaquinaVirtual.h"
#include<iostream>
#include"Interface.h"

int main(int argc,char* argv[]){


	std::string nomeDoArquivo;

	nomeDoArquivo =argv[1];//"arquitetura.txt"; //
	Capsula::Interface show(nomeDoArquivo);
	//std::cout<<argv[1]<<std::endl;
	try{
		//show.carregarMemoria(nomeArquivo);

		//Capsula::Interface::menu();
		//show.imprimeVetor();
		show.menu();
		//show.compilador();

		//show.imprimeVetor();


	}catch(std::string msgErro){
		std::cout<<"Erro ->"<<msgErro<<std::endl;
	}

	//show.imprimeVetor();
system("pause");
}
