/*
 * Cilindro.cpp
 *
 *  Created on: 20/09/2009
 *      Author: jUniN C.Z.N
 */

#include"Cilindro.h"

#define PI 3.14

void Cilindro::setRaio(float r)
{
	raio=r;
}

void Cilindro::setAltura(float l)
{
	altura=l;
}

float Cilindro::getAreaLateral()const
{
	return (2*PI*raio*altura);
}

float Cilindro::getArea()const
{
	return(2*PI*raio*(altura+raio));
}

float Cilindro::getVolume()const
{
	 return (PI*raio*raio*altura);
}
