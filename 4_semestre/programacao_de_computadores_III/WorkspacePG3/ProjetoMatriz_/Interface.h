#ifndef INTERFACE_H_
#define INTERFACE_H_
#include"Matriz.h"
#include"Controle.h"

namespace VilaNova {

class Interface {
private:
	Controle controle;
public:
	Interface(){};
	~Interface(){};
	void lerMatriz(Matriz &matriz);
	void escreverMatriz(Matriz const &matriz);
	void menu01();// ok
	void menu011(); //menu011 ok
	void menu012(); //menu012
};

}

#endif /* INTERFACE_H_ */
