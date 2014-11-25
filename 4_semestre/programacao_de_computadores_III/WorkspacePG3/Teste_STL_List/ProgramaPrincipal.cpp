#include<iostream>
#include<list>
#include"Paciente.h"
#include<fstream>
#include"Iterator.h"

std::ostream& operator<<(std::ostream & os,const std::list<int>& lista){
	std::list<int>::const_iterator it;

	for(it = lista.begin();it != lista.end();it++)
		os << *it << ' ';
	return os;


}

int main(){

	std::ifstream arquivo("lista.txt");
	std::ofstream arquivoOrdenado("listaOrdenada.txt");
	std::string linha;
	PSP::Paciente paciente,p2;
	std::list<PSP::Paciente> lista;

	//std::list<int> lista;


	for(;!arquivo.eof();){
		std::getline(arquivo,linha);
		paciente.setNome(linha);
		lista.push_back(paciente);
	}

	Container::Iterator<PSP::Paciente> ITR(lista);
/*
	lista.push_front(10);
	lista.push_front(12);
	lista.push_front(11);
	lista.push_front(1);
	lista.push_front(20);
	lista.push_front(14);
	lista.push_front(50);
	lista.push_front(0);

*/


	//lista.sort();

	//std::cout << lista <<std::endl;

	p2 = ITR.primeiro();

	std::cout<<"NOME = "<<p2.getNome()<<std::endl;

	for(;ITR.existeProximo();){std::cout<<"----------"<<std::endl;
		arquivoOrdenado << p2.getNome() << std::endl;
		p2 = ITR.proximo();
	}





	arquivo.close();
	arquivoOrdenado.close();

}
