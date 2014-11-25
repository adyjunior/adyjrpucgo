/*
 * Cone.cpp
 *
 *  Created on: 18/09/2009
 *      Author: jUniN C.Z.N
 */
#include"Cone.h"
#define PI 3.14
#include<cmath>



void Cone::setRaio(float r)
{
	raio=r;
}

void Cone::setAltura(float l)
{
	altura=l;
}

float Cone::getGeratriz()
{
	return (sqrt((altura*altura)+(raio*raio)));

}



float Cone::getAreaLateral(){
	return (PI*raio*geratriz);
}

float Cone::getArea(){
	return (PI*raio*(geratriz+raio));
}

float Cone::getVolume(){
	return ((0.33)*PI*raio*raio*altura);
}
