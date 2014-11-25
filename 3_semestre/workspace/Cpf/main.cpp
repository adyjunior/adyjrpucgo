/*
 * main.cpp
 *
 *  Created on: 21/10/2009
 *      Author: jUniN C.Z.N
 */
#include<iostream>
#include"Cpf.h"
#include<stdio.h>


using namespace std;

int main()
{
	string a;
	string* a2=&a;

	do
	{
	cout<<"Digite o seu CPF\n";
	cin>>a;

	if(Cpf::validar(a2))
		cout<<"O CPF eh Valido\n";
	else
		cout<<"O CPF eh Invalido , digite novamente\n";
	//printf("|%-20s|%-30s|%-30s|\n","Caracteristicas","Numero1","Numero2");
	//cout<<"|____________________|______________________________|______________________________|\n";


	}while(!(Cpf::validar(a2)));

/*
	Cpf pessoa;

	pessoa.setCpf(a);



	cout<<"CPF Valido"<<pessoa.getCpf()<<endl;

*/

}
