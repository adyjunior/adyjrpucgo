#include "Interface.h"

namespace VilaNova {

void Interface::lerMatriz(Matriz &matriz){
	for(int linha=0; linha<matriz.getQuantidadeLinhas();linha++){
		for(int coluna=0; coluna<matriz.getQuantidadeColunas();coluna++){
			std::cout<<"Elemento["<<linha<<"]["<<coluna<<"]= ";
			int elemento=0;
			std::cin>>elemento;
			matriz.setElemento(linha,coluna,elemento);
		}
	}
}

void Interface::escreverMatriz(Matriz const &matriz){
	int qLinhas = matriz.getQuantidadeLinhas();
	int qColunas = matriz.getQuantidadeColunas();
	for(int linha=0; linha<qLinhas;linha++){
		std::cout<<"|";
		for(int coluna=0; coluna<qColunas;coluna++){
			int elemento=0;
			matriz.getElemento(linha,coluna,elemento);
			std::cout<<std::left<<std::setw(3)<<elemento<<" ";
		}
		std::cout<<std::left<<std::setw(3)<<"|"<<std::endl;
	}
}


}
