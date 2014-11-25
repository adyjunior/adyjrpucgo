#ifndef ARVOREBINARIA_H_
#define ARVOREBINARIA_H_

# include <iostream>
# include <queue>
#include <stl_queue.h>

using namespace std;

class No {
   public :
	int valor;
    No *direito, *esquerdo;
    No ();
    No (int);
};

No :: No () {
	this->direito = this->esquerdo = NULL;
}

No :: No(int valor) {
	this->valor = valor;
	this->direito = this->esquerdo = NULL;
}

class ArvoreBinaria {
	protected :
		No *raiz;
		int Busca (No*, int);
		void PreOrdem (No*);
		void EmOrdem (No*);
		void PosOrdem (No*);
		int remove (No*,int);
		void percursoEmLargura(No *);
		int Altura (No*);
		int Nivel (No*, int, int);
 	public    :
		ArvoreBinaria ();
		int Altura ();
		int Nivel (int);
		bool Vazio ();
		int Busca (int);
		void insere (int);
		int remove (int);
		void percursoEmLargura();
		No* noMaior(No*);
		void PreOrdem ();
		void EmOrdem ();
		void PosOrdem ();

};

No* ArvoreBinaria :: noMaior(No *raiz){
       No *temp=NULL;
  
       temp = raiz;
  
       if(temp->direito== NULL){
           raiz = raiz->esquerdo;
           return temp;
       } else
           return noMaior(raiz->direito);
   }
  
int ArvoreBinaria :: Nivel(No *inicio, int valor, int nivel) {
       if (!inicio)
           return -1;
       else {
           if (valor == inicio->valor)
               return nivel;
           else {
               ++nivel;
  
               if (valor < inicio->valor)
                   nivel = Nivel (inicio->esquerdo, valor, nivel);
               else if (valor > inicio->valor)
                   nivel = Nivel (inicio->direito, valor, nivel);
           }
  
           return nivel;
       }
}

void ArvoreBinaria :: percursoEmLargura(No *inicio){
     No *temp = NULL;
     queue *auxFila = NULL;
     if(inicio != NULL){ // !inicio
         auxFila->push(inicio);
         while(auxFila->empty() != true){
             temp = auxFila->pop();
             if(temp->esquerdo != NULL)
                 auxFila->push(temp->esquerdo);
             if(temp->direito != NULL)
                 auxFila->push(temp->direito);
             cout << temp->valor<< endl;
         }
     }
 }

 void ArvoreBinaria :: percursoEmLargura() {
     return percursoEmLargura (this->raiz);
 }

 int ArvoreBinaria :: Nivel(int valor) {
     return Nivel (this->raiz, valor, 0);
 }

int ArvoreBinaria ::Altura(No *inicio) {
      if (!inicio)
          return -1;
     else {
         int alturaesquerda, alturadireita;
         alturaesquerda = Altura (inicio->esquerdo);
         alturadireita  = Altura (inicio->direito);

       if (alturaesquerda < alturadireita)
          return alturadireita + 1;
       else
          return alturaesquerda + 1;
     }
}

int ArvoreBinaria :: Altura() {
     return Altura (this->raiz)+1;
}

int ArvoreBinaria :: Busca (No *inicio, int valor) {
     while (inicio != NULL) {
         if (valor == inicio->valor)
             return inicio->valor;
         else if (valor < inicio->valor)
             inicio = inicio->esquerdo;
         else
             inicio = inicio->direito;
     }

     return 0;
}

void ArvoreBinaria  :: PreOrdem (No *inicio) {
     if (inicio != NULL) {
         this->PreOrdem (inicio->esquerdo);
          cout << inicio->valor << " ";
         this->PreOrdem (inicio->direito);
     }
}

void ArvoreBinaria :: EmOrdem (No *inicio) {
     if (inicio != NULL) {
         cout << inicio->valor << " ";
         this->EmOrdem (inicio->esquerdo);
         this->EmOrdem (inicio->direito);
     }
}

void ArvoreBinaria :: PosOrdem (No *inicio) {
     if (inicio != NULL) {
         this->PosOrdem (inicio->esquerdo);
         this->PosOrdem (inicio->direito);
         cout << inicio->valor << " ";
     }
}

ArvoreBinaria  :: ArvoreBinaria () {
    this->raiz = NULL;
}

bool ArvoreBinaria :: Vazio () {
     return this->raiz == NULL;
}

void ArvoreBinaria :: insere (int valor) {
     No *tmp = this->raiz;
     No *ant = NULL;

     while (tmp != NULL) {
         ant = tmp;

         if (tmp->valor < valor) {
             tmp = tmp->direito;
         }
         else {
             tmp = tmp->esquerdo;
         }
}

     if (this->Vazio()) {
         this->raiz = new No (valor);
     }
     else if (ant->valor < valor) {
         ant->direito = new No (valor);
     }
     else {
         ant->esquerdo = new No (valor);
     }
}

int ArvoreBinaria :: remove (No *raiz, int valor){
     No *temp = NULL;

     if(raiz == NULL)
         return 1;
     if(valor == raiz->valor){
         temp = raiz;
         if(raiz->esquerdo == NULL)
            raiz = raiz->direito;
         else
            if(raiz->direito == NULL)
                raiz = raiz->esquerdo;
            else{
                temp = noMaior(raiz->esquerdo);
                raiz->valor = temp->valor;
            }
         delete temp;
         return 0;
     } else if(valor < raiz->valor)
         return remove(raiz->esquerdo, valor);
     else
         return remove(raiz->direito, valor);
 }

int ArvoreBinaria :: remove (int valor){
     return remove (this->raiz, valor);
}

int ArvoreBinaria :: Busca (int valor){
      return Busca (this->raiz, valor);
}

void ArvoreBinaria :: PreOrdem () {
      PreOrdem (this->raiz);
}

void ArvoreBinaria :: EmOrdem () {
      EmOrdem (this->raiz);
}

void ArvoreBinaria :: PosOrdem () {
      PosOrdem (this->raiz);
}


#endif /* ARVOREBINARIA_H_ */
