/*
 * Data.h
 *
 *  Created on: 05/10/2009
 *      Author: jUniN C.Z.N
 */

#ifndef DATA_H_
#define DATA_H_
#include<string>
class Data
{
private:
	int dia,mes,ano;

public :
	Data(int d, int m, int a){
		dia=d;
		mes=m;
		ano=a;
	}
	~Data(){}

	int getDia()const{return dia;};
	int getMes()const{return mes;};
	int getAno()const{return ano;};

	//void Data::setDia(int d);
	//void Data::setMes(int m);
	//void Data::setAno(int a);

	static bool valdiar(int d, int m, int a)
	{
			if(a>0){
					if( ((d>0)&&(d<32)) && ((m>0)&&(m<13)) )
							return true;
					else
							return false;
					}

				else
					return false;

	}


	static bool testefev(int d,int m,int a)
	{
		if(m==2)
				{
						if(( ((a%4)==0) && ( ((a%100)!=0) || ((a%400)==0) ) ))
						{
						if(d<30)
							return true;
						else
							return false;
						}


						else{
							if(d<29)
								return true;
							else
								return false;
							}
				}
		else
			return true;


	}
	static bool mes31(int d,int m, int a)
	{
		if((((m==4)&&(d<31))||((m==6)&&(d<31))||((m==9)&&(d<31))||((m==11)&&(d<31))) )
					return true;
		else{
			if(m>0)
				return true;
			else
				return false;
			}




	}
	int getCalculoSemana();
	std::string getMesExtenso();
	std::string diaDaSemana();
};

#endif /* DATA_H_ */
