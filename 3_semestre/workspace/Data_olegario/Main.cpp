


#include <iostream>
#include "Data.h"
#include <string>
#include <sstream>
#include <cstdlib>
//#include <QApplication>
//#include <QPushbutton>

using namespace std;
int main()
{
	//Data data;
	//int d, m, a=-1;
	string dat;
	string & da = dat;
	/*
	while (!Data::eValida(d,m,a))
	{
		cout << "Programa de data"<<endl;
		cout << "Digite o dia = "; cin >> d;
		cout << "Digite o mes = "; cin >> m;
		cout << "Digite o ano = "; cin >> a;
	}
	*/
	dat = "vazio";
	da = dat;
	while (!Data::eValida(da))
	{
		cout << "Programa de data"<<endl;
		cout << "Digite a data = "; cin >> dat;
	}
	Data data(dat);
	//data.setDia(d);
	//data.setMes(m);
	//data.setAno(a);
	cout<<endl<<data.getDataDDMMAAAA();
	cout<<endl<<data.getDataDDMMAA();
	cout<<endl<<data.getDataMMDDAAAA();
	cout<<endl<<data.getDataMMDDAA();
	cout<<endl<<data.getDataPorExtenso();
	cout<<endl<<data.getDiaDaSemana();
	cout<<endl<<data.getDataPorExtensoCompleta();
}

