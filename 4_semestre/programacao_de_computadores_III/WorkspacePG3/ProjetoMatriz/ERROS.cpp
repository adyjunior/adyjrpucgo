#include "ERROS.h"



namespace PC3 {

ERROS::ERROS(int op){
	op = 10;
}
void ERROS::setIdioma(int opcao){

	int tam;
	std::string nomeDoArquivo,lixo;
	if(opcao == 2)
		nomeDoArquivo="DiretorioErro/arquivoDeErro.txt";
	else
		nomeDoArquivo="DiretorioErro/arquivoDeErroEUA.txt";

	std::ifstream arquivo(nomeDoArquivo.c_str());

	try{
		if(!arquivo.is_open()) throw (std::logic_error) ("Arquivo de Erro nao pode ser aberto");

		arquivo >> tam;

		strErro = new std::string[tam];

		std::getline(arquivo,lixo);
		for(int i=0;i < tam;i++)
			std::getline(arquivo,strErro[i]);

		arquivo.close();

	}catch(std::logic_error a){
		arquivo.close();
		throw a;
	}catch(std::bad_alloc&){
		arquivo.close();
		throw (std::logic_error) ("Memoria insuficiente para criacao do arquivo de ERROS");
	}

}

ERROS * ERROS::instancia=0;





}
