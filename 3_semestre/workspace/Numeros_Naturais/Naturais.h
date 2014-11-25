/*
 * Naturais.h
 *
 *  Created on: 13/11/2009
 *      Author: jUniN C.Z.N
 */

#ifndef NATURAIS_H_
#define NATURAIS_H_

class Naturais
{
private:
	int numero;
	int numero2;

public:
	Naturais(int n){
		numero=n;
	};
	~Naturais(){};

	static bool setnaturais(int n)
	{
		if(n>0)
			return true;
		else
			return false;
	}

	int getFatorial()const;//pronto pra teste

	bool getNPerfeito()const;//pronto pra teste

	bool getCapicua()const;//pronto pra teste

	bool getQuadrado()const;//pronto pra teste

	bool getPrimo()const;//pronto pra teste

	int getBase()const;

	int getMdc()const;

	int getMmc()const;

	bool getPrimo2()const;





};




#endif /* NATURAIS_H_ */
