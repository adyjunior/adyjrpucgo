#ifndef DATA_H_
#define DATA_H_
#include<string>
#include<sstream>

namespace PG2 {

class Data {
private:
	int dia;
	int mes;
	int ano;

public:
//**  Sobrecarga de Metodos - Construtor
	Data(int dia, int mes, int ano);//Construtor com parametro
	Data(){dia=mes=ano=1;}//Construtor sem parametro
//****************************************************************
	~Data(){};//Destrutor - inline

//*** Metodo Estatico
	static bool validar(int dia, int mes, int ano);//static
//****************************************************************

	void set(int dia, int mes, int ano);//Normal
	int getDia()const{return dia;}//inline - const
	int getAno()const{return ano;}//inline - const
	std::string getDataStr()const;
	void setDataStr(std::string data);
	int quantidadeDeAnos(Data data)const;

//**  Sobrecarga de Metodos
	int getMes()const{return mes;}//inline - const
	void getMes(int &mes)const{mes = this->mes;}//inline - const
	void getMes(std::string &mes)const;//const

	std::string diaDaSemana()const;//const
	void diaDaSemana(std::string &diaSemana)const{diaSemana=diaDaSemana();}//inline - const

	void get(int &dia, int &mes, int &ano)const{dia=this->dia;mes=this->mes;ano=this->ano;}//inline - const
	void get(int &dia, std::string &mes, int &ano)const{dia=this->dia;this->getMes(mes);ano=this->ano;}//inline - const
//****************************************************************

	int quantidadeDeDias(Data data)const;//ok - ok - const

private:

	int diaDoSeculo()const{return (ano - 1901) * 365 + (ano - 1901) / 4 + dia + (mes - 1) * 31 -
		 ((mes * 4 + 23) / 10) * ((mes + 12) / 15) + ((4 - ano % 4) / 4) * ((mes + 12) / 15);}
};

}

#endif /* DATA_H_ */
