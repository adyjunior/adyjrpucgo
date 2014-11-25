/*
 * Main.cpp
 *
 *  Created on: 18/09/2009
 *      Author: jUniN C.Z.N
 */
#include<iostream>
#include"Esfera.h"

using namespace std;
int main()
{
	float a=-1;

	while(!Esfera::eValido(a))
	{
	cout<<"Digite o Valor do Raio\n";
	cin>>a;

	if(a<0)
		cout<<"Valor invalido , Digite novamente\n\n";
	}

		Esfera bola;
		bola.setRaio(a);


		cout<<"Area eh "<<bola.getArea()<<endl;
		cout<<"Volume eh "<<bola.getVolume()<<endl;




}
