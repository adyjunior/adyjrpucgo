/*
 * Cpf.h
 *
 *  Created on: 17/11/2009
 *      Author: jUniN C.Z.N
 */

#ifndef CPF_H_
#define CPF_H_

#include<iostream>
#include<cstdlib>
#include<sstream>
#include<string>

using namespace std;

class Cpf
{
public:
	Cpf(){};
	~Cpf(){};

	static bool validar(string *cpf)
	{
		int i,j=10,soma1=0,soma2=0,multi,digito9,digito10,numero,resto1,resto2,verify1,verify2;


		istringstream sss(cpf->substr(9,1));
		sss >> digito9;

		istringstream ssss(cpf->substr(10,1));
		ssss >> digito10;

		for(i=0;i<9;i++)
		{
			istringstream ss(cpf->substr(i,1));
			ss >> numero;
			multi=numero*j;
			soma1=soma1+multi;
			j--;
		}


		j=11;
		multi=0;
		numero=0;
		for(i=0;i<10;i++)
		{
			istringstream ss(cpf->substr(i,1));
			ss >> numero;
			multi=numero*j;
			soma2=soma2+multi;
			j--;
		}

		resto1=soma1%11;
		resto2=soma2%11;

		if(resto1<2)
			verify1=0;
		else
			verify1=11-resto1;

		if(resto2<2)
			verify2=0;
		else
			verify2=11-resto2;


		//cout<<verify1<<"\t"<<digito9<<endl<<verify2<<"\t"<<digito10;

		if((verify1==digito9)&&(verify2==digito10))
			return true;
		else
			return false;






	}
};



#endif /* CPF_H_ */
