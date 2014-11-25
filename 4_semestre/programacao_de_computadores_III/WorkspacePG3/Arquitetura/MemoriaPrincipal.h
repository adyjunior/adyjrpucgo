#ifndef MEMORIAPRINCIPAL_H_
#define MEMORIAPRINCIPAL_H_
#include"Endereco.h"
#include<string>
#define SIZE 100
namespace Capsula {

class MemoriaPrincipal {
private:
	static Endereco *memoria;
	static int indeceDeUso;


public:
	MemoriaPrincipal(){};
	~MemoriaPrincipal(){};
	static std::string getMemoria(int endereco);
	static void setMemoria(int endereco,std::string dado);
	static int getIndeceDeUso(){return indeceDeUso;}
	//void operator=(MemoriaPrincipal memoria);

};

}

#endif /* MEMORIAPRINCIPAL_H_ */
