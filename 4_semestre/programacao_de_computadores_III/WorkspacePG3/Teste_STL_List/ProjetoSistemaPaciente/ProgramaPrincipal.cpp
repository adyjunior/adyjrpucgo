#include<iostream>
#include"Paciente.h"
#include"Controle.h"
#include"Iterator.h"

using std::cout;
using std::cin;
using std::endl;

int main(){

try{

	std::string nome,endereco,email,nomeDoArquivo="arquivoPaciente.txt";//,data;
	int dia=9,mes=1,ano=2000;
	long telefone = 32924510;
	long long numeroCPF;
	//Container::Iterator<Paciente> it;

	PSP::Paciente Junior;
	//PSP::Persistencia per(nomeDoArquivo.c_str());
	PSP::Controle *ctrl;
	ctrl = new PSP::Controle(nomeDoArquivo.c_str());

	cout<<"Digite seu nome : ";
	std::getline(cin,nome);
	//cout<<endl<<"Digite seu telefone: ";
	//cin>>telefone;
	cout<<endl<<"Digite seu Cpf";
	cin>>numeroCPF;
	cout<<endl<<"Digite seu email: ";
	cin>>email;
	//cout<<endl<<"Digite a data de nascimento "<<endl;
	//cin>>data;
	//cout<<"Digite o dia: "<<endl;
	//cin>>dia;
	//cout<<"Digite o mes: ";
	//cin>>mes;
	//cout<<"Digite o ano: ";
	//cin>>ano;
	cout<<endl<<"Digite seu endereco: ";
	cin.ignore();
	std::getline(cin,endereco);


	Junior.setNome(nome);
	Junior.setTelefone(telefone);
	Junior.setNumeroCPF(numeroCPF);
	Junior.setEmail(email);
	Junior.setDataDeNascimento(dia,mes,ano);
	//Junior.setDataDeNascimento(data);
	Junior.setEndereco(endereco);



	int opcao=50;

	while(opcao){
		cout<<"    Sistema Paciente"<<endl<<endl;
		cout<<"1 - Gravar paciente"<<endl;
		cout<<"2 - Recuperar paciente"<<endl;
		cout<<"3 - Apagar paciente"<<endl;
		cout<<"4 - Alterar paciente"<<endl;
		cout<<"5 - Buscar paciente"<<endl;
		cout<<"6 - Listar paciente"<<endl;
		cout<<"0 - Sair"<<endl;
		cout<<"Opcao :";
		cin>> opcao;




		switch(opcao){
			case 1:{
				ctrl->inclusaoPaciente(Junior);
				cout<<"Gravado com sucesso !!"<<endl;
				cin.get();
				cin.ignore();
				break;
			}
			case 2:{
				int d,m,a;
				std::string dA="",mA="";
				ctrl->alteracaoPaciente(Junior);
				Junior.getDataDeNascimento(d,m,a);
				if(d < 10)dA="0";
				if(m < 10)mA = "0";
				cout<<"Nome : "<<Junior.getNome()<<endl;
				cout<<"Telefone : "<<Junior.getTelefone()<<endl;
				cout<<"CPF : "<<Junior.getNumeroCPF()<<endl;
				cout<<"DataNascimento : "<<dA<<d<<"/"<<mA<<m<<"/"<<a<<endl;//<<Junior.getDataDeNascimento()<<endl;
				cout<<"Endereco : "<<Junior.getEndereco()<<endl;
				cout<<"Email : "<<Junior.getEmail()<<endl;
				cin.get();
				cin.ignore();
				break;
			}
			case 3:{
				ctrl->exclusaoPaciente(Junior.getNome());
				cout<<"Deletado com sucesso !!"<<endl;
				cin.get();
				cin.ignore();
				break;
			}
			case 4:{
				ctrl->alteracaoPaciente(Junior);
				cout<<"Alterado com sucesso !!"<<endl;
				cin.get();
				cin.ignore();
				break;
			}
			case 5:{
/*
				if( per.buscar("VILA SHOOOOW (:") )
					cout<<"Nome JA existe "<<endl;
				else
					cout<<"Nome NAO existe "<<endl;
*/
			}
			case 6:{
				PSP::Paciente *pessoa;
				Container::Iterator<PSP::Paciente*> *it;

				it = ctrl->listarPaciente();


				pessoa = it->primeiro();
				for(;it->existeProximo();){

					cout<<"Nome : "<<pessoa->getNome()<<endl;
					pessoa = it->proximo();
				}
				pessoa = it->itemAtual();
				cout<<"Nome : "<<pessoa->getNome()<<endl;

				break;
			}


		}


	}

}catch(int valorErro){
	cout<<"ERRO >> "<<valorErro<<endl;
}


}
