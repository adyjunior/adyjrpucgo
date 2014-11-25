/*
 * Main.cpp
 *
 *  Created on: 18/09/2009
 *      Author: jUniN C.Z.N
 */

#include"Retangulo.h"
#include<iostream>

using namespace std;

int main()
{
	float a=-1,b=-1;



	while(!Retangulo::Rvalido(a,b))
	{

	cout<<"Digite o Comprimento\n";
	cin>>a;

	cout<<"Digite a Largura\n";
	cin>>b;

	if((a<0)||(b<0))
		cout<<"valor invalido , Digite novamente\n";
	}

		Retangulo R;

		R.setComprimento(a);
		R.setLargura(b);

		cout<<"O Valor do Perimetro eh "<<R.getPerimetro()<<endl;
		cout<<"O Valor da Area eh "<<R.getArea()<<endl;





}
