#ifndef ITERATOR_H_
#define ITERATOR_H_
#include<list>

namespace Container {
template <class type>
class Iterator {
private:
	std::list<type> lista;
	//std::list<type>::const_iterator it;
	typename std::list<type>::const_iterator it;
public:
	Iterator(std::list<type> lista){this->lista = lista; it = this->lista.begin();}//this->lista.sort();}
	Iterator(){it = this->lista.begin();}
	~Iterator(){};
	type primeiro()const;
	type proximo();
	bool existeProximo()const;
	type itemAtual();


};

template<class type>
type Iterator<type>::primeiro()const{
	typename std::list<type>::const_iterator aux;
	aux = lista.begin();
	return  *aux;
}

template <class type>
type Iterator<type>::proximo(){

	return *(++it);

}

template <class type>
bool Iterator<type>::existeProximo()const{

	typename std::list<type>::const_iterator aux; // crio um iterator auxiliar para receber o iterator IT
	aux = it;// aux recebe a posicao de IT da lista

	aux++; // increventa AUX para chegar na proxima posicao

	if(aux == this->lista.end()) return false; // se aux for igual a lista.end() significa que
											   //a lista acabou e nao existe proximo elemento

	return true; // se nao existe o proximo elemento;

}

template <class type>
type Iterator<type>::itemAtual(){
	typename std::list<type>::const_iterator aux; // crio um iterator auxiliar para receber o iterator IT
	aux = it;
	it++;

	return *aux;
}



}

#endif /* ITERATOR_H_ */

