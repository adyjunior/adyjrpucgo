#ifndef LISTA_H_
#define LISTA_H_
#include<string>

namespace Junior {

class Lista {//lista de inteiros
private:
	int *item;
	int primeiro, ultimo, pos, maxTam;
public:
	Lista (); // Cria uma Lista vazia
	Lista (int maxTam); // Cria uma Lista vazia
	~Lista(){if(item)delete [] item; item = 0;}
	int getMaxtam()const{return maxTam;}
	int pesquisa(const int& chave)const;
	void add(const int& x);
	bool remove(const int& chave,int &item);
	int retiraPrimeiro ();
	int _primeiro ();
	bool proximo (int &item);
	bool vazia ()const;
	void imprime ();

};
}

#endif /* LISTA_H_ */
