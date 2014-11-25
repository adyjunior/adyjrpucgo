/*
 * ArvoreBinaria.h
 *
 *  Created on: 19/09/2010
 *      Author: jolimpiof
 */

#ifndef ARVOREBINARIA_H_
#define ARVOREBINARIA_H_

#include "No.h"

class ArvoreBinaria {
private:
	No *raiz;
public:
	ArvoreBinaria();
	No* pesquisa (int pChave, No *pNo) const;
	No* insere(No *novo, No *pNo);
	No* antecessor (No *pNo, No *aNo);
	No* retira (int pChave, No *pNo);
	No* getRaiz();
	void setRaiz (No *pRaiz);
	void imprimeCentral (No *pNo) const;
	void testa (No *p) const;
	virtual ~ArvoreBinaria();
};

#endif /* ARVOREBINARIA_H_ */
