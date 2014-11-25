#include "Controle.h"

namespace PC3 {

void Controle::processoGravar(Matriz const &matriz, std::string const &nomeDoArquivo)const{
	try{
		if(matriz.getQuantidadeLinhas() != matriz.getQuantidadeColunas()) throw (5);//matriz nao eh quadrada
		std::string nomeDoArquivoNoDisco = /*"./DiretorioMatriz/" + */"DiretorioMatriz/"+nomeDoArquivo;
		persistir.gravar(matriz,nomeDoArquivoNoDisco);
	}catch(int valorErro){
		throw valorErro;
	}
}

Matriz *Controle::processoRecuperar(std::string const &nomeDoArquivo)const{
	try{
		std::string nomeDoArquivoNoDisco = /*"./DiretorioMatriz/" + */"DiretorioMatriz/"+nomeDoArquivo;
		return persistir.recuperar(nomeDoArquivoNoDisco);
	}
	catch(int valorErro){
		throw valorErro;
	}
}

void Controle::processoApagar(std::string const &nomeDoArquivoNoDisco)const{
	try{
	persistir.apagar("DiretorioMatriz/"+nomeDoArquivoNoDisco);
	}catch(int valorErro){
		throw valorErro;
	}
}

}
