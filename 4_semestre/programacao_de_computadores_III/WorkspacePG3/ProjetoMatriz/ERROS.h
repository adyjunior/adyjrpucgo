#ifndef ERROS_H_
#define ERROS_H_

#include<string>
#include<stdexcept>
#include <fstream>
namespace PC3 {

class ERROS {
//Atributo
private:
		//int tamanho;
		std::string *strErro;
		static ERROS *instancia;
		void setIdioma(int opcao);
		ERROS(int op);
public:

	~ERROS(){if(strErro) delete[]strErro;if(instancia)delete instancia;}
	std::string getErro(int erro)const{return strErro[erro];}
	static ERROS *getInstancia(int opcao){
		try{
			if(!instancia)	instancia = new ERROS(opcao);
			instancia->setIdioma(opcao);
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

#endif /* ERROS_H_ */
