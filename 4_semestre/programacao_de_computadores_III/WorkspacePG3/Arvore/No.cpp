/*
 * No.cpp
 *
 *  Created on: 19/09/2010
 *      Author: jolimpiof
 */

#include "No.h"
using namespace std;

No::No() {
	chave = 0;
	nome.clear();
	esq = dir = 0;
}

int No::getChave() {
	return this->chave;
}

bool No::setChave(int pChave) {
	if(pChave > 0) {	this->chave = pChave;	return true;}
	else {	this->chave = 0;		return false;}
}

string No::getNome() {
	return this->nome;
}

bool No::setNome(string pNome) {
	this->nome = pNome;	return true;
}

No* No::getEsq() {
	return this->esq;
}

void No::setEsq(No *pEsq) {
	this->esq = pEsq;
}

No* No::getDir() {
	return this->dir;
}

void No::setDir(No *pDir) {
	this->dir = pDir;
}

No::~No() {
	// TODO Auto-generated destructor stub
}
