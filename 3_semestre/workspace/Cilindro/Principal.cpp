/*
 * Principal.cpp
 *
 *  Created on: 20/09/2009
 *      Author: jUniN C.Z.N
 */

#include"Cilindro.h"
#include<iostream>

using namespace std;

int main()
{
	float a=-1,b=-1;

	while(!Cilindro::cValido(a,b))
	{
		cout<<"Digite o Valor do Raio\n";
			cin>>a;

			cout<<"Digite o Valor da Altura\n";
			cin>>b;

			if((a<0)||(b<0))
				cout<<"Valores invalidos , Digite Novamente\n\n";
	}






	Cilindro lata;


			lata.setRaio(a);
			lata.setAltura(b);


			cout<<"A Area Lateral eh "<<lata.getAreaLateral()<<endl;
			cout<<"A Area eh "<<lata.getArea()<<endl;
			cout<<"O Volume eh "<<lata.getVolume()<<endl;




}
