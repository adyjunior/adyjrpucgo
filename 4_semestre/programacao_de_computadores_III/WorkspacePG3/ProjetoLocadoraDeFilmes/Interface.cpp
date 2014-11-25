#include "Interface.h"

void Interface::menu01(Persistencia *locadora)
{
	int opcao=9;
	while(opcao!=0){// while
		system("cls");
		cout<<" M E N U    P R I N C I P A L "<<endl<<endl;
		cout<<"	1 - 	MANTER CLIENTE"<<endl;
		cout<<"	2 - 	MANTER FILME"<<endl;
		cout<<"	3 - 	MANTER LOCACAO"<<endl;
		cout<<"	0 - 	FIM"<<endl<<endl;
		cout<<"OPCAO: ";
		cin>>opcao;
		switch(opcao){//switch
		case 1:{// case 1
						menuCliente(locadora);
						break;
		}//case1
		case 2:{
						menuFilme(locadora);
						break;
		}
		case 3:{

		}

		}// switch
	}// while
}

void Interface::menuFilme(Persistencia *locadora){


	ControleFilme controleFilme(locadora);
	int opcao=9;
		while(opcao!=0){// while
			system("cls");
			cout<<" M E N U    F I L M E "<<endl<<endl;
			cout<<"	1 - 	INCLUSAO"<<endl;
			cout<<"	2 - 	ALTERACAO"<<endl;
			cout<<"	3 - 	CONSULTA"<<endl;
			cout<<"	0 - 	FIM"<<endl<<endl;
			cout<<"OPCAO: ";
			cin>>opcao;
			switch(opcao){//switch
			case 1:{// case 1
							int id;
							string nome;
							int valor;
							bool situacao;
							system("cls");
							cout<<"DADOS DO CLIENTE"<<endl<<endl;
							cout<<"IDENTIFICADOR: ";
							cin>>id;
							cout<<"TITULO: ";
							cin.ignore();
							getline(cin,nome);
							cout<<"VALOR: ";
							cin>>valor;
							cout<<"EMAIL: ";
							situacao = false;
							Filme filme(id);
							filme.atribuirTitulo(nome);
							filme.atribuirSituacao(situacao);
							filme.atribuirValorDeCompra(valor);
							controleFilme.incluirFilme(&filme);
							cout<<"INCLUSAO CONCLUIDA";
							break;
			}//case 1
			case 2:{//case 2
				int id;
				system("cls");
				cout<<"DADOS DO CLIENTE"<<endl<<endl;
				cout<<"IDENTIFICADOR: ";
				cin>>id;
				Cliente cliente(id);
				//controleCliente.consultarCliente(&cliente);

					system("cls");
					cout<<"DADOS DO CLIENTE"<<endl<<endl;
					cout<<"IDENTIFICADOR: "<<cliente.obterIdentificador()<<endl;
					cout<<"NOME: "<<cliente.obterNome()<<endl;
					cout<<"TELEFONE: "<<cliente.obterTelefone()<<endl;
					cout<<"EMAIL: "<<cliente.obterEmail()<<endl;
					cout<<"CONFIRMA ALTERACAO: ";
					char resp;
					cin.ignore();
					cin>>resp;
					if(resp == 'S' || resp == 's'){
						string nome,email;
						long telefone;
						system("cls");
						cout<<"DADOS DO CLIENTE"<<endl<<endl;
						cout<<"IDENTIFICADOR: "<<cliente.obterIdentificador()<<endl;
						cout<<"NOME: ";
						cin.ignore();
						getline(cin,nome);
						cout<<"TELEFONE: ";
						cin>>telefone;
						cout<<"EMAIL: ";
						cin.ignore();
						getline(cin,email);
						cliente.atribuirNome(nome);
						cliente.atribuirTelefone(telefone);
						cliente.atribuirEmail(email);
						//controleCliente.alterarCliente(&cliente);
					}
					break;

			}//case 2
			case 3:{// case 3
				int id;
				system("cls");
				cout<<"DADOS DO CLIENTE"<<endl<<endl;
				cout<<"IDENTIFICADOR: ";
				cin>>id;
				Cliente cliente(id);
				//controleCliente.consultarCliente(&cliente);

					system("cls");
					cout<<"DADOS DO CLIENTE"<<endl<<endl;
					cout<<"IDENTIFICADOR: "<<cliente.obterIdentificador()<<endl;
					cout<<"NOME: "<<cliente.obterNome()<<endl;
					cout<<"TELEFONE: "<<cliente.obterTelefone()<<endl;
					cout<<"EMAIL: "<<cliente.obterEmail()<<endl;
					cout<<endl<<"tecle enter para continuar";
					char resp;
					cin.ignore();
					cin>>resp;
					break;
			}//case 3
			}//switch
		}//while


}






