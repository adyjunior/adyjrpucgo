#include<iostream>
#include<string>
#include"Interface.h"
#include"Cliente.h"
#include"persistencia.h"
using namespace std;
int main(void)
{
	
	Persistencia per;
	
	/*
	//TESTE DE FUNCIONAMENTO DA PERSISTENCIA  - ITEM GRAVACAO
	Cliente teste(10,"Carlos da Silva",2339988,"carlos@teste.dat");
	if(per.gravar(&teste))std::cout<<"gravado 10 ";
		else std::cout<<"nao gravado 10";
	std::cout<<endl<<endl;
	teste.atribuir(11,"Antonio dos Santos",5442377,"antonio@teste.dat");
	if(per.gravar(&teste))std::cout<<"gravado 11 ";
		else std::cout<<"nao gravado 11";
	std::cout<<endl<<endl;
	teste.atribuir(12,"Jose Matheus",3278855,"jose@teste.dat");
	if(per.gravar(&teste))std::cout<<"gravado 12 ";
		else std::cout<<"nao gravado 12";
	std::cout<<endl<<endl;
	teste.atribuir(13,"Maria do Carmo",999999,"maria@teste.dat");
	if(per.gravar(&teste))std::cout<<"gravado 13 ";
		else std::cout<<"nao gravado 13";
	std::cout<<endl<<endl;
	teste.atribuir(11,"Antonio dos Santos",5442377,"antonio@teste.dat");
	if(per.gravar(&teste))std::cout<<"gravado 11 ";
		else std::cout<<"nao gravado 11";
	std::cout<<endl<<endl;
*/

/*
	//TESTE DE FUNCIONAMENTO DA PERSISTENCIA  - ITEM RECUPERACAO
	string nome,email;
	unsigned int id;
	long telefone;
	Cliente teste2(12,"",0,"");
	if(per.recuperar(&teste2)){
		teste2.obter(id,nome,telefone,email);
		cout<<endl<<"Id: "<<id<<"   Nome: "<<nome;
		cout<<endl<<"Telefone: "<<telefone<<"  Email: "<<email<<endl<<endl;
	}
	else std::cout<<"nao Recuperado 11"<<endl;

	teste2.atribuir(10,"",0,"");
	if(per.recuperar(&teste2)){
		teste2.obter(id,nome,telefone,email);
		cout<<endl<<"Id: "<<id<<"   Nome: "<<nome;
		cout<<endl<<"Telefone: "<<telefone<<"  Email: "<<email<<endl<<endl;
	}
		else std::cout<<"nao Recuperado 11"<<endl;

	teste2.atribuir(99,"",0,"");
	if(per.recuperar(&teste2)){
		teste2.obter(id,nome,telefone,email);
		cout<<endl<<"Id: "<<id<<"   Nome: "<<nome;
		cout<<endl<<"Telefone: "<<telefone<<"  Email: "<<email<<endl<<endl;
	}
		else std::cout<<"nao Recuperado 99"<<endl;
	
*/

	//TESTE DE FUNCIONAMENTO DA PERSISTENCIA  - ITEM REMOVER
	
	string nome,email;
	unsigned int id;
	long telefone;
	Cliente teste2(12,"",0,"");
	if(per.recuperar(&teste2)){
		teste2.obter(id,nome,telefone,email);
		cout<<endl<<"Id: "<<id<<"   Nome: "<<nome;
		cout<<endl<<"Telefone: "<<telefone<<"  Email: "<<email<<endl<<endl;
		if(per.remover(&teste2))std::cout<<"Removido 12";
			else std::cout<<"Removido 12";
	}
	else std::cout<<"nao Recuperado 11"<<endl;

	//Interface::menuPrincipal();
}

