#ifndef ARVOREAVL_H_
#define ARVOREAVL_H_
#include "No.h"

class ArvoreAVL {
	private:
		No* Root;
		int Contador;
	public:
		ArvoreAVL();
		virtual ~ArvoreAVL();
		No* getRoot();
		int getContador();
		bool push(No** Raiz, No* P);
		bool pop(No** Raiz, No** P, float K);
		No* busca(No* Raiz, float K);
		void RSE(No** Raiz);
		void RSD(No** Raiz);
		void RDE(No** Raiz);
		void RDD(No** Raiz);
		bool inserir(Elemento Dado);
		bool excluir(No** P, float K);
		No* sucessor(No** Raiz);
		void listar(No* Raiz);
		void imprimirPreOrdem(No* Raiz);
		void imprimirPosOrdem(No* Raiz);
		bool eVazia();
};

#endif
