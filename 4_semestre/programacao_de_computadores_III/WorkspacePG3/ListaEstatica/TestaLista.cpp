#include<iostream>
#include"Lista.h"

using std::cout;
using std::cin;
using std::endl;

int main(){

	int tamLista=0,elemento,i=0,item=0;//chave=5;

	cout<<"Digite o tamanho da lista: ";
	cin>>tamLista;



	Junior::Lista array(tamLista);


	try{

		for(;i < tamLista;i++){
			cout<<"Digite o "<<(i+1)<<"da Lista:";
			cin>>elemento;
			array.add(elemento);
		}

		if(array.remove(5,item))
			cout<<"O elemento removido eh: "<<item<<endl<<endl;
		else
			cout<<"Elemento nao encontrado"<<endl<<endl;

		//cout<<"O primeiro elemento eh: "<<array.retiraPrimeiro()<<endl;


		if(array.vazia())
			cout<<"Lista vazia"<<endl;
		else
			cout<<"Lista nao esta vazia"<<endl;


			cout<<"A posicao do elemento eh: "<<array.pesquisa(1)<<endl;

	}
	catch(std::string a){
		cout<<"Erro de Lista: ->"<<a<<endl;
	}
	catch(...){
		cout<<"Erro de Lista nao identificado"<<endl;
	}
	array.imprime();


}