void  Interface::menuCliente(Persistencia *locadora)
{

	ControleCliente controleCliente(locadora);
	int opcao=9;
		while(opcao!=0){// while
			system("cls");
			cout<<" M E N U    C L I E N T E "<<endl<<endl;
			cout<<"	1 - 	INCLUSAO"<<endl;
			cout<<"	2 - 	ALTERACAO"<<endl;
			cout<<"	3 - 	CONSULTA"<<endl;
			cout<<"	0 - 	FIM"<<endl<<endl;
			cout<<"OPCAO: ";
			cin>>opcao;
			switch(opcao){//switch
			case 1:{// case 1
							int id;
							string nome,email;
							long telefone;
							system("cls");
							cout<<"DADOS DO CLIENTE"<<endl<<endl;
							cout<<"IDENTIFICADOR: ";
							cin>>id;
							cout<<"NOME: ";
							cin.ignore();
							getline(cin,nome);
							cout<<"TELEFONE: ";
							cin>>telefone;
							cout<<"EMAIL: ";
							cin.ignore();
							getline(cin,email);
							Cliente cliente(id);
							cliente.atribuirNome(nome);
							cliente.atribuirTelefone(telefone);
							cliente.atribuirEmail(email);
							controleCliente.incluirCliente(&cliente);
							cout<<"INCLUSAO CONCLUIDA";
							break;
			}//case 1
			case 2:{//case 2
				int id;
				system("cls");
				cout<<"DADOS DO CLIENTE"<<endl<<endl;
				cout<<"IDENTIFICADOR: ";
				cin>>id;
				Cliente cliente(id);
				controleCliente.consultarCliente(&cliente);

					system("cls");
					cout<<"DADOS DO CLIENTE"<<endl<<endl;
					cout<<"IDENTIFICADOR: "<<cliente.obterIdentificador()<<endl;
					cout<<"NOME: "<<cliente.obterNome()<<endl;
					cout<<"TELEFONE: "<<cliente.obterTelefone()<<endl;
					cout<<"EMAIL: "<<cliente.obterEmail()<<endl;
					cout<<"CONFIRMA ALTERACAO: ";
					char resp;
					cin.ignore();
					cin>>resp;
					if(resp == 'S' || resp == 's'){
						string nome,email;
						long telefone;
						system("cls");
						cout<<"DADOS DO CLIENTE"<<endl<<endl;
						cout<<"IDENTIFICADOR: "<<cliente.obterIdentificador()<<endl;
						cout<<"NOME: ";
						cin.ignore();
						getline(cin,nome);
						cout<<"TELEFONE: ";
						cin>>telefone;
						cout<<"EMAIL: ";
						cin.ignore();
						getline(cin,email);
						cliente.atribuirNome(nome);
						cliente.atribuirTelefone(telefone);
						cliente.atribuirEmail(email);
						controleCliente.alterarCliente(&cliente);
					}
					break;

			}//case 2
			case 3:{// case 3
				int id;
				system("cls");
				cout<<"DADOS DO CLIENTE"<<endl<<endl;
				cout<<"IDENTIFICADOR: ";
				cin>>id;
				Cliente cliente(id);
				controleCliente.consultarCliente(&cliente);

					system("cls");
					cout<<"DADOS DO CLIENTE"<<endl<<endl;
					cout<<"IDENTIFICADOR: "<<cliente.obterIdentificador()<<endl;
					cout<<"NOME: "<<cliente.obterNome()<<endl;
					cout<<"TELEFONE: "<<cliente.obterTelefone()<<endl;
					cout<<"EMAIL: "<<cliente.obterEmail()<<endl;
					cout<<endl<<"tecle enter para continuar";
					char resp;
					cin.ignore();
					cin>>resp;
					break;
			}//case 3
			}//switch
		}//while

}





