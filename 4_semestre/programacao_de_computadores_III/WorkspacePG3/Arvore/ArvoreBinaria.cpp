/*
 * ArvoreBinaria.cpp
 *
 *  Created on: 19/09/2010
 *      Author: jolimpiof
 */

#include "ArvoreBinaria.h"
#include <iostream>
using namespace std;

ArvoreBinaria::ArvoreBinaria() {
	raiz = 0;
}

No* ArvoreBinaria::pesquisa (int pChave, No *pNo) const
{
	if (pNo == NULL) return NULL; // N‹o encontrado
	else		if (pChave < pNo->getChave())
				return pesquisa(pChave, pNo->getEsq());
			else		if (pChave > pNo->getChave())
						return pesquisa(pChave, pNo->getDir());
					else return pNo;
}

No* ArvoreBinaria::insere(No *novo, No *pNo)
{
	if (pNo == 0) {
		pNo = novo;
		pNo->setEsq(0);
		pNo->setDir(0);
	}
	else		if (novo->getChave() < pNo->getChave())
				pNo->setEsq(this->insere(novo, pNo->getEsq()));
			else		if (novo->getChave() > pNo->getChave())
						pNo->setDir(this->insere(novo, pNo->getDir()));
					//else continue;
	return pNo;
}

No* ArvoreBinaria::antecessor (No *pNo, No *aNo)
{
  if (aNo->getDir() != 0) aNo->setDir(this->antecessor(pNo, aNo->getDir()));
  else {
    // Copia dos atributos do no antecessor (aNo) para o pNo
    pNo->setChave (aNo->getChave());
    pNo->setNome (aNo->getNome());
    // Remocao do no antecessor (aNo)
    No *aux = aNo; aNo = aNo->getEsq(); delete aux;
  }
  return aNo;
}

No* ArvoreBinaria::retira(int pChave, No *pNo) {
	if (pNo == 0) return 0;
	else		if (pChave < pNo->getChave())
				pNo->setEsq(this->retira (pChave, pNo->getEsq()));
			else		if (pChave > pNo->getChave())
						pNo->setDir (this->retira (pChave, pNo->getDir()));
					else
						if	(pNo->getDir() == 0) {
							No* aux = pNo; pNo = pNo->getEsq();
							delete aux;
						}
						else		if (pNo->getEsq() == 0) {
									No* aux = pNo;
									pNo = pNo->getDir();
									delete aux;
								}
								else pNo->setEsq(this->antecessor(pNo, pNo->getEsq()));

	return pNo;
}

No* ArvoreBinaria::getRaiz() {
	return this->raiz;
}

void ArvoreBinaria::setRaiz(No *pRaiz) {
	this->raiz = pRaiz;
}

void ArvoreBinaria::imprimeCentral(No *pNo) const {
	if (pNo != 0) {
		imprimeCentral (pNo->getEsq());
		cout << pNo->getChave() << endl;
		cout << pNo->getNome() << endl << endl;
		imprimeCentral (pNo->getDir());
	}
}

// MŽtodo para testar o funcionamento da classe
void ArvoreBinaria::testa(No *p) const {
  if (p == 0) return;
  if (p->getEsq() != 0) {
    if (p->getChave() < p->getEsq()->getChave())
      { cout << "Erro: Pai " << p->getChave();
        cout << " menor que filho a esquerda "<< p->getEsq()->getChave();
        exit(1);
      }
  }
  if (p->getDir() != 0) {
    if (p->getChave() > p->getDir()->getChave()) {
      cout << "Erro: Pai " << p->getChave();
      cout << " maior que filho a direita " << p->getDir()->getChave();
      exit(1);
    }
  }
  cout << p->getChave() << " " << p->getNome() << endl;
  testa(p->getEsq());
  testa(p->getDir());
}

ArvoreBinaria::~ArvoreBinaria() {
	while (this->getRaiz() != 0)
		this->setRaiz(this->retira(this->getRaiz()->getChave(), this->getRaiz()));
}
