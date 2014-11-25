#include "CPF.h"

namespace PG2 {

bool CPF::validar(long long int numero){
		long long int numeroCPF,digitoVerificadorCPF;
		unsigned int soma, dv, dv1, dv2, coeficiente;

		digitoVerificadorCPF = numero%100;
		numeroCPF = numero/100;
		soma = 0;
		for(coeficiente=2;numeroCPF!=0;coeficiente++)
		{
			soma = soma + (numeroCPF%10)*coeficiente;
			numeroCPF = numeroCPF/10;
		}
		dv1 = 11 - soma%11;
		if(dv1>9) dv1=0;
		soma = dv1*2;
		numeroCPF = numero/100;
		for(coeficiente=3;numeroCPF!=0;coeficiente++)
		{
			soma = soma + (numeroCPF%10)*coeficiente;
			numeroCPF = numeroCPF/10;
		}
		dv2 = 11 - soma%11;
		if(dv2>9) dv2=0;
		dv = dv1*10 + dv2;
		if(dv == digitoVerificadorCPF) return(true);
			else return(false);
	}

void CPF::set(long long int numero){
	if(numero<0) throw(1);// Erro 1 CPF invalido
	if(validar(numero)){
		this->numero = numero;

	}
	else throw(1);// Erro 1 CPF invalido
}

}

