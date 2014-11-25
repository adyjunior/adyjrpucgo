#include "Persistencia.h"

namespace VilaNova {

bool Persistencia::gravar(	Matriz const &matriz,
							std::string const &nomeDoArquivo){
	std::ofstream arquivoMatriz(nomeDoArquivo.c_str());
	if(!arquivoMatriz.is_open()) return false;
	int linha  = matriz.getQuantidadeLinhas();
	int coluna = matriz.getQuantidadeColunas();
	arquivoMatriz<<linha<<std::endl;
	arquivoMatriz<<coluna<<std::endl;
	for(int i=0; i<linha; i++)
    	for(int j=0; j<coluna; j++){
    		int elemento;
    		matriz.getElemento(i,j,elemento);
    		arquivoMatriz<<elemento<<std::endl;
    	}

	arquivoMatriz.close();
	return true;
}


Matriz *Persistencia::recuperar(std::string const &nomeDoArquivo){
	std::ifstream arquivoMatriz(nomeDoArquivo.c_str());
	if(!arquivoMatriz.is_open()) return 0;
	int linha, coluna,a;
	arquivoMatriz>>linha;
	arquivoMatriz>>coluna;

	Matriz *matriz = new Matriz(linha,coluna);

	for(int i=0; i<linha; i++)
    	for(int j=0; j<coluna; j++){
    		arquivoMatriz>>a;
    		matriz->setElemento(i,j,a);
    	}
	arquivoMatriz.close();
	return matriz;
}


}
