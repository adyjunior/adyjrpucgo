#include "Cliente.h"
// Classe testada em C++ e modela no Jude
std::string Cliente::desmaterializar()const
{// inicio desmaterializar
	std::string linha;
	std::string idString;
	for(int aux=identificador;aux;){
		char letra= (aux%10)+48;
		idString=letra+idString;
		aux=aux/10;
	}
	linha=idString;
	linha +=";";
	linha+=nome;
	linha+=";";
	std::string foneString;
	for(long aux=telefone;aux;){
		char letra= (aux%10)+48;
		foneString=letra+foneString;
		aux=aux/10;
	}
	linha+=foneString;
	linha+=";";
	linha+=email;
	linha+=";";
	return linha;
}// fim desmaterializar

void Cliente::materializar(const std::string cdc)
{// inicio materializar
		int aux=0;
		int pos=0;
		for(;cdc[pos]!=';';pos++) aux=aux*10+(cdc[pos]-48);
		identificador=aux;
		std::string strAux="";
		for(pos++;cdc[pos]!=';';pos++) strAux+=cdc[pos];
		nome=strAux;
		long aux2=0;
		for(pos++;cdc[pos]!=';';pos++) aux2=aux2*10+(cdc[pos]-48);
		telefone=aux2;
		strAux="";
		for(pos++;cdc[pos]!=';';pos++) strAux+=cdc[pos];
		email=strAux;
}// fim materializar

// METODOS DA CLASSE CONTROLE CLIENTE

void ControleCliente::incluirCliente(Cliente *pessoa)
{
	try{
		if(!persistencia->gravar(pessoa))throw(0);
	}catch(int valorErro){
		throw valorErro;
	}

}

void ControleCliente::consultarCliente(Cliente *pessoa)
{
	try{
		if(!persistencia->recuperar(pessoa))throw(1);
	}catch(int valorErro){
		throw valorErro;
	}

}

void ControleCliente::alterarCliente(Cliente *pessoa)
{
	try{
		Cliente pessoaAux(pessoa->obterIdentificador());
		if(!persistencia->remover(&pessoaAux))throw(1);

		persistencia->gravar(pessoa);
	}catch(int valorErro){
		throw valorErro;
	}
	
}

void ControleCliente::excluirCliente(Cliente *pessoa){
	try{
		this->persistencia->remover(pessoa);
	}catch(int valorErro){
		throw valorErro;
	}
}

