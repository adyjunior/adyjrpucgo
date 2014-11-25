#include "Controle.h"

namespace VilaNova {

void Controle::gravarMatriz(Matriz const &matriz, std::string const &nomeDoArquivo){
	matrizesEmArquivo.gravar(matriz,nomeDoArquivo);
}

Matriz *Controle::recuperarMatriz(std::string const &nomeDoArquivo){
	return matrizesEmArquivo.recuperar(nomeDoArquivo);
}

void Controle::apagarMatriz(std::string const &nomeDoArquivo){
	//matrizesEmArquivo.apagar(nomeDoArquivo);
}

}
