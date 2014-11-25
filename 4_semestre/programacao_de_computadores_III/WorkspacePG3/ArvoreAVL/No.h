#ifndef NO_H_
#define NO_H_
#include <iostream>
#include "Elemento.h"

using namespace std;

class No {
	private:
		Elemento EL;
		No* PtLeft;
		No* PtRight;
		int Bal;
	public:
		No(Elemento Dado);
		virtual ~No();
		void setEL(Elemento Dado);
		void setPtLeft(No* PTR);
		void setPtRight(No* PTR);
		void setBal(int B);
		Elemento getEL();
		No* getPtLeft();
		No* getPtRight();
		No** getPttLeft();
		No** getPttRight();
		int getBal();
		static No* MontaNo(Elemento Dado);
		Elemento DesmontaNo();
		void print();
};

#endif
