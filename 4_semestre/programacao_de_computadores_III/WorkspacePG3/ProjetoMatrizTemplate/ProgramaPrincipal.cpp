
#include"Interface.h"
#include<iostream>

int main(void){

	int opcao=0;

	std::cout<<"ESCOLHA O TIPO DE ESTRUTURA DESEJA :"<<std::endl<<std::endl;
	std::cout<<"1 - int"<<std::endl;
	std::cout<<"2 - float"<<std::endl;
	std::cout<<"3 - char"<<std::endl;
	std::cout<<"4 - long"<<std::endl;
	std::cout<<"5 - long long"<<std::endl;
	std::cout<<"6 - double"<<std::endl;
	std::cout<<"Opcao : ";
	cin>> opcao;
	system("cls");
	switch(opcao){
	case 1:{
		PG3::Interface<int> show;
		show.menuPrincipal();
	}
	case 2:{
		PG3::Interface<float> show;
		show.menuPrincipal();
	}
	case 3:{
		PG3::Interface<char> show;
		show.menuPrincipal();
	}
	case 4:{
		PG3::Interface<long> show;
		show.menuPrincipal();
	}
	case 5:{
		PG3::Interface<long long> show;
		show.menuPrincipal();
	}
	case 6:{
		PG3::Interface<double> show;
		show.menuPrincipal();
	}
	default:{
		std::cout<<"Opcao invalida"<<std::endl;
	}

	}


}
