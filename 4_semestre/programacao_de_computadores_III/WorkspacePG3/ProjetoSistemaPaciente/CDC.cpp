#include "CDC.h"
#include<iostream>
namespace CadeiaCaracteres {

int CDC::converteStrParaInteiro(std::string const &str) {
	int numero=0;
	for(unsigned int pos=0;pos<str.length();pos++){
		if(static_cast<int>(str[pos]) < 48 || static_cast<int>(str[pos]) > 57) throw 6;
		numero = numero*10 + static_cast<int>(str[pos])-48;
	}
	return numero;
}

long CDC::converteStrParaInteiroLongo(std::string const &str) {
	long numero=0;
	for(unsigned int pos=0;pos<str.length();pos++){
		if(static_cast<int>(str[pos]) < 48 || static_cast<int>(str[pos]) > 57) throw 6;
		numero = numero*10 + static_cast<int>(str[pos])-48;
	}
	return numero;
}

long long CDC::converteStrParaInteiroLongoLongo(const std::string &str){
	long long numero=0;
		for(unsigned int pos=0;pos<str.length();pos++){
			if(static_cast<int>(str[pos]) < 48 || static_cast<int>(str[pos]) > 57) throw 6;
			numero = numero*10 + static_cast<int>(str[pos])-48;
		}
		return numero;

}

float CDC::converteStrParaReal(std::string const &str){
	int inteiro=0;
	float fracionario=0;
	int exp = 0;
	bool teste = true;
	for(unsigned int pos=0;pos<str.length();pos++){
		if((static_cast<int>(str[pos])< 48 || static_cast<int>(str[pos]) > 57) && str[pos]!='.') throw (6);
		if(str[pos]=='.') {teste=false;pos++;}
		if(teste) inteiro = inteiro*10 + static_cast<int>(str[pos])-48;
		else{
			fracionario = fracionario*10 + (static_cast<int>(str[pos])-48);
			exp++;
		}
	}
	//float numero = inteiro + fracionario/static_cast<int>(std::pow(10,exp));
	//return numero;
	return 0.0;
}

void CDC::converteStringParaMaiuscula(std::string &str){
	for(unsigned int pos=0; pos<str.length();pos++){
		if(str[pos]>=97 && str[pos]<=122) str[pos]-=32;
	}
}

void CDC::converteStringParaMinuscula(std::string &str){
	for(unsigned int pos=0; pos<str.length();pos++){
		if(str[pos]>=65 && str[pos]<=90) str[pos]+=32;
	}
}

std::string CDC::buscarSubString(std::string const &str, unsigned int &pos, char caracter){
	if(pos>=str.length()){std::cout<<pos<<" >= "<<str.length()<<std::endl; throw (3);}
	std::string strSaida="";
	for(unsigned int p=pos;p<str.length()&&str[p]!=';';pos++,p++){
		strSaida+=str[p];
	}
	pos++;
	return strSaida;
}

std::string CDC::converteInteiroParaStr(int numero){
	std::string str="";
	while(numero){
		str= static_cast<char>((numero%10)+48) + str;
		numero = numero/10;
	}
	return str;
}

std::string CDC::converteInteiroLongoParaStr(long numero){
	std::string str="";
	while(numero){
		str= static_cast<char>((numero%10)+48) + str;
		numero = numero/10;
	}
	return str;
}

std::string CDC::converteInteiroLongoLongoParaStr(long long numero){
	std::string str="";
		while(numero){
			str= static_cast<char>((numero%10)+48) + str;
			numero = numero/10;
		}
		return str;
}

/*std::string CDC::converteRealParaStr(float numero){
	long numeroL=static_cast<long>(numero);
	std::string str="";
	while(numeroL){
		str= static_cast<char>((numeroL%10)+48) + str;
		numeroL = numeroL/10;
	}
	str+=".";
	std::string str2="";
	numeroL= (numero - static_cast<long>(numero))*1000000;
	while(numeroL){
		str2= static_cast<char>((numeroL%10)+48) + str2;
		numeroL = numeroL/10;
	}
	return str+str2;
}*/


}
