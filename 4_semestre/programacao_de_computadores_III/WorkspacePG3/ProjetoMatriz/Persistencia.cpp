#include "Persistencia.h"

namespace PC3 {

void Persistencia::gravar(Matriz const &matriz, std::string const &nomeDoArquivoNoDisco)const{
	std::ofstream arquivoMatriz(nomeDoArquivoNoDisco.c_str());
try{

	if(!arquivoMatriz.is_open()) throw(4);//arquivo nao pode ser aberto
	int linha  = matriz.getQuantidadeLinhas();
	int coluna = matriz.getQuantidadeColunas();
	arquivoMatriz<<linha<<std::endl;
	arquivoMatriz<<coluna<<std::endl;
	for(int i=0; i<linha; i++)
		for(int j=0; j<coluna; j++){
	   		int elemento = matriz.getElemento(i,j);
	   		arquivoMatriz<<elemento<<std::endl;
	   	}
	arquivoMatriz.close();


	}catch(int valorErro){
		if(valorErro != 4)
		arquivoMatriz.close();
		throw valorErro;

	}
}

Matriz *Persistencia::recuperar(std::string const &nomeDoArquivoNoDisco)const{

	std::ifstream arquivoMatriz(nomeDoArquivoNoDisco.c_str());

	try{

		if(!arquivoMatriz.is_open()) throw(4);//arquivo nao pode ser aberto
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

	}catch(int valorErro){
		if(valorErro != 4)
		arquivoMatriz.close();
		throw valorErro;
	}catch(std::bad_alloc&){
		arquivoMatriz.close();
		throw(0);
	}


}

void Persistencia::apagar(std::string const &nomeDoArquivo)const{
	//try{
		if( std::remove(nomeDoArquivo.c_str()) )
			throw (7);//Arquivo nao pode ser deletado
	//}catch(int valorErro){
		//throw valorErro;
	//}
}

}
