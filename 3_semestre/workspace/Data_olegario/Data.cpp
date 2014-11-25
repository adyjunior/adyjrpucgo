/*
 * Data.cpp
 *
 *  Created on: 05/10/2009
 *      Author: Olegário C. S. Neto
 */

#include "Data.h"
#include <sstream>
/*bool Data::setDia(int d)
{
	if (d<0) return false;
	if (d>=1 && d<=28) {dia = d; return true;}
	if (d>=29 && d<=31 && (mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))
	{
		dia = d;
		return true;
	}
	if (d>=29 && d<=30 && (mes == 1 || mes == 4 || mes == 6 || mes == 9 || mes == 11))
		{
			dia = d;
			return true;
		}
	if (d==29 && mes == 2 && (ano%400==0 || (!(ano%100==0 && ano%400 != 0) && (ano%4==0 && ano%100!=0))))
	{
		dia=d;
		return true;
	}
	return false;
}
*/
bool Data::setMes(int m)
{
	if (m > 0 && m <= 12)
	{
		mes = m;
		return true;
	}
	else return false;
}

bool Data::setAno(int a)
{
	if (ano > 0)
	{
		ano = a;
		return true;
	}
	else return false;
}

int Data::getDia()const
{
	return dia;
}

std::string Data::getDiaDaSemana()const
{
	std::string diadasemana[7] = {"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira",
			"Quinta-feira",	"Sexta-feira", "Sábado"};
	int a=ano;
	int f = this->ano+this->dia+3*(this->mes-1) -1;
	if(this->mes<3) a--;
		else f-= int(0.4*this->mes+2.3);
	f+=(int(this->ano/4) - int((a/100+1)*0.75));
	f%=7;
	return(diadasemana[f]);
}

int Data::getMes()const
{
	return mes;
}

int Data::getAno()const
{
	return ano;
}

std::string Data::getDataPorExtenso()const
{
	std::string meses[13] = {"Vazio", "Janeiro", "Fevereiro", "Março", "Abril",
			"Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
	std::stringstream d, a;
	d << this->dia;
	a << this->ano;
	return "Goiânia, " + d.str()+ " " + meses[this->mes] + " de "+ a.str();
}

std::string Data::getDataPorExtensoCompleta()const
{
	return this->getDiaDaSemana() + ", " + this->getDataPorExtenso();
}

std::string Data::getDataDDMMAAAA()const
{
	std::stringstream d, m, a;
	d << this->dia;
	m << this->mes;
	a << this->ano;
	return  d.str() + "/" + m.str() + "/" + a.str();
}
std::string Data::getDataMMDDAAAA()const
{
	std::stringstream d, m, a;
	d << this->dia;
	m << this->mes;
	a << this->ano;
	return  m.str() + "/" + d.str() + "/" + a.str();
}
std::string Data::getDataDDMMAA()const
{
	std::stringstream d, m, a;
	d << this->dia;
	m << this->mes;
	a << this->ano;
	return  d.str() + "/" + m.str() + "/" + a.str().substr(2,2);
}

std::string Data::getDataMMDDAA()const
{
	std::stringstream d, m, a;
	d << this->dia;
	m << this->mes;
	a << this->ano;
	return  m.str() + "/" + d.str() + "/" + a.str().substr(2,2);
}

