#ifndef CONTROLE_H_
#define CONTROLE_H_
#include"Persistencia.h"
namespace PG3 {

template <class type>
class Controle {
private:
	Persistencia<type> persistir;
public:
	Controle(){};
	~Controle(){};
	void processoGravar(Matriz<type> const &matriz, std::string const &nomeDoArquivo)const;
	Matriz<type> *processoRecuperar(std::string const &nomeDoArquivo)const;
	void processoApagar(std::string const &nomeDoArquivoNoDisco)const;
};

template <class type>
void Controle<type>::processoGravar(Matriz<type> const &matriz, std::string const &nomeDoArquivo)const{
	try{
		if(matriz.getQuantidadeLinhas() != matriz.getQuantidadeColunas()) throw (5);//matriz nao eh quadrada
		std::string nomeDoArquivoNoDisco = /*"./DiretorioMatriz/" + */"DiretorioMatriz/"+nomeDoArquivo;
		persistir.gravar(matriz,nomeDoArquivoNoDisco);
	}catch(int valorErro){
		throw valorErro;
	}
}

template <class type>
Matriz<type> *Controle<type>::processoRecuperar(std::string const &nomeDoArquivo)const{
	try{
		std::string nomeDoArquivoNoDisco = /*"./DiretorioMatriz/" + */"DiretorioMatriz/"+nomeDoArquivo;
		return persistir.recuperar(nomeDoArquivoNoDisco);
	}
	catch(int valorErro){
		throw valorErro;
	}
}

template <class type>
void Controle<type>::processoApagar(std::string const &nomeDoArquivoNoDisco)const{
	try{
	persistir.apagar("DiretorioMatriz/"+nomeDoArquivoNoDisco);
	}catch(int valorErro){
		throw valorErro;
	}
}


}

#endif /* CONTROLE_H_ */
