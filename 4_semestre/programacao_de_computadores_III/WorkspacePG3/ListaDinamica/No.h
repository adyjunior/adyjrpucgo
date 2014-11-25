#ifndef NO_H_
#define NO_H_

namespace VilaNova {

class No {
private:
	No * anterior;
	No * proximo;
	int elemento;
public:
	No(){this->anterior=this->proximo=0;}
	~No(){};
	No *getAnterior() const{return anterior;}
	No *getProximo() const{return proximo;}
	void setAnterior(No *anterior){this->anterior = anterior;}
	void setProximo(No *proximo){this->proximo = proximo;}



	};




}

#endif /* NO_H_ */
