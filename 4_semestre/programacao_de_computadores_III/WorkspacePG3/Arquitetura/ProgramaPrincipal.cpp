#include"MaquinaVirtual.h"
#include<iostream>

int main(int argc,char* argv[]){


	std::string nomeDoArquivo;

	nomeDoArquivo = "arquitetura.txt"; //se quiser abrir arquivo especifico
	// nomeDoArquivo = argv[1] // se quiser abrir qualquer arquivo na hora de executar o programa EX :  MaquinaVirtaul.exe arquivo.ias
	MaquinaVirtual mv;
	try{
		mv.carregarMemoria(nomeArquivo);

		mv.imprimeVetor();
		mv.compilador(nomeArquivo);

		mv.imprimeVetor();


	}catch(std::string msgErro){
		std::cout<<"Erro ->"<<msgErro<<std::endl;
	}


system("pause");
}
