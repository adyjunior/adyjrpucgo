/*
 * Main.cpp
 *
 *  Created on: 19/10/2009
 *      Author: jUniN C.Z.N
 */



#include"Data.h"
#include<iostream>
#include<cstdlib>
#include<string>


using namespace std;

int main()
{
	int dd=-1,mm=-1,aa=-1,iniciar;
	char finalizar;
	do
	{


		cout<<"Deseja digitar a data JUNTA , ou SEPARADAMENTE?\n\nPara digitar juto digite(2)\tPara digitar separado digite(3)";
		cin>>iniciar;

		if(iniciar==2)
		{
			char Data[10],Data2[10];
			int Data_final,Numero,I,J=0;






			do
			{



				//cout<<"\n\n"<<Data<<"\n\n"<<Data2<<endl;
				cout<<"Digite a Data\n";
				cin>>Data;

				Numero= strlen(Data);


				for(I=0;I<Numero;I++)
				{
					if(Data[I]!='/')
					{
						Data2[J]=Data[I];
						J++;
					}

				}
				Data2[J] = '\0';

				Data_final= atoi(Data2);

				//cout<<"\n\n"<<Data_final<<endl;



				dd=Data_final/1000000;
				if(dd==0)
				dd=Data_final/100000;

				mm=Data_final/10000;
				mm=mm%1000;

				if(mm>99)
					mm=mm%100;
				if((Data_final/1000000)==0)
					mm=mm%10;
				aa=Data_final%10000;

			//cout<<"\n\n"<<dd<<"/"<<mm<<"/"<<aa<<endl;

				if(mm==2)
				{
					if(!(Data::testefev(dd,mm,aa)))
					{dd=-1;mm=-1;aa=-1;}

				}
				else
					if(!(Data::mes31(dd,mm,aa)))
						{dd=-1;mm=-1;aa=-1;}


				if(! (Data::valdiar(dd,mm,aa)) )
				{
					cout<<"Data invalida Digite Novamente\n\n";
					for(I=0;I<Numero;I++)
							{
								Data[I]='/0';
								Data2[I]='/0';
							}
				}



			}while(!(Data::valdiar(dd,mm,aa)));




		}
		else
			if(iniciar==3)
			{

				dd=-1;



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
							{dd=-1;mm=-1;aa=-1;}


					}
					else
						if(!(Data::mes31(dd,mm,aa)))
							{dd=-1;mm=-1;aa=-1;}


					if(! (Data::valdiar(dd,mm,aa)) )
						cout<<"Data invalida Digite Novamente\n\n";



				}



			}
			else{
				cout<<"Opção invalida";
				return 0;
				}

		Data d;//Objeto d da classe Data foi criado

		d.setDia(dd);
		d.setMes(mm);
		d.setAno(aa);

		int aano=d.getAno()%1000;

		if ((d.getAno()<1000)||((d.getAno()%1000)>100))
			aano=d.getAno()%100;

		cout<<"As datas são:\n\n";

		if((d.getAno()%1000)<10)
		{
			if((d.getDia()<10)&&(d.getMes()<10))
			{
				cout<<"0"<<d.getDia()<<"/0"<<d.getMes()<<"/"<<d.getAno()<<endl;
				cout<<"0"<<d.getMes()<<"/0"<<d.getDia()<<"/"<<d.getAno()<<endl;
				cout<<"0"<<d.getDia()<<"/0"<<d.getMes()<<"/0"<<aano<<endl;
				cout<<"0"<<d.getMes()<<"/0"<<d.getDia()<<"/0"<<aano<<endl;
			}
			else{
					if(d.getDia()<10)
					{
						cout<<"0"<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
						cout<<d.getMes()<<"/0"<<d.getDia()<<"/"<<d.getAno()<<endl;
						cout<<"0"<<d.getDia()<<"/"<<d.getMes()<<"/0"<<aano<<endl;
						cout<<d.getMes()<<"/0"<<d.getDia()<<"/0"<<aano<<endl;
					}
					else{
						if(d.getMes()<10)
						{
							cout<<d.getDia()<<"/0"<<d.getMes()<<"/"<<d.getAno()<<endl;
							cout<<"0"<<d.getMes()<<"/"<<d.getDia()<<"/"<<d.getAno()<<endl;
							cout<<d.getDia()<<"/0"<<d.getMes()<<"/0"<<aano<<endl;
							cout<<"0"<<d.getMes()<<"/"<<d.getDia()<<"/0"<<aano<<endl;
						}
							else{

								cout<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
								cout<<d.getMes()<<"/"<<d.getDia()<<"/"<<d.getAno()<<endl;
								cout<<d.getDia()<<"/"<<d.getMes()<<"/0"<<aano<<endl;
								cout<<d.getMes()<<"/"<<d.getDia()<<"/0"<<aano<<endl;

								}


					}
				}
			cout<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
			cout<<d.diaDaSemana()<<", "<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
			cout<<d.diaDaSemana()<<", "<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;

		}

		else{

			if((d.getAno()%1000)<100)
			{
				if((d.getDia()<10)&&(d.getMes()<10))
				{
					cout<<"0"<<d.getDia()<<"/0"<<d.getMes()<<"/"<<d.getAno()<<endl;
					cout<<"0"<<d.getMes()<<"/0"<<d.getDia()<<"/"<<d.getAno()<<endl;
					cout<<"0"<<d.getDia()<<"/0"<<d.getMes()<<"/"<<aano<<endl;
					cout<<"0"<<d.getMes()<<"/0"<<d.getDia()<<"/"<<aano<<endl;
				}
				else{
					if(d.getDia()<10)
					{
						cout<<"0"<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
						cout<<d.getMes()<<"/0"<<d.getDia()<<"/"<<d.getAno()<<endl;
						cout<<"0"<<d.getDia()<<"/"<<d.getMes()<<"/"<<aano<<endl;
						cout<<d.getMes()<<"/0"<<d.getDia()<<"/"<<aano<<endl;

					}
					else{
						if(d.getMes()<10)
						{
							cout<<d.getDia()<<"/0"<<d.getMes()<<"/"<<d.getAno()<<endl;
							cout<<"0"<<d.getMes()<<"/"<<d.getDia()<<"/"<<d.getAno()<<endl;
							cout<<d.getDia()<<"/0"<<d.getMes()<<"/"<<aano<<endl;
							cout<<"0"<<d.getMes()<<"/"<<d.getDia()<<"/"<<aano<<endl;

						}
						else{
								cout<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
								cout<<d.getMes()<<"/"<<d.getDia()<<"/"<<d.getAno()<<endl;
								cout<<d.getDia()<<"/"<<d.getMes()<<"/"<<aano<<endl;
								cout<<d.getMes()<<"/"<<d.getDia()<<"/"<<aano<<endl;

						}
					}
				}
				cout<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
				cout<<d.diaDaSemana()<<", "<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
				cout<<d.diaDaSemana()<<", "<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
			}

			else{
				if(d.getAno()>0)
				{
					if((d.getDia()<10)&&(d.getMes()<10))
					{
						cout<<"0"<<d.getDia()<<"/0"<<d.getMes()<<"/"<<d.getAno()<<endl;
						cout<<"0"<<d.getMes()<<"/0"<<d.getDia()<<"/"<<d.getAno()<<endl;
						cout<<"0"<<d.getDia()<<"/0"<<d.getMes()<<"/"<<aano<<endl;
						cout<<"0"<<d.getMes()<<"/0"<<d.getDia()<<"/"<<aano<<endl;
					}
					else{


							if(d.getDia()<10)
							{
								cout<<"0"<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
								cout<<d.getMes()<<"/0"<<d.getDia()<<"/"<<d.getAno()<<endl;
								cout<<"0"<<d.getDia()<<"/"<<d.getMes()<<"/"<<aano<<endl;
								cout<<d.getMes()<<"/0"<<d.getDia()<<"/"<<aano<<endl;
							}
							else{
								if(d.getMes()<10)
								{
									cout<<d.getDia()<<"/0"<<d.getMes()<<"/"<<d.getAno()<<endl;
									cout<<"0"<<d.getMes()<<"/"<<d.getDia()<<"/"<<d.getAno()<<endl;
									cout<<d.getDia()<<"/0"<<d.getMes()<<"/"<<aano<<endl;
									cout<<"0"<<d.getMes()<<"/"<<d.getDia()<<"/"<<aano<<endl;

								}
								else{
										cout<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;
										cout<<d.getMes()<<"/"<<d.getDia()<<"/"<<d.getAno()<<endl;
										cout<<d.getDia()<<"/"<<d.getMes()<<"/"<<aano<<endl;
										cout<<d.getMes()<<"/"<<d.getDia()<<"/"<<aano<<endl;

								}
							}
						}
						cout<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
						cout<<d.diaDaSemana()<<", "<<d.getDia()<<" de "<<d.getMesExtenso()<<" de "<<d.getAno()<<endl;
						cout<<d.diaDaSemana()<<", "<<d.getDia()<<"/"<<d.getMes()<<"/"<<d.getAno()<<endl;



				}
			}
			}

			cout<<"Deseja adicionar uma nova data?\n\nDigite\n(S)para Sim\t digite (N)para não\n";
			cin>>finalizar;



}
while((finalizar=='S')||(finalizar=='s'));

return 0;
}
