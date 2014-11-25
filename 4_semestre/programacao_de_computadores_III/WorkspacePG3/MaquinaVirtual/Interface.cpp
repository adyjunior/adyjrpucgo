#include "Interface.h"

namespace Capsula {

using std::cin;
using std::cout;
using std::endl;

void Interface::menu(){

	int select=50;
	while(select){

		system("cls");
		cout<<"\xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n";
		cout<<"\xba                    MAQUINA VIRTUAL 1.0                  \xba\n";
		cout<<"\xba                                                         \xba\n";
		cout<<"\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n";
		cout<<"\xba 01 - INSTRUCOES EXISTENTES                              \xba"<<endl;
		cout<<"\xba 02 - CARREGAR ARQUIVO NA MEMORIA                        \xba"<<endl;
		cout<<"\xba 03 - CONTEUDO DA MEMORIA                                \xba"<<endl;
		cout<<"\xba 04 - EXECUTAR MAQUINA VIRTUAL                           \xba"<<endl;
		cout<<"\xba 05 - CONTEUDO DOS REGISTRADORES                         \xba"<<endl;
		cout<<"\xba 0  - SAIR                                               \xba"<<endl;
		cout<<"\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n";

		cout<<endl<<"Digite uma opcao : ";
		cin>>select;
		system("cls");

		switch(select){
		case 1:{
			this->instrucoesExistentes();
			break;
		}
		case 2:{
			this->carregaArquivoNaMemoria();
			break;
		}
		case 3:{
			this->conteudoMemoria();
			break;
		}
		case 4:{
			mv.compilador(this->nomeDoArquivo);
			break;
		}
		case 5:{
			this->conteudoRegistradores();
			break;
		}
		default :{
			if(select){
				cout<<"OPCAO INVALIDA"<<endl;
				std::cout<<"Tecle < ENTER > ..."<<std::endl;
				std::getchar();
				std::cin.ignore();
			}
			break;
		}

		}

	}

}

void Interface::conteudoMemoria(){

	mv.imprimeVetor();
	std::cout<<"Tecle < ENTER > ..."<<std::endl;
	std::getchar();
	std::cin.ignore();

}

void Interface::conteudoRegistradores(){
	mv.imprimeReg();
	std::cout<<"Tecle < ENTER > ..."<<std::endl;
	std::getchar();
	std::cin.ignore();
}

void Interface::carregaArquivoNaMemoria(){
	mv.carregarMemoria(this->nomeDoArquivo);
	std::cout<<"Arquivo Carregado com sucesso !"<<std::endl;
	std::cout<<"Tecle < ENTER > ..."<<std::endl;
	std::getchar();
	std::cin.ignore();
}



void Interface::instrucoesExistentes(){
	cout<<"INSTRUCOES DA MAQUINA VIRTUAL 1.0"<<endl<<endl;
	cout<<"load()"<<endl;
	cout<<"load(x,mq)"<<endl;
	cout<<"load(x)"<<endl;
	cout<<"stor(x)"<<endl;
	cout<<"stor(x,8:19)"<<endl;
	cout<<"stor(x,28:39)"<<endl;
	cout<<"jump(x,0:19)"<<endl;
	cout<<"jump(x,20:39)"<<endl;
	cout<<"add(x)"<<endl;
	cout<<"sub(x)"<<endl;
	cout<<"mul(x)"<<endl;
	cout<<"div(x)"<<endl;
	cout<<"lsh()"<<endl;
	cout<<"rsh()"<<endl<<endl;;
	cout<<"x -> endereco de memoria"<<endl<<endl;
	std::cout<<"Tecle < ENTER > ..."<<std::endl;
	std::getchar();
	std::cin.ignore();

}

}
