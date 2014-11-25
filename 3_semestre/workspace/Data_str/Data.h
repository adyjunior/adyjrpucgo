/*
 * Data.h
 *
 *  Created on: 23/10/2009
 *      Author: jUniN C.Z.N
 */

#ifndef DATA_H_
#define DATA_H_
#include<string>
#include<cstdlib>
#include<iostream>
#include<sstream>

class Data
{
private:
	int dia;
	int mes;
	int ano;

public:
	Data(std::string data)
	{
		if(data.size()==10)
				{
					dia= atoi(data.substr(0,2).c_str());
					mes= atoi(data.substr(3,2).c_str());
					ano= atoi(data.substr(6,4).c_str());

				}
				else{
						if(data.size()==9)
						{
							if((data[1]=='/')&&(data[4]=='/'))
							{
								dia=atoi(data.substr(0,1).c_str());
								mes=atoi(data.substr(2,2).c_str());
								ano=atoi(data.substr(5,4).c_str());
							}
							else{
									if((data[2]=='/')&&(data[4]=='/'))
									{
										dia=atoi(data.substr(0,2).c_str());
										mes=atoi(data.substr(3,1).c_str());
										ano=atoi(data.substr(5,4).c_str());
									}
								}
						}
						else{
								if(data.size()==8)
								{
									dia=atoi(data.substr(0,1).c_str());
									mes=atoi(data.substr(2,1).c_str());
									ano=atoi(data.substr(4,4).c_str());
								}

						}

					}
	}





	~Data(){};


	void setData(std::string data)
	{

	}


	int getDia()const{return dia;};
	int getMes()const{return mes;};
	int getAno()const{return ano;};

	static bool validar(int d, int m, int a)
		{
			if (d<=0 || d>31 || m<=0 || m>12 || a<=0) return false;
			if (d>=1 && d<=28 && m>=1 && m<=12) return true;
			if (d>=29 && d<=31 && (m == 3 || m == 5 || m == 7 || m == 8 ||
					m == 10 || m == 12))return true;
			if (d>=29 && d<=30 && (m == 1 || m == 4 || m == 6 || m == 9 ||
					m == 11)) return true;
			if (d==29 && m == 2 && (a%400==0 || (!(a%100==0 && a%400 != 0) &&
					(a%4==0 && a%100!=0))))	return true;

			return false;
		};


	static bool validar(std::string data)
	{		int d,m,a;
			if(data.size()==10)
			{
				d=atoi(data.substr(0,2).c_str());
				m=atoi(data.substr(3,2).c_str());
				a=atoi(data.substr(6,4).c_str());
				return Data::validar(d,m,a);
			}
			else{
					if(data.size()==9)
					{
						if((data[1]=='/')&&(data[4]=='/'))
						{
							d=atoi(data.substr(0,1).c_str());
							m=atoi(data.substr(2,2).c_str());
							a=atoi(data.substr(5,4).c_str());
							return Data::validar(d,m,a);
						}
						else{
								if((data[2]=='/')&&(data[4]=='/'))
								{
									d=atoi(data.substr(0,2).c_str());
									m=atoi(data.substr(3,1).c_str());
									a=atoi(data.substr(5,4).c_str());
									return Data::validar(d,m,a);
								}
							}
					}
					else{
							if(data.size()==8)
							{
								d=atoi(data.substr(0,1).c_str());
								m=atoi(data.substr(2,1).c_str());
								a=atoi(data.substr(4,4).c_str());
								return Data::validar(d,m,a);
							}
							else return false;

						}

				}
		}


		int getCalculoSemana()const;
		std::string getMesExtenso();
		std::string diaDaSemana();


		std::string getDDMMAAAA();
		std::string getMMDDAAAA();
		std::string getDDMMAA();
		std::string getMMDDAA();
		std::string getDDmesAAAA();
		std::string getDiasemanaDDmesAAAA();
		std::string getDiasemanaDDMMAAA();


};


#endif /* DATA_H_ */
