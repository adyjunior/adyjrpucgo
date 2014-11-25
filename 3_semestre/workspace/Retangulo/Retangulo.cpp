/*
 * Retangulo.cpp
 *
 *  Created on: 18/09/2009
 *      Author: jUniN C.Z.N
 */
#include"Retangulo.h"


void Retangulo::setComprimento(float c)
{
	comprimento=c;
}

void Retangulo::setLargura(float l)
{
	largura=l;
}

float Retangulo::getArea()const{
	return (largura*comprimento);
}

float Retangulo::getPerimetro()const{
	return (2*largura+2*comprimento);
}


