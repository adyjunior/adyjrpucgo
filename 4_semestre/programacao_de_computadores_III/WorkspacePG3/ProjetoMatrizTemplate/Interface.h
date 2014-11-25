#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<iostream>
#include <iomanip>
#include<string>
#include"Matriz.h"
#include"Controle.h"
#include"Erro.h"
using std::cin;
using std::cout;
using std::endl;


namespace PG3 {

template <class type>
class Interface {
private:
	Controle<type> ctrl;
	Erro *erro;

public:
	Interface(){};
	~Interface(){};
	void lerMatriz(Matriz<type> &matriz)const;
	void escreverMatriz(Matriz<type> const &matriz)const;
	void menuPrincipal();
	void persistirMatrizes();
	void operacoesMatrizes()const;
	Matriz<type> *recuperar()const;
};



template <class type>
void Interface<type>::lerMatriz(Matriz<type> &matriz)const{
	int qLinhas = matriz.getQuantidadeLinhas();
	int qColunas = matriz.getQuantidadeColunas();
	type elemento;
	for(int linha=0; linha < qLinhas; linha++){
		for(int coluna=0; coluna < qColunas; coluna++){
			try{
				std::cout<<"MATRIZ["<<linha<<"] , ["<<coluna<<"]= ";
				std::cin>>elemento;
				matriz.setElemento(linha,coluna,elemento);
			}catch(int valorErro){
				throw valorErro;
			}
		}
	}
}


template <class type>
void Interface<type>::escreverMatriz(Matriz<type> const &matriz)const{
	int qLinhas = matriz.getQuantidadeLinhas();
	int qColunas = matriz.getQuantidadeColunas();
	for(int linha=0; linha<qLinhas; linha++){
		std::cout<<"|";
		for(int coluna=0; coluna<qColunas;coluna++){
			try{
				std::cout<<std::left<<std::setw(3)<<matriz.getElemento(linha,coluna)<<" ";
			}catch(int valorErro){
				throw valorErro;
			}
		}
		std::cout<<std::left<<std::setw(3)<<"|"<<std::endl;
	}
}

template <class type>
Matriz<type> *Interface<type>::recuperar()const{
	try{
		cout<<"ARQUIVOS EXISTENTES:"<<endl;
		system("dir /b DiretorioMatriz");
		cout<<endl<<endl<<"QUAL ARQUIVO DESEJA RECUPERAR: ";
		std::string nomeDoArquivoNoDisco;
		cin>>nomeDoArquivoNoDisco;

		return this->ctrl.processoRecuperar(nomeDoArquivoNoDisco);
	}catch(int valorErro){
		throw valorErro;
	}
}


template <class type>
void Interface<type>::menuPrincipal(){
	int opcao;
	do{
		cout<<"Deseja que o arquivo de Erro seja Ingles ou portugues :"<<endl;
		cout<<"( 2 ) PARA PORTUGUES"<<endl;
		cout<<"( 3 ) PARA INGLES"<<endl;
		cout<<"OPCAO : ";
		cin>>opcao;
		system("cls");
	}while(opcao !=3 && opcao != 2);

		int select=99;
		while(select){
			try{
				this->erro = Erro::getInstancia(opcao);

				cout<<endl<<endl<<endl<<endl;
				cout<<"                              \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB"<<endl;
				cout<<"                              \xba        MENU MATRIZ       \xba"<<endl;
				cout<<"                              \xba                          \xba"<<endl;
				cout<<"                              \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9"<<endl;
				cout<<"                              \xba  1 - MANIPULAR MATRIZES  \xba"<<endl;
				cout<<"                              \xba  2 - OPERACOES MATRICIAIS\xba"<<endl;
				cout<<"                              \xba  0 - SAIR                \xba"<<endl;
				cout<<"                              \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc"<<endl;


				cout<<"  OPCAO: ";
				cin>>select;

				system("cls");

				switch(select){
					case 1:{
						persistirMatrizes();
						break;
					}
					case 2:{
						operacoesMatrizes();
						break;
					}
					default :{
						if(select)
							cout<<"OPCAO INVALIDA , DIGITE NOVAMENTE";
						cout<<endl<<endl;
						break;
					}
				}
			}catch(int valorErro){
				cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl<<endl;
				system("pause");
				system("cls");
			}catch(std::logic_error a){
					cout<<"ERRO -> "<<a.what()<<endl;
					system("pause");
					std::exit(1);
			}

		}

}

template <class type>
void Interface<type>::persistirMatrizes(){

	int select=99;
	while(select){
		try{
			cout<<endl<<endl<<endl<<endl;
			cout<<"                              \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB"<<endl;
			cout<<"                              \xba        MANIPULAR MATRIZ        \xba"<<endl;
			cout<<"                              \xba                                \xba"<<endl;
			cout<<"                              \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9"<<endl;
			cout<<"                              \xba  1 - GRAVAR MATRIZ             \xba"<<endl;
			cout<<"                              \xba  2 - RECUPERAR MATRIZ          \xba"<<endl;
			cout<<"                              \xba  3 - APAGAR MATRIZ             \xba"<<endl;
			cout<<"                              \xba  0 - RETORNAR AO MENU PRINCIPAL\xba"<<endl;
			cout<<"                              \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc"<<endl;

			cout<<"OPCAO  :";
			cin>>select;

			system("cls");

			switch(select){
				case 1:{
					int linhaA,colunaA;
					std::string nomeArquivo;
					cout<<"GRAVAR MATRIZ"<<endl;
					cout<<"DIGITE O NOME DO ARQUIVO QUE SERA SALVO : ";
					cin>>nomeArquivo;
					cout<<"Digite o numero de linhas da matriz  : ";
					cin>>linhaA;
					cout<<"Digite o numero de colunas da matriz  : ";
					cin>>colunaA;
					Matriz<type> matSalvar(linhaA,colunaA);
					this->lerMatriz(matSalvar);
					this->ctrl.processoGravar(matSalvar,nomeArquivo);
					cout<<endl<<"MATRIZ SALVA COM SUCESSO"<<endl<<endl;
					break;

				}
				case 2:{
					std::string nomeArquivo;
					cout<<"RECUPERAR MATRIZ"<<endl<<endl;
					Matriz<type> *matRecuperada;
					matRecuperada = this->recuperar();
					cout<<"MATRIZ RECUPERADA : "<<endl<<endl;
					this->escreverMatriz(*matRecuperada);
					cout<<endl<<endl;
					break;

				}
				case 3:{
					cout<<"APAGAR MATRIZ"<<endl<<endl;
					cout<<"ARQUIVOS EXISTENTES:"<<endl;
					system("dir /b DiretorioMatriz");
					cout<<endl<<endl<<"QUAL ARQUIVO DESEJA APAGAR :";
					std::string nomeDoArquivoNoDisco;
					cin>>nomeDoArquivoNoDisco;
					this->ctrl.processoApagar(nomeDoArquivoNoDisco);
					cout<<"MATRIZ APAGADA COM SUCESSO"<<endl<<endl;
					break;

				}
				default: {
					if(select)
						cout<<"OPCAO INVALIDA , DIGITE NOVAMENTE";
					cout<<endl<<endl;
					break;
				}

			}
		}catch(int valorErro){
			cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl<<endl;
			system("pause");
			system("cls");
		}


	}

}




template <class type>
void Interface<type>::operacoesMatrizes()const{
try{

	std::string nomeArquivo;
	cout<<"RECUPERAR MATRIZ (A)"<<endl<<endl;
	Matriz<type> MA(1,1);
	MA = this->recuperar();
	if(MA.getQuantidadeLinhas() < 3)
		throw (8);
	cout<<"MATRIZ RECUPERADA : "<<endl<<endl;
	this->escreverMatriz(MA);
	cout<<endl;
	system("pause");
	system("cls");

	cout<<endl<<endl<<"RECUPERAR MATRIZ (B)"<<endl<<endl;
	Matriz<type> MB(1,1);
	MB = this->recuperar();
	if(MB.getQuantidadeLinhas() < 3)
		throw (8);
	cout<<"MATRIZ RECUPERADA : "<<endl<<endl;
	this->escreverMatriz(MB);



	Matriz<type> MC(1,1);

	int select=99;
	while(select){

		system("pause");
		system("cls");
		cout<<endl<<endl<<endl<<endl;
		cout<<"                              \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB"<<endl;
		cout<<"                              \xba         OPERACAO MATRIZES        \xba"<<endl;
		cout<<"                              \xba                                  \xba"<<endl;
		cout<<"                              \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9"<<endl;
		cout<<"                              \xba  01 - ADICAO                     \xba"<<endl;
		cout<<"                              \xba  02 - SUBTRACAO                  \xba"<<endl;
		cout<<"                              \xba  03 - MULTIPLICACAO              \xba"<<endl;
		cout<<"                              \xba  04 - MATRIZES IGUAIS            \xba"<<endl;
		cout<<"                              \xba  05 - MATRIZES DIFERENTES        \xba"<<endl;
		cout<<"                              \xba  06 - TRIANGULAR SUPERIOR        \xba"<<endl;
		cout<<"                              \xba  07 - TRIANGULAR INFERIOR        \xba"<<endl;
		cout<<"                              \xba  08 - SIMETRICA                  \xba"<<endl;
		cout<<"                              \xba  09 - ANTI-SIMETRICA             \xba"<<endl;
		cout<<"                              \xba  10 - IDENTIDADE                 \xba"<<endl;
		cout<<"                              \xba  11 - TRANSPOSTA                 \xba"<<endl;
		cout<<"                              \xba  12 - PERMUTACAO                 \xba"<<endl;
		cout<<"                              \xba  13 - MULTIPLICACAO POR K        \xba"<<endl;
		cout<<"                              \xba  14 - ORTOGONAL                  \xba"<<endl;
		cout<<"                              \xba  15 - POTENCIACAO DE MATRIZ      \xba"<<endl;
		cout<<"                              \xba  0  - RETORNAR AO MENU PRINCIPAL \xba"<<endl;
		cout<<"                              \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc"<<endl<<endl;

		cout<<"  OPCAO: ";
		cin>>select;

		system("cls");

		switch(select){
			case 1:{
				try{
					cout<<"ADICAO DE MATRIZES"<<endl;
					MC = MA + MB;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl<<"MATRIZ RESULTANTE : "<<endl;
					this->escreverMatriz(MC);
					cout<<endl<<endl;
					break;

				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}
			}
			case 2:{
				try{
					cout<<"SUBTRACAO DE MATRIZES"<<endl;
					MC = MA - MB;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl<<"MATRIZ RESULTANTE : "<<endl;
					this->escreverMatriz(MC);
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}
			}
			case 3:{
				try{
					cout<<"MULTIPLICACAO DE MATRIZES"<<endl;
					MC = MA * MB;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl<<"MATRIZ RESULTANTE : "<<endl;
					this->escreverMatriz(MC);
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}
			}
			case 4:{
				try{
					cout<<"COMPARAR SE MATRIZES SAO IGUAIS"<<endl;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl<<endl;
					if(MA == MB)
						cout<<"MATRIZES SAO IGUAIS"<<endl;
					else
						cout<<"MATRIZES NAO SAO IGUAIS"<<endl;
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			case 5:{
				try{
					cout<<"COMPARAR SE MATRIZES SAO DIFERENTES"<<endl;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl<<endl;
					if(MA != MB)
						cout<<"MATRIZES SAO DIFERENTES"<<endl;
					else
						cout<<"MATRIZES NAO SAO DIFERENTES"<<endl;
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			case 6:{
				try{
					cout<<"SE MATRIZ EH TRIANGULAR SUPERIOR"<<endl;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl;
					if(MA.eMatrizTriangularSuperior())
						cout<<"MATRIZ (A) EH TRIANGULAR SUPERIOR"<<endl;
					else
						cout<<"MATRIZ (A) NAO EH TRIANGULAR SUPERIOR"<<endl;
					cout<<endl<<endl;

					cout<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl;
					if(MB.eMatrizTriangularSuperior())
						cout<<"MATRIZ (B) EH TRIANGULAR SUPERIOR"<<endl;
					else
						cout<<"MATRIZ (B) NAO EH TRIANGULAR SUPERIOR"<<endl;
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			case 7:{
				try{
					cout<<"SE MATRIZ EH TRIANGULAR INFERIOR"<<endl;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl;
					if(MA.eMatrizTriangularInferior())
						cout<<"MATRIZ (A) EH TRIANGULAR INFERIOR"<<endl;
					else
						cout<<"MATRIZ (A) NAO EH TRIANGULAR INFERIOR"<<endl;
					cout<<endl<<endl;

					cout<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl;
					if(MB.eMatrizTriangularInferior())
						cout<<"MATRIZ (B) EH TRIANGULAR INFERIOR"<<endl;
					else
						cout<<"MATRIZ (B) NAO EH TRIANGULAR INFERIOR"<<endl;
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			case 8:{
				try{
					cout<<"SE MATRIZ EH SIMETRICA"<<endl;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl;
					if(MA.eMatrizSimetrica())
						cout<<"MATRIZ (A) EH SIMETRICA"<<endl;
					else
						cout<<"MATRIZ (A) NAO EH SIMETRICA"<<endl;
					cout<<endl<<endl;

					cout<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl;
					if(MB.eMatrizSimetrica())
						cout<<"MATRIZ (B) EH SIMETRICA"<<endl;
					else
						cout<<"MATRIZ (B) NAO EH SIMETRICA"<<endl;
					cout<<endl<<endl;
					break;
			}catch(int valorErro){
				cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
				break;
			}

			}
			case 9:{
				try{
					cout<<"SE MATRIZ EH ANTI-SIMETRICA SIMETRICA"<<endl;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl;
					if(MA.eMatrizAntiSimetrica())
						cout<<"MATRIZ (A) EH ANTI-SIMETRICA"<<endl;
					else
						cout<<"MATRIZ (A) NAO EH ANTI-SIMETRICA"<<endl;
					cout<<endl<<endl;

					cout<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl;
					if(MB.eMatrizAntiSimetrica())
						cout<<"MATRIZ (B) EH ANTI-SIMETRICA"<<endl;
					else
						cout<<"MATRIZ (B) NAO EH ANTI-SIMETRICA"<<endl;
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			case 10:{
				try{
					cout<<"SE MATRIZ EH IDENTIDADE"<<endl;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl;
					if(MA.eMatrizIdentidade())
						cout<<"MATRIZ (A) EH IDENTIDADE"<<endl;
					else
						cout<<"MATRIZ (A) NAO EH IDENTIDADE"<<endl;
					cout<<endl<<endl;

					cout<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl;
					if(MB.eMatrizIdentidade())
						cout<<"MATRIZ (B) EH IDENTIDADE"<<endl;
					else
						cout<<"MATRIZ (B) NAO EH IDENTIDADE"<<endl;
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			case 11:{
				try{
					cout<<"MATRIZ TRANSPOSTA"<<endl;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<"MATRIZ TRANSPOSTA DE (A)"<<endl;
					this->escreverMatriz(*MA.matrizTransposta());

					cout<<endl<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<"MATRIZ TRANSPOSTA DE (B)"<<endl;
					this->escreverMatriz(*MB.matrizTransposta());
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			case 12:{
				try{
					cout<<"SE MATRIZ EH DE PERMUTACAO"<<endl;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl;
					if(MA.eMatrizDePermutacao())
						cout<<"MATRIZ (A) EH DE PERMUTACAO"<<endl;
					else
						cout<<"MATRIZ (A) NAO EH DE PERMUTACAO"<<endl;
					cout<<endl<<endl;

					cout<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl;
					if(MB.eMatrizDePermutacao())
						cout<<"MATRIZ (B) EH DE PERMUTACAO"<<endl;
					else
						cout<<"MATRIZ (B) NAO EH DE PERMUTACAO"<<endl;
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			case 13:{
				try{
					cout<<"MULTIPLICAR MATRIZ POR K"<<endl;
					cout<<"DIGITE K : ";int k=0;
					cin>>k;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<"MATRIZ (A) MULTIPLICADA POR K"<<endl;
					this->escreverMatriz(*MA.multiplicarPorK(k));

					cout<<endl<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<"MATRIZ (B) MULTIPLICADA POR K"<<endl;
					this->escreverMatriz(*MB.multiplicarPorK(k));
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			case 14:{
				try{
					cout<<"SE MATRIZ EH ORTAGONAL"<<endl;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<endl;
					if(MA.eMatrizOrtagonal())
						cout<<"MATRIZ (A) EH ORTAGONAL"<<endl;
					else
						cout<<"MATRIZ (A) NAO EH ORTAGONAL"<<endl;
					cout<<endl<<endl;

					cout<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<endl;
					if(MB.eMatrizOrtagonal())
						cout<<"MATRIZ (B) EH ORTAGONAL"<<endl;
					else
						cout<<"MATRIZ (B) NAO EH ORTAGONAL"<<endl;
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			case 15:{
				try{
					cout<<"POTENCIACAO DE MATRIZES"<<endl;
					cout<<"DIGITE O EXPONENCIAL A SER ELEVADO : ";int k=0;
					cin>>k;
					cout<<"MATRIZ A :"<<endl;
					this->escreverMatriz(MA);
					cout<<"MATRIZ (A) POTENCIALIZADA"<<endl;
					Matriz<type> *potA = MA.potenciaMatriz(k);
					this->escreverMatriz(*potA);

					cout<<endl<<"MATRIZ B : "<<endl;
					this->escreverMatriz(MB);
					cout<<"MATRIZ (B) POTENCIALIZADA"<<endl;
					Matriz<type> *potB = MB.potenciaMatriz(k);
					this->escreverMatriz(*potB);
					cout<<endl<<endl;
					break;
				}catch(int valorErro){
					cout<<endl<<endl<<"ERRO ("<<valorErro<<") -> "<<erro->getErro(valorErro)<<endl;
					break;
				}

			}
			default: {
				if(select)
				cout<<"OPCAO ERRADA , DIGITE NOVAMENTE";
				cout<<endl<<endl;
				break;
			}

		}

	}

}catch(int valorErro){
	throw valorErro;
}



}







}

#endif /* INTERFACE_H_ */






















/*

template<class type>
void Interface<type>::menuPrincipal(){
	cout<<"Digite a Matriz (A)"<<endl;
	Matriz<int> MA(3,3);
	this->lerMatriz(MA);

	cout<<"Digite a Matriz (B)"<<endl;
	Matriz<int> MB(3,3);
	this->lerMatriz(MB);

	Matriz<int> MC(3,3);

	cout<<"1 - ADD"<<endl;
	cout<<"2 - SUB"<<endl;
	cout<<"3 - MUL"<<endl;
	cout<<"4 - IGUAIS"<<endl;
	cout<<"5 - DIF"<<endl;
	cout<<"6 - T SUP"<<endl;
	cout<<"5 - T INF"<<endl;
	cout<<"Opcao : ";
	int opcao;
	cin>>opcao;

	switch(opcao){
	case 1:{
		cout<<"ADICAO DE MATRIZES"<<endl;
		MC = MA + MB;
		cout<<"MATRIZ A :"<<endl;
		this->escreverMatriz(MA);
		cout<<endl<<"MATRIZ B : "<<endl;
		this->escreverMatriz(MB);
		cout<<endl<<"MATRIZ RESULTANTE : "<<endl;
		this->escreverMatriz(MC);
		cout<<endl<<endl;
		break;

	}
	case 2:{
		cout<<"SUBTRACAO DE MATRIZES"<<endl;
		MC = MA - MB;
		cout<<"MATRIZ A :"<<endl;
		this->escreverMatriz(MA);
		cout<<endl<<"MATRIZ B : "<<endl;
		this->escreverMatriz(MB);
		cout<<endl<<"MATRIZ RESULTANTE : "<<endl;
		this->escreverMatriz(MC);
		cout<<endl<<endl;
		break;

	}
	case 3:{
		cout<<"MULTIPLICACAO DE MATRIZES"<<endl;
		MC = MA * MB;
		cout<<"MATRIZ A :"<<endl;
		this->escreverMatriz(MA);
		cout<<endl<<"MATRIZ B : "<<endl;
		this->escreverMatriz(MB);
		cout<<endl<<"MATRIZ RESULTANTE : "<<endl;
		this->escreverMatriz(MC);
		cout<<endl<<endl;
		break;

	}
	case 4:{
		cout<<"COMPARAR SE MATRIZES SAO IGUAIS"<<endl;
		cout<<"MATRIZ A :"<<endl;
		this->escreverMatriz(MA);
		cout<<endl<<"MATRIZ B : "<<endl;
		this->escreverMatriz(MB);
		cout<<endl<<endl;
		if(MA == MB)
			cout<<"MATRIZES SAO IGUAIS"<<endl;
		else
			cout<<"MATRIZES NAO SAO IGUAIS"<<endl;
		cout<<endl<<endl;
		break;

	}
	case 5:{
		cout<<"COMPARAR SE MATRIZES SAO DIFERENTES"<<endl;
		cout<<"MATRIZ A :"<<endl;
		this->escreverMatriz(MA);
		cout<<endl<<"MATRIZ B : "<<endl;
		this->escreverMatriz(MB);
		cout<<endl<<endl;
		if(MA != MB)
			cout<<"MATRIZES SAO DIFERENTES"<<endl;
		else
			cout<<"MATRIZES NAO SAO DIFERENTES"<<endl;
		cout<<endl<<endl;
		break;

	}
	case 6:{
		cout<<"SE MATRIZ EH TRIANGULAR SUPERIOR"<<endl;
		cout<<"MATRIZ A :"<<endl;
		this->escreverMatriz(MA);
		cout<<endl;
		if(MA.eMatrizTriangularSuperior())
			cout<<"MATRIZ (A) EH TRIANGULAR SUPERIOR"<<endl;
		else
			cout<<"MATRIZ (A) NAO EH TRIANGULAR SUPERIOR"<<endl;
		cout<<endl<<endl;

		cout<<"MATRIZ B : "<<endl;
		this->escreverMatriz(MB);
		cout<<endl;
		if(MB.eMatrizTriangularSuperior())
			cout<<"MATRIZ (B) EH TRIANGULAR SUPERIOR"<<endl;
		else
			cout<<"MATRIZ (B) NAO EH TRIANGULAR SUPERIOR"<<endl;
		cout<<endl<<endl;
		break;

	}
	case 7:{
		cout<<"SE MATRIZ EH TRIANGULAR INFERIOR"<<endl;
		cout<<"MATRIZ A :"<<endl;
		this->escreverMatriz(MA);
		cout<<endl;
		if(MA.eMatrizTriangularInferior())
			cout<<"MATRIZ (A) EH TRIANGULAR INFERIOR"<<endl;
		else
			cout<<"MATRIZ (A) NAO EH TRIANGULAR INFERIOR"<<endl;
		cout<<endl<<endl;

		cout<<"MATRIZ B : "<<endl;
		this->escreverMatriz(MB);
		cout<<endl;
		if(MB.eMatrizTriangularInferior())
			cout<<"MATRIZ (B) EH TRIANGULAR INFERIOR"<<endl;
		else
			cout<<"MATRIZ (B) NAO EH TRIANGULAR INFERIOR"<<endl;
		cout<<endl<<endl;
		break;

	}
	}
}
*/
