/*
 * main.cpp
 *
 *  Created on: 05/10/2009
 *      Author: jUniN C.Z.N
 */

#include"Data.h"
#include<iostream>
#include<cstdlib>
#include<string>


using namespace std;

int main()
{
int dd=-1,mm=-1,aa=-1;
char finalizar;

do{
			while(!(Data::valdiar(dd,mm,aa)))
			{
				cout<<"Digite o Dia\n";
				cin>>dd;




				cout<<"Digite o mes\n";
				cin>>mm;




				cout<<"Digite o Ano\n\n";
				cin>>aa;
				if(mm==2)
				{
						if(!(Data::testefev(dd,mm,aa)))
						{
							dd=-1;
							mm=-1;
							aa=-1;
						}

				}
				else
					if(!(Data::mes31(dd,mm,aa)))
					{
						dd=-1;
						mm=-1;
						aa=-1;

					}


				if(! (Data::valdiar(dd,mm,aa)) )
					cout<<"Data invalida Digite Novamente\n\n";



			}





	Data d(dd,mm,aa);

	//d.setDia(dd);
	//d.setMes(mm);
	//d.setAno(aa);

	int aano=d.getAno()%1000;

	if ((d.getAno()<1000)||((d.getAno()%1000)>100))
			aano=d.getAno()%100;

	cout<<"As datas são:\n\n";

	if((d.getAno()%1000)<10)
	{

		cout<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
		cout<<d.getMes()<<"/"<<d.getDia()<<"/"<<d.getAno()<<endl;
		cout<<d.getDia()<<"/"<<d.getMes()<<"/0"<<aano<<endl;
		cout<<d.getMes()<<"/"<<d.getDia()<<"/0"<<aano<<endl;
		cout<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
		cout<<d.diaDaSemana()<<", "<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
		cout<<d.diaDaSemana()<<", "<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
	}
	else{

		if((d.getAno()%1000)<100)
		{
			cout<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
			cout<<d.getMes()<<"/"<<d.getDia()<<"/"<<d.getAno()<<endl;
			cout<<d.getDia()<<"/"<<d.getMes()<<"/"<<aano<<endl;
			cout<<d.getMes()<<"/"<<d.getDia()<<"/"<<aano<<endl;
			cout<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
			cout<<d.diaDaSemana()<<", "<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
			cout<<d.diaDaSemana()<<", "<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
		}

		else{


			cout<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
			cout<<d.getMes()<<"/"<<d.getDia()<<"/"<<d.getAno()<<endl;
			cout<<d.getDia()<<"/"<<d.getMes()<<"/"<<aano<<endl;
			cout<<d.getMes()<<"/"<<d.getDia()<<"/"<<aano<<endl;
			cout<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
			cout<<d.diaDaSemana()<<", "<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
			cout<<d.diaDaSemana()<<", "<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
		}
		}
		cout<<"Deseja adicionar uma nova data?\n\nDigite\n(S)para Sim\t digite (N)para não\n";
		cin>>finalizar;

}
while((finalizar!='S')||(finalizar!='s'));

}
