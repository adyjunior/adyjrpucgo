#ifndef ERRO_H_
#define ERRO_H_

#include<string>
#include<stdexcept>
#include <fstream>

namespace PG3 {

class Erro {
private:
	std::string *strErro;
	static Erro *instancia;
	Erro(int opcao);


public:
	~Erro(){if(strErro) delete[]strErro;if(instancia)delete instancia;}
	std::string getErro(int erro)const{return strErro[erro];}
	static Erro *getInstancia(int opcao){
		try{
			if(!instancia)	instancia = new Erro(opcao);
			return instancia;
		}catch(std::logic_error a){
				throw a;
		}
		catch(std::bad_alloc&){
			throw (std::logic_error) ("Memoria insuficiente para criacao do arquivo de ERROS");
		}
	}

};

}

#endif /* ERRO_H_ */
