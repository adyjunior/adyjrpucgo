/*
 * Main.cpp
 *
 *  Created on: 18/09/2009
 *      Author: jUniN C.Z.N
 */

#include"Cone.h"
#include<iostream>
#define PI 3.14

using namespace std;

int main ()
{
	float a=-1,b=-1;

while(!Cone::cValido(a,b))
	{
	cout<<"Digite o Raio\n";
	cin>>a;

	cout<<"Digite a Altura\n";
	cin>>b;

		if((a<0)||(b<0))
		{
			cout<<"Valores invalidos , Digite novamente\n\n";
		}

	}
		Cone C;

		C.setRaio(a);
		C.setAltura(b);

		cout<<"O Valor da Geratriz eh "<<C.getGeratriz()<<endl;
		cout<<"O Valor da Area Lateral eh "<<C.getAreaLateral()<<endl;
		cout<<"O Valor da Area Total eh "<<C.getArea()<<endl;
		cout<<"O Valor do Volume eh "<<C.getVolume()<<endl;




}
