/*
 * programa.cpp
 *
 *  Created on: 19/09/2010
 *      Author: jolimpiof
 */
#include<iostream>

#include"ArvoreBinaria.h"

using namespace std;

int main() {
ArvoreBinaria *arvore = 0;
No *novo;
int key = 0, op = 0;
char entrada[80];
string nome;

do {
	cout << "Digite:" << endl;
	cout << "1 : para criar uma arvore binaria vazia." << endl;
	cout << "2 : para inserir um novo no na arvore."<< endl;
	cout << "3 : para retirar um no da arvore." << endl;
	cout << "4 : para pesquisar por um no na arvore." << endl;
	cout << "5 : para listar todos os nos da arvore." << endl;
	cout << "6 : para testar a arvore."<< endl;
	cout << "7 : para encerrar o programa." << endl;

	do {
		cout << "Forneca uma entrada valida." << endl;
		cin.getline(entrada,80);
		op = atoi(entrada);
	} while(op<1 || op>7);

	switch (op) {
	case 1:
		if(!arvore) {
			arvore = new ArvoreBinaria;
			if (arvore) cout << "Sucesso: arvore criada." << endl;
			else cout << "Erro." << endl;
		}
		else cout << "Arvore j‡ criada." << endl;
		break;
	case 2:
		if (arvore) {
			cout << "Forneca a chave e o nome: " << endl;
			cin >> key;
			cin >> nome;
			//nome = entrada;
			novo = new No;
			novo->setChave(key);
			novo->setNome(nome);
			arvore->setRaiz(arvore->insere(novo, arvore->getRaiz()));
		}
		else cout << "Arvore nao foi criada." << endl;
		break;
	case 3:
		if(arvore) {
			cout << "Informe a chave para o no a ser removido." << endl;
			cin >> key;
			arvore->setRaiz(arvore->retira(key, arvore->getRaiz()));
		}
		else cout << "Arvore nao foi criada." << endl;
		break;
	case 4:
		if(arvore) {
			cout << "Informe a chave a ser pesquisada." << endl;
			cin >> key;
			novo = arvore->pesquisa(key, arvore->getRaiz());
			if(novo) {
				cout << novo->getChave() << endl;
				cout << novo->getNome() << endl;
			}
			else cout << "Chave nao encontrada." << endl;
		}
		else cout << "Arvore nao foi criada." << endl;
		break;
	case 5:
		if(arvore) {
			arvore->imprimeCentral(arvore->getRaiz());
		}
		else cout << "Arvore nao foi criada." << endl;
		break;
	case 6:
		if(arvore) {
			arvore->testa(arvore->getRaiz());
		}
		else cout << "Arvore nao foi criada." << endl;
		break;
	case 7:
		op = 0;
		break;
	}
} while(op != 0);
arvore->~ArvoreBinaria();
cout << "Program encerrado." << endl;
}

