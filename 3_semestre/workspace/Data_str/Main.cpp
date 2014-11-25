#include<string>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include"Data.h"


using namespace std;


int main()
{

	string dat;


	do
	{
	cout<<"Digite a Data\n";
	cin>>dat;


	if(!Data::validar(dat))
		cout<<"Data invaliza Digite novamente\n";

	}
	while(! Data::validar(dat));




	Data dd(dat);

	cout<<"As datas são\n";
	cout<<dd.getDDMMAAAA()<<endl;
	cout<<dd.getMMDDAAAA()<<endl;
	cout<<dd.getDDMMAA()<<endl;
	cout<<dd.getMMDDAA()<<endl;
	cout<<dd.getDDmesAAAA()<<endl;
	cout<<dd.getDiasemanaDDmesAAAA()<<endl;
	cout<<dd.getDiasemanaDDMMAAA()<<endl;

system("pause");
}











