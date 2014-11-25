#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<iostream>
#include <iomanip>
#include"Matriz.h"
#include"Controle.h"
#include"ERROS.h"
namespace PC3 {

class Interface {
private:
	Controle ctrl;
	ERROS *erro;
public:
	Interface(){};
	~Interface(){};
	void lerMatriz(Matriz &matriz)const;
	void escreverMatriz(Matriz const &matriz)const;
	void menuPrincipal();
	void persistirMatrizes();
	void operacoesMatrizes()const;
	Matriz *recuperar()const;
};

}

#endif /* INTERFACE_H_ */
