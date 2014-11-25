

#ifndef DATA_H_
#define DATA_H_
#include <string>
#include <cstdlib>
class Data
{
private:
	int dia;
	int mes;
	int ano;
public:
	Data()
	{
		dia = 1;
		mes = 1;
		ano = 1;
	};
	Data(std::string &data)
	{
		switch (data.size())
		{
		case 10:
			this->dia = atoi(data.substr(0,2).c_str());
			this->mes = atoi(data.substr(3,2).c_str());
			this->ano = atoi(data.substr(6,4).c_str());
			break;
		case 9:
			if (data[1]== '/'&& data[4]=='/')
			{
				this->dia = atoi(data.substr(0,1).c_str());
				this->mes = atoi(data.substr(2,2).c_str());
			}
			if (data[2]== '/'&& data[4]=='/')
			{
				this->dia = atoi(data.substr(0,2).c_str());
				this->mes = atoi(data.substr(3,1).c_str());
			}
			this->ano = atoi(data.substr(5,4).c_str());
			break;
		case 8:
			this->dia = atoi(data.substr(0,1).c_str());
			this->mes = atoi(data.substr(2,1).c_str());
			this->ano = atoi(data.substr(4,4).c_str());
			break;
		}
	}
	~Data(){};
	//bool Data::setDia(int d);
	bool Data::setMes(int m);
	bool Data::setAno(int a);
	int Data::getDia()const;
	std::string Data::getDiaDaSemana()const;
	std::string Data::getDataPorExtensoCompleta()const;
	int Data::getMes()const;
	int Data::getAno()const;
	std::string Data::getDataPorExtenso()const;
	std::string Data::getDataDDMMAAAA()const;
	std::string Data::getDataMMDDAAAA()const;
	std::string Data::getDataDDMMAA()const;
	std::string Data::getDataMMDDAA()const;
	static bool Data::eValida(int d, int m, int a)
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
	static bool Data::eValida(std::string &data)
	{
		int d, m, a;
		switch (data.size())
		{
		case 10:
			d = atoi(data.substr(0,2).c_str());
			m = atoi(data.substr(3,2).c_str());
			a = atoi(data.substr(6,4).c_str());
			return Data::eValida(d,m,a);
			break;
		case 9:
			if (data[1]== '/'&& data[4]=='/')
			{
				d = atoi(data.substr(0,1).c_str());
				m = atoi(data.substr(2,2).c_str());
			}
			if (data[2]== '/'&& data[4]=='/')
			{
				d = atoi(data.substr(0,2).c_str());
				m = atoi(data.substr(3,1).c_str());
			}
			a = atoi(data.substr(5,4).c_str());
			return Data::eValida(d,m,a);
			break;
		case 8:
			d = atoi(data.substr(0,1).c_str());
			m = atoi(data.substr(2,1).c_str());
			a = atoi(data.substr(4,4).c_str());
			return Data::eValida(d,m,a);
			break;
		default:
			return false;
		}
	}
};

#endif /* DATA_H_ */
