/*
 * Cpf.h
 *
 *  Created on: 21/10/2009
 *      Author: jUniN C.Z.N
 */

#ifndef CPF_H_
#define CPF_H_

class Cpf
{
private:
	double cpf;


public :
	Cpf(){}
	~Cpf(){}
	//void setCpf(double c);
	//int getCpf()const{return cpf;};


	static bool validar(std::string *c)
	{
		int I,c2[11], J=11, c3[11],c4[11],c5[11],numero,cf1=0,cf2=0,cf3,cf4,cpf1[11],cpf2[11];


		numero=c->size();

		for(I=0;I<=numero;I++)
		{
			c2[I]=atoi(c->substr(I,1).c_str());
			cpf1[I]=c2[I];

		}

		for(I=0;I<10;I++)
		{
			c3[I]=J;
			cpf2[I]=c3[I];
				J--;
		}

		J=1;
		for(I=0;I<9;I++)
		{
			c4[I]=c2[I]*c3[J];

			cf1=cf1+c4[I];
			J++;
		}

		for(I=0;I<10;I++)
		{
			c5[I]=c2[I]*c3[I];

			cf2=cf2+c5[I];
		}




		cf3=cf1%11;

		cf4=cf2%11;




		if(cf3<2)
			cpf1[9]=0;
		else
			cpf1[9]=11-cf3;

		if(cf4<2)
			cpf2[10]=0;
		else
			cpf2[10]=11-cf4;


		//std::cout<<cpf1[9]<<"\t"<<c2[9]<<"\n\n"<<cpf2[10]<<"\t"<<c2[10]<<std::endl;


		if((cpf1[9]==c2[9])&&(cpf2[10]==c2[10]))
			return true;
		else
			return false;

	}
};

#endif /* CPF_H_ */
