/*
 * Principal.cpp
 *
 *  Created on: 21/09/2009
 *      Author: jUniN C.Z.N
 */
#include<iostream>
#include<cmath>
#include"Triangulo.h"

using namespace std;

int main()
{
float a,b,c;

Triangulo t(a,b,c);

cout<<"Digite o Valor do lado a \n";
cin>>a;

cout<<"Digite o Valor do lado b \n";
cin>>b;

cout<<"Digite o Valor do lado c \n";
cin>>c;

if((a+b>c)||(a+c>b)||(b+c>a))
{
	cout<<"O Triangulo eh"<<t.getTipoLado()<<" e "<<t.getTipoAngulo()<<endl;
	cout<<"A area do Triangulo eh "<<t.getArea()<<endl;

	}
else
	cout<<"Não eh Triangulo\n";



}
