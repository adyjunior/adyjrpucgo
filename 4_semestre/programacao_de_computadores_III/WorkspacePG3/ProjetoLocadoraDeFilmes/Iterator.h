#ifndef ITERATOR_H_
#define ITERATOR_H_
#include<list>

#include <iostream>

using namespace std;

namespace Container {
template <class type>
class Iterator {
private:
        std::list<type> lista;
        //std::list<type>::const_iterator it;
        typename std::list<type>::const_iterator it;
public:
        Iterator(std::list<type> lista);//this->lista.sort();}
        //Iterator(Iterator<type> IT,int);
        Iterator(){it = this->lista.begin();}
        ~Iterator();
        int size();
        type primeiro()const;
        type proximo();
        bool existeProximo()const;
        type itemAtual();
        //void operator = (Iterator<type>* itCopia);


};




template<class type>
Iterator<type>::Iterator(std::list<type>  lista){
        if(lista.empty())throw(14);
        //this->lista = lista;
        typename std::list<type>::const_iterator indice;


        for(indice = lista.begin();!(indice == lista.end());indice++){
                this->lista.push_back(*indice);
        }

        it = this->lista.begin();


}

template<class type>
Iterator<type>::~Iterator(){


        typename std::list<type>::const_iterator indice;
        for(indice = lista.begin();!(indice == lista.end());indice++){
                delete *indice;
                lista.pop_back();
        }

}

/*template<class type>
Iterator<type>::Iterator(Iterator<type> IT,int l){
        //if(IT.lista.empty())throw(13);
        //IT.it = IT.lista.begin();
        this->it = IT.it;
        this->lista = IT.lista;
}*/

template<class type>
int Iterator<type>::size(){
   return this->lista.size();
}

template<class type>
type Iterator<type>::primeiro()const{
        typename std::list<type>::const_iterator aux;
        aux = lista.begin();
        return  *aux;
}

template <class type>
type Iterator<type>::proximo(){

        //it++;
        return *(++it);

}

template <class type>
bool Iterator<type>::existeProximo()const{

        typename std::list<type>::const_iterator aux; // crio um iterator auxiliar para receber o iterator IT
        aux = it;// aux recebe a posicao de IT da lista

        //aux++; // increventa AUX para chegar na proxima posicao

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
/*
template <class type>
void Iterator<type>::operator =(Iterator<type>* itCopia){
        this->it = itCopia->it;
        this->lista = itCopia->lista;


}*/



}

#endif /* ITERATOR_H_ */

