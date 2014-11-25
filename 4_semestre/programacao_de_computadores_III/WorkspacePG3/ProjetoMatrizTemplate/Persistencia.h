#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_

#include<fstream>
#include<iostream>
#include"Matriz.h"
namespace PG3 {

template <class type>
class Persistencia {
public:
	Persistencia(){};
	~Persistencia(){};
	void gravar(Matriz<type> const &matriz, std::string const &nomeDoArquivoNoDisco)const;
	Matriz<type> * recuperar(std::string const &nomeDoArquivoNoDisco)const;
	void apagar(std::string const &nomeDoArquivo)const;
};

template <class type>
void Persistencia<type>::gravar(Matriz<type> const &matriz, std::string const &nomeDoArquivoNoDisco)const{
	std::ofstream arquivoMatriz(nomeDoArquivoNoDisco.c_str());
try{

	if(!arquivoMatriz.is_open()) throw(4);//arquivo nao pode ser aberto
	int linha  = matriz.getQuantidadeLinhas();
	int coluna = matriz.getQuantidadeColunas();
	arquivoMatriz<<linha<<std::endl;
	arquivoMatriz<<coluna<<std::endl;
	for(int i=0; i<linha; i++)
		for(int j=0; j<coluna; j++){
	   		type elemento = matriz.getElemento(i,j);
	   		arquivoMatriz<<elemento<<std::endl;
	   	}
	arquivoMatriz.close();


	}catch(int valorErro){
		if(valorErro != 4)
		arquivoMatriz.close();
		throw valorErro;

	}
}

template <class type>
Matriz<type> *Persistencia<type>::recuperar(std::string const &nomeDoArquivoNoDisco)const{

	std::ifstream arquivoMatriz(nomeDoArquivoNoDisco.c_str());
	Matriz<type> *matriz;

	try{

		if(!arquivoMatriz.is_open()) throw(4);//arquivo nao pode ser aberto

		int linha, coluna;
		type elemento;
		arquivoMatriz>>linha;
		arquivoMatriz>>coluna;
		matriz = new Matriz<type>(linha,coluna);
		for(int i=0; i<linha; i++)
			for(int j=0; j<coluna; j++){
				arquivoMatriz>>elemento;
				matriz->setElemento(i,j,elemento);
			}
		arquivoMatriz.close();
		return matriz;

	}catch(int valorErro){
		//if(matriz)delete matriz;
		if(valorErro != 4)
		arquivoMatriz.close();
		throw valorErro;
	}catch(std::bad_alloc&){
		arquivoMatriz.close();
		throw(0);
	}


}

template <class type>
void Persistencia<type>::apagar(std::string const &nomeDoArquivo)const{

		if( std::remove(nomeDoArquivo.c_str()) )
			throw (7);//Arquivo nao pode ser deletado
	}

}

#endif /* PERSISTENCIA_H_ */
