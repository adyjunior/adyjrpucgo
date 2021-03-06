#include "Data.h"
#include<iostream>

namespace PG2 {

Data::Data(int dia, int mes, int ano) {// ok
	// TODO Auto-generated constructor stub
	if(validar(dia,mes,ano)){
		this->dia = dia;
		this->mes = mes;
		this->ano = ano;
		return;
	}
	this->dia=this->mes=this->ano = 1;
}

void Data::setDataStr(std::string data){
	//std::cout<<"Size ->"<<data.length()<<std::endl;
	//std::cout<<"Data ->"<<data<<std::endl;
	if(data.size() != 8)//TRATAR COM INTERFACE GRAFICA
			throw(1);

	int dia,mes,ano;
	std::istringstream ss(data.substr(0,2));
	ss >> dia;
	std::istringstream ss2(data.substr(2,2));
	ss2 >> mes;
	std::istringstream ss3(data.substr(4,4));
	ss3 >> ano;

	if(this->validar(dia,mes,ano))
	{
		this->dia = dia;
		this->mes = mes;
		this->ano = ano;
		//this->data = data;

	}
	else
		throw(1);
}

bool Data::validar(int dia, int mes, int ano){// ok
	int diasDoMes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(dia<1 || mes<1 || dia>31 || mes>12 || ano<1) return(false);
	if(ano%4==0 && (ano%100!=0 || ano%400==0)) diasDoMes[2]+=1;
	if(dia>diasDoMes[mes]) return(false);
	return(true);
}
void Data::set(int dia, int mes, int ano){//ok
	if(validar(dia,mes,ano)){
		this->dia = dia;
		this->mes = mes;
		this->ano = ano;
	}
	else
		throw(2);// Erro 2 data invalida
}

void Data::getMes(std::string &mes)const{//ok
	std::string mesString[13]={	"vazio","Janeiro","Fevereiro",
								"Marco","Abril","Maio","Junho",
								"Julho","Agosto","Setembro",
								"Outubro","Novembro","Dezembro"};
	mes=mesString[this->mes];
}

std::string Data::diaDaSemana()const{//ok
	std::string diaSemana[7]={	"segunda-feira",
								"terca-feira","quarta-feira",
								"quinta-feira","sexta-feira",
								"sabado","domingo"};

	 int resultado = diaDoSeculo() % 7;
	 return diaSemana[resultado];
}

int Data::quantidadeDeDias(Data data)const{// ok
	int 	diaDoSeculo1 = diaDoSeculo();
	int 	diaDoSeculo2 = data.diaDoSeculo();
	int diferenca = diaDoSeculo1 - diaDoSeculo2;
	if(diferenca<0) diferenca*=-1;  // Diferenca em modulo
	return diferenca;
}

std::string Data::getDataStr()const{
	std::ostringstream ss,ss2,ss3;
	std::string d,m,a;
	ss << dia;
	ss2 << mes;
	ss3 << ano;

	a = ss3.str();

	if(this->dia < 10)
		d = "0"+ss.str();
	else
		d = ss.str();
	if(this->mes < 10)
		m = "0"+ss2.str();
	else
		m = ss2.str();

	return d  + m  + a;

}

int Data::quantidadeDeAnos(Data data)const{
int ano=0;

		if(this->diaDoSeculo() > data.diaDoSeculo())
			ano = this->diaDoSeculo() - data.diaDoSeculo();
		else
			ano = data.diaDoSeculo() - this->diaDoSeculo();

		return ano/365;

}
// Rever os calculos do dia do Seculo

}
