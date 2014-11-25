/*
 * CDC.h
 *
 *  Created on: 27/04/2010
 *      Author: eugenio
 */

#ifndef CDC_H_
#define CDC_H_
#include<string>
#include<cmath>
#include<iostream>

namespace CadeiaCaracteres {
// Classe Testada
class CDC {
public:
	static int 		converteStrParaInteiro(std::string const &str);
	static long		converteStrParaInteiroLongo(std::string const &str);
	static float 	converteStrParaReal(std::string const &str);
	static long long converteStrParaInteiroLongoLongo(std::string const &str);

	static std::string converteInteiroParaStr(int numero);
	static std::string converteInteiroLongoParaStr(long numero);
	static std::string converteInteiroLongoLongoParaStr(long long numero);
	static std::string converteRealParaStr(float numero);

	static std::string buscarSubString(std::string const &str, unsigned int &pos, char caracter);

	static void converteStringParaMaiuscula(std::string &str);
	static void converteStringParaMinuscula(std::string &str);
};

}

#endif /* CDC_H_ */
