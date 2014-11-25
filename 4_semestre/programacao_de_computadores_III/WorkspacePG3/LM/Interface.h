#ifndef INTERFACE_H_
#define INTERFACE_H_
#include<iostream>
#include"Cliente.h"


class Interface
{
	public:
		static void menuPrincipal();

		//  TELAS PARA CLIENTE
		static void menuManterCliente();
		static void lerDadosDoCliente(Cliente &pessoa);
		static void escreverDadosDoCliente(const Cliente &pessoa);

		//  TELAS PARA FILME
		static void menuManterFilme();

		//  TELAS PARA LOCACAO
		static void menuManterLocacao();

};

void Interface::menuPrincipal()
{
	int opcao=1;
	while(opcao){
		system("clear");
		std::cout<<std::endl<<"	MENU PRINCIPAL"<<std::endl;
		std::cout<<std::endl<<"	1 - CLIENTE";
		std::cout<<std::endl<<"	2 - FILME";
		std::cout<<std::endl<<"	3 - LOCACAO";
		std::cout<<std::endl<<"	0 - SAIR";
		std::cout<<std::endl<<std::endl<<"	OPCAO: ";
		std::cin>>opcao;
		switch(opcao){
			case 1:{// case 1
				menuManterCliente();
				//std::cout<<std::endl<<"MENU CLIENTE EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				//std::cin.get();
				break;
			}//case 1
			case 2:{//case 2
				menuManterFilme();
				//std::cout<<std::endl<<"MENU FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				//std::cin.get();
				break;
			}//case 2
			case 3:{//case 3
				menuManterLocacao();
				//std::cout<<std::endl<<"MENU LOCACAO EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				//std::cin.get();
				break;
			}//case 3
		}
	}
}

//********************************************************
//  TELAS PARA CLIENTE
//********************************************************
void Interface::menuManterCliente()
{
	int opcao=1;
	while(opcao){
		system("clear");
		std::cout<<std::endl<<"	MENU MANTER CLIENTE"<<std::endl;
		std::cout<<std::endl<<"	1 - INCLUIR";
		std::cout<<std::endl<<"	2 - EXCLUIR";
		std::cout<<std::endl<<"	3 - ALTERAR";
		std::cout<<std::endl<<"	4 - CONSULTAR";
		std::cout<<std::endl<<"	5 - LISTAR";
		std::cout<<std::endl<<"	0 - SAIR";
		std::cout<<std::endl<<std::endl<<"	OPCAO: ";
		std::cin>>opcao;
		switch(opcao){
			case 1:{// case 1
				Cliente pessoa;
				lerDadosDoCliente(pessoa);

				break;
			}//case 1
			case 2:{//case 2
				std::cout<<std::endl<<"EXCLUIR CLIENTE EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 2
			case 3:{//case 3
				std::cout<<std::endl<<"ALTERAR CLIENTE EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 3
			case 4:{//case 4
				std::cout<<std::endl<<"CONSULTAR CLIENTE EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 4
			case 5:{//case 5
				std::cout<<std::endl<<"LISTAR CLIENTE EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 5
		}
	}
}

void Interface::lerDadosDoCliente(Cliente &pessoa)
{
	unsigned int id;
	std::string nome, email;
	long telefone;
	//system("clear");
	std::cout<<std::endl<<std::endl<<"DADOS DO CLIENTE - ENTRADA"<<std::endl<<std::endl;
	std::cout<<"IDENTIFICADOR: ";
	std::cin>>id;
	std::cin.ignore();
	std::cout<<"NOME: ";
	getline(std::cin,nome);
	std::cout<<"TELEFONE: ";
	std::cin>>telefone;
	std::cout<<"EMAIL: ";
	std::cin.ignore();
	getline(std::cin,email);
	pessoa.atribuir(id,nome,telefone,email);
}

void Interface::escreverDadosDoCliente(const Cliente &pessoa)
{
	unsigned int id;
	std::string nome, email;
	long telefone;
	pessoa.obter(id,nome,telefone,email);
	//system("clear");
	std::cout<<std::endl<<std::endl<<" DADOS DO CLIENTE - SAIDA"<<std::endl<<std::endl;
	std::cout<<"IDENTIFICADOR: "<<id<<std::endl;
	std::cout<<"NOME: "<<nome<<std::endl;
	std::cout<<"TELEFONE: "<<telefone<<std::endl;
	std::cout<<"EMAIL: "<<email<<std::endl;
}





//********************************************************
//  TELAS PARA FILME
//********************************************************
void Interface::menuManterFilme()
{
	int opcao=1;
	while(opcao){
		system("clear");
		std::cout<<std::endl<<"	MENU MANTER FILME"<<std::endl;
		std::cout<<std::endl<<"	1 - INCLUIR";
		std::cout<<std::endl<<"	2 - EXCLUIR";
		std::cout<<std::endl<<"	3 - ALTERAR";
		std::cout<<std::endl<<"	4 - CONSULTAR";
		std::cout<<std::endl<<"	5 - LISTAR";
		std::cout<<std::endl<<"	0 - SAIR";
		std::cout<<std::endl<<std::endl<<"	OPCAO: ";
		std::cin>>opcao;
		switch(opcao){
			case 1:{// case 1
				std::cout<<std::endl<<"INCLUIR FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 1
			case 2:{//case 2
				std::cout<<std::endl<<"EXCLUIR FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 2
			case 3:{//case 3
				std::cout<<std::endl<<"ALTERAR FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 3
			case 4:{//case 4
				std::cout<<std::endl<<"CONSULTAR FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 4
			case 5:{//case 5
				std::cout<<std::endl<<"LISTAR FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 5
		}
	}
}



//********************************************************
//  TELAS PARA LOCACAO
//********************************************************
void Interface::menuManterLocacao()
{
	int opcao=1;
	while(opcao){
		system("clear");
		std::cout<<std::endl<<"	MENU MANTER LOCACAO"<<std::endl;
		std::cout<<std::endl<<"	1 - LOCAR FILME";
		std::cout<<std::endl<<"	2 - DEVOLVER FILME";
		std::cout<<std::endl<<"	3 - CANCELAR";
		std::cout<<std::endl<<"	4 - CONSULTAR";
		std::cout<<std::endl<<"	0 - SAIR";
		std::cout<<std::endl<<std::endl<<"	OPCAO: ";
		std::cin>>opcao;
		switch(opcao){
			case 1:{// case 1
				std::cout<<std::endl<<"LOCAR FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 1
			case 2:{//case 2
				std::cout<<std::endl<<"DEVOLVER FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 2
			case 3:{//case 3
				std::cout<<std::endl<<"CANCELAR LOCACAO EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 3
			case 4:{//case 4
				std::cout<<std::endl<<"CONSULTAR LOCACAO EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				break;
			}//case 4
		}
	}
}






#endif /*INTERFACE_H_*/
