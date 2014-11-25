#include"ArvoreAVL.h"
#include"Elemento.h"
#include"No.h"
#include<iostream>


int main(){

/*	ArvoreAVL *av;
	av = new ArvoreAVL();
	Elemento elemento;
	No* raiz;
	raiz = No::MontaNo(elemento);
	float a;
	for(;;){

		std::cout<<"Digite o numero a ser inserido : ";
		std::cin>>a;

		elemento.setPosicao(a);
		//raiz.setEL(elemento);

		std::cout<<"Inclusao            :"<<std::endl;
		av->inserir(elemento);
		std::cout<<"O Elemento "<<elemento.getPosicao()<<" foi incluido !!"<<std::endl;

		//cout<<"Deseja listar os elementos ?"<<std::endl;
		//cin>>a;

		if(!a)break;
	}

	No *P;
	P = No::MontaNo(elemento);

	av->excluir(&P,elemento.getPosicao());

	P = av->getRoot();

	av->listar(av->getRoot());*/


	///////////////////////////////////


	ArvoreAVL avl;
	Elemento elemento;
	float el;



	int select = 50;

	while(select){

		std::cout<<" _____________________________________________"<<std::endl;
		std::cout<<"|                  ARVORE AVL                 |"<<std::endl;
		std::cout<<"|                                             |"<<std::endl;
		std::cout<<"|1 - INSERIR ELEMENTO                         |"<<std::endl;
		std::cout<<"|2 - EXCLUIR ELEMENTO                         |"<<std::endl;
		std::cout<<"|3 - LISTAR AVL EM ORDEM                      |"<<std::endl;
		std::cout<<"|4 - LISTAR AVL EM PRE-ORDEM                  |"<<std::endl;
		std::cout<<"|5 - LISTAR AVL EM POS-ORDEM                  |"<<std::endl;
		std::cout<<"|0 - SAIR                                     |"<<std::endl;
		std::cout<<"|_____________________________________________|"<<std::endl;

		cout<<"OPCAO : ";
		cin>>select;

		switch(select){
		case 1:{
			std::cout<<"Digite o valor do Elemento a ser incluido: ";
			cin>>el;

			elemento.setPosicao(el);

			avl.inserir(elemento);
			std::cout<<"Elemento "<<elemento.getPosicao()<<" enserido na AVL com sucesso !!!"<<std::endl;

			std::cout<<"Tecle < ENTER > ... "<<std::endl;
			std::getchar();
			std::cin.ignore();
			system("cls");
			break;
		}
		case 2:{
			std::cout<<"Digite o valor do Elemento a ser deletado: ";
			cin>>el;


			if(!avl.eVazia()){
				elemento.setPosicao(el);
				No *P;
				P = No::MontaNo(elemento);

				avl.excluir(&P,elemento.getPosicao());
				std::cout<<"Elemento "<<elemento.getPosicao()<<" excluido da AVL com sucesso !!!"<<std::endl;

			}
			else {std::cout<<"Arvore Vazia !!! "<<std::endl<<std::endl;}

			std::cout<<"Tecle < ENTER > ... "<<std::endl;
			std::getchar();
			std::cin.ignore();
			system("cls");
			break;

		}
		case 3:{

			if(!avl.eVazia()){
				avl.listar(avl.getRoot());
				std::cout<<endl<<endl;
			}
			else {std::cout<<"Arvore Vazia !!! "<<std::endl<<std::endl;}

			std::cout<<"Tecle < ENTER > ... "<<std::endl;
			std::getchar();
			std::cin.ignore();
			system("cls");
			break;

		}
		case 4:{

			if(!avl.eVazia()){
				avl.imprimirPreOrdem(avl.getRoot());
				std::cout<<endl<<endl;
			}
			else {std::cout<<"Arvore Vazia !!! "<<std::endl<<std::endl;}
			std::cout<<"Tecle < ENTER > ... "<<std::endl;
			std::getchar();
			std::cin.ignore();
			system("cls");
			break;

		}
		case 5:{

			if(!avl.eVazia()){
				avl.imprimirPosOrdem(avl.getRoot());
				std::cout<<endl<<endl;
			}
			else {std::cout<<"Arvore Vazia !!! "<<std::endl<<std::endl;}
			std::cout<<"Tecle < ENTER > ... "<<std::endl;
			std::getchar();
			std::cin.ignore();
			system("cls");
			break;

		}
		default :{
			if(select)std::cout<<"Opcao invalida"<<std::endl;
			std::cout<<"Tecle < ENTER > ... "<<std::endl;
			std::getchar();
			std::cin.ignore();
			break;

		}
		}

	}



	system("pause");

}


