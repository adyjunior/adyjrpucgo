#include "No.h"
#include <iomanip>

No::No(Elemento Dado) {
	EL = Dado;
	PtLeft = NULL;
	PtRight = NULL;
	Bal = 0;
}

No::~No() {
	delete PtLeft;
	delete PtRight;
}

void No::setEL(Elemento Dado) {
	EL = Dado;
}

void No::setPtLeft(No* PTR) {
	PtLeft = PTR;
}

void No::setPtRight(No* PTR) {
	PtRight = PTR;
}

void No::setBal(int B) {
	Bal = B;
}

Elemento No::getEL() {
	return EL;
}

No* No::getPtLeft() {
	return PtLeft;
}

No* No::getPtRight() {
	return PtRight;
}

No** No::getPttLeft() {
	return& PtLeft;
}

No** No::getPttRight() {
	return& PtRight;
}

int No::getBal() {
	return Bal;
}

No* No::MontaNo(Elemento Dado) {
	return new No(Dado);
}

Elemento No::DesmontaNo() {
	return EL;
}

void No::print() {
	//cout << fixed << setprecision(1) << EL.getPosicao() << " ";
	cout << EL.getPosicao() << " ";
}
