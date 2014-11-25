#include<iostream>
#include"Lista.h"

using std::cout;
using std::cin;
using std::endl;

namespace Junior {
void Lista::imprime(){
	for (int i = this->primeiro; i < this->ultimo; i++)
	cout << this->item[i] << endl;
}
Lista::Lista (){
	this->item = new int[1000]; this->maxTam = 1000;
	this->pos = -1;
	this->ultimo = this->primeiro = 0;
}


Lista::Lista (int maxTam){
	this->item = new int[maxTam]; this->maxTam = maxTam;
	this->pos = -1;
	this->ultimo = this->primeiro = 0;
}

int Lista::pesquisa (const int& chave)const {
	if (this->vazia ()) throw std::string("Lista Vazia");
	for (int p = 0; p < this->ultimo; p++)
		if (this->item[p] == chave) return p;
	return -1;
}
void Lista::add(const int& x) {
	if (this->ultimo >= this->maxTam)
		throw std::string("Lista cheia");
	else {
		this->item[this->ultimo] = x;
		this->ultimo = this->ultimo + 1; }
}


bool Lista::remove(const int& chave, int &item) {
	if (this->vazia ())
		throw std::string("Lista Vazia");

	int p = this->primeiro;
	while (p < this->ultimo && !(this->item[p] == chave)) p++;
	if (p >= this->ultimo) return false; // Chave não encontrada
	item = this->item[p];
	this->item[p] = 0; // transfere a posse da memória
	this->ultimo = this->ultimo - 1;
	for (int aux = p; aux < this->ultimo; aux++)
		this->item[aux] = this->item[aux + 1];
	return true;

}

int Lista::retiraPrimeiro () {
	if (this->vazia ())
		throw std::string("Lista Vazia");

	else {int item = this->item[0];
	this->item[0] = 0; // transfere a posse da memória
	this->ultimo = this->ultimo - 1;
	for (int aux = 0; aux < this->ultimo; aux++)
		this->item[aux] = this->item[aux + 1];
	return item;}
}

int Lista::_primeiro (){
	int item=0;
	this->pos = -1; item = this->proximo (item);
	return item;
}

bool Lista::proximo(int &item) {
	this->pos++;
	if (this->pos >= this->ultimo) return false;
	else item = this->item[this->pos];
	return true;
}

bool Lista::vazia ()const{
	return (this->primeiro == this->ultimo);}

}


