#ifndef SISTEMA_H_
#define SISTEMA_H_
#include<fstream>
#include<string>
#include<cstdlib>
#include<iostream>
#include"Controle.h"
#include"MemoriaPrincipal.h"

namespace Capsula {

class MaquinaVirtual {
	//MemoriaPrincipal memoria;
	Controle controle;
	//ULA unidadeLA;


public:
	//MaquinaVirtual(){};
	void carregarMemoria(std::string nomeArquivo);
	void compilador(std::string nomeDoArquivoNoDisco);
	void trataValor(std::string linha,int pos);
	void trataOperacao(std::string linha,int pos);
	int isOperation(std::string linha)const;
	void trataModular(std::string instrucao,int pos);
	void defineInstrucoes(std::string instrucao,int pos);
	void separaPalavra(char caracter,std::string linha,std::string &parte1,std::string &parte2);
	//MemoriaPrincipal getMemoria()const{return memoria;}
	void imprimeVetor();
	void imprimeReg();
	//void setMemoria(MemoriaPrincipal &mem){this->memoria = mem;}

	//void getVetor(){this->controle.getVetor(this->memoria);}


};

}

#endif /* SISTEMA_H_ */
