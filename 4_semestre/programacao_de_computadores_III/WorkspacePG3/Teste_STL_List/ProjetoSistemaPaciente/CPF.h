/*
 * CPF.h
 *
 *  Created on: 31/03/2010
 *      Author: eugenio
 */

#ifndef CPF_H_
#define CPF_H_

namespace PG2 {

class CPF {
//Atributos
private:
	long long int numero;

//Metodos
public:
	CPF(){numero = 00000000000;}
	~CPF(){};
	void set(long long int numero);
	long long int get()const{return numero;}
	static bool validar(long long int numero);
};

}

#endif /* CPF_H_ */
