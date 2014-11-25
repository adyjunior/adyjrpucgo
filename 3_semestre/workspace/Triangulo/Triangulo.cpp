/*
 * Triangulo.cpp
 *
 *  Created on: 21/09/2009
 *      Author: jUniN C.Z.N
 */

#include"Triangulo.h"
#include<cmath>



void Triangulo::setladoa(float la)
{
	ladoa =la;
}

void Triangulo::setladob(float lb)
{
	ladob=lb;
}

void Triangulo::setladoc(float lc)
{
	ladoc=lc;
}

std::string Triangulo::getTipoLado()
{
	if(ladoa<ladob+ladoc && ladob<ladoa+ladoc && ladoc<ladoa+ladob){

		if (ladoa != ladob && ladob!= ladoc){
			return "Escaleno";
			}
		else if (ladoa == ladob && ladob == ladoc){
			return "Equilatero";
		}
		else
			return "Isosceles";
		}

}

std::string Triangulo::getTipoAngulo(){
	if(ladoa<ladob+ladoc && ladob<ladoa+ladoc && ladoc<ladoa+ladob){

	if (ladoa*ladoa == ladob*ladob + ladoc*ladoc){
	return "Retangulo";
	}

	else if (ladoa*ladoa < ladob*ladob + ladoc*ladoc){
	return "Acutangulo";
	}

	else
	return "Obtusangulo";

	}
}
float Triangulo::getArea(){
	if (ladoa<ladob+ladoc && ladob<ladoa+ladoc && ladoc<ladoa+ladob){
	float T=(ladoa + ladob + ladoc) / 2;
	return (sqrt(T*(T-ladoa)*(T-ladob)*(T-ladoc)));
	}
}
