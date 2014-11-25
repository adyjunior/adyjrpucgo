#ifndef LISTA_H_
#define LISTA_H_
#include"No.h"

namespace VilaNova {

class Lista {
private:
	No* primeiro;
	No* ultimo;
	No* atual;

public:
	Lista();
	~Lista();
	void inserir(int tipo);
};

}

#endif /* LISTA_H_ */
