/*
 * Main.cpp
 *
 *  Created on: 17/11/2009
 *      Author: jUniN C.Z.N
 */

#include"Cpf.h"

int main()
{
	string cpf;
	string* ponteiro=&cpf;


	do
	{
		cout<<"Digite o Cpf"<<endl;
		cin>>cpf;

		if(Cpf::validar(ponteiro))
			cout<<"Numero de CPF Valido"<<endl;
		else
			cout<<"CPF invalido , Digite novamente"<<endl;

	}
	while(!Cpf::validar(ponteiro));


}
