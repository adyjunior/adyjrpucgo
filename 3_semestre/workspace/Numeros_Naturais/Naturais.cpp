/*
 * Naturais.cpp
 *
 *  Created on: 14/11/2009
 *      Author: jUniN C.Z.N
 */

#include"Naturais.h"
#include<cmath>
#include<sstream>
#include<cstdlib>

using namespace std;


int Naturais::getFatorial()const
{
	int i=0,fatorial=0;

	for(i=numero;i<0;i--)
	{
		fatorial=fatorial*i;
	}

	return fatorial;
}


bool Naturais::getPrimo()const
{
	int i,cont=0;
	for(i=1;i<9999;i++)
	{
		if((numero%i)==0)
			cont++;
	}

		if(cont>2)
			return false;
		else
			return true;

}

bool Naturais::getQuadrado()const
{
int x;
	x=sqrt(numero);

	//fmod(num,x)==0

	if(numero%x==0)
		return true;
	else
		return false;



}


bool Naturais::getNPerfeito()const
{
	int i=0,soma;

	for(i=0;i<numero;i++)
	{
		if(numero%i==0)
			soma=soma+numero;
	}


	if(soma==numero)
		return true;
	else
		return false;
}

bool Naturais::getCapicua()const
{

	int a[10],b[10],j=0,tam,i,cont=0;

	string c;
	stringstream x;


	x << numero;

	c=x.str();

	tam=c.size();
	for(i=0;i<tam;i++)
	a[i]=atoi(c.substr(i,1).c_str());

	for(i=tam-1;j<=tam-1;i--)
		{
		b[j]=a[i];

		if(b[j]==a[j])
			cont++;

		j++;
		}

		if(cont==tam)
			return true;
		else
			return false;


}







