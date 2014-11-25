#include "Persistencia.h"
#include"CDC.h"
#include<iostream>
namespace PSP {

Persistencia::Persistencia(std::string const &nomeDoArquivo){
    std::ifstream arquivoDeEntrada(nomeDoArquivo.c_str());// se nao existir ele cria;
    std::ofstream arquivoBackup;

    if(!arquivoDeEntrada.is_open()){

    	arquivoBackup.open(nomeDoArquivo.c_str());
    }
    this->nomeDoArquivo = nomeDoArquivo;
    arquivoDeEntrada.close();
    arquivoBackup.close();

}

Persistencia *Persistencia::instancia = 0;

Persistencia *Persistencia::getInstancia(std::string const &nomeDoArquivo){
	try{
	if(!instancia)
		instancia = new Persistencia(nomeDoArquivo); //BAD_ALLOC
	return instancia;
	}catch(std::bad_alloc&){
		throw (12);
	}
}


void Persistencia::gravar(Paciente const &paciente)const{

	std::ofstream arquivoDeSaida(this->nomeDoArquivo.c_str(),std::ofstream::app);
	try{

		if(!arquivoDeSaida.is_open())throw(4);//arquivo nao pode ser aberto
		std::string linha = paciente.desmaterializar(); // lanca excecao

		arquivoDeSaida << linha << std::endl;

		arquivoDeSaida.close();

	}catch(int valorErro){
		if(valorErro!=4)
			arquivoDeSaida.close();
		throw valorErro; //FECHAR O ARQUIVO
	}

}

void Persistencia::recuperar(Paciente &paciente)const{
	std::ifstream arquivoDeEntrada(this->nomeDoArquivo.c_str());
	Paciente aux;

	try{
		if(!arquivoDeEntrada.is_open())throw(4);//arquivo nao pode ser aberto

		std::string linha = paciente.desmaterializar();

		for(;!arquivoDeEntrada.eof();){
			std::getline(arquivoDeEntrada,linha);
			if(linha != "")
				aux.materializar(linha);//lanca excecao
			if(aux.getNome() == paciente.getNome())
				break;

		}


		arquivoDeEntrada.close();
	}catch(int valorErro){ // FECHAR O ARQUIVO
		if(valorErro!=4)
			arquivoDeEntrada.close();
		throw valorErro;
	}
}

void Persistencia::apagar(std::string nome)const{
	Paciente p;
	std::ifstream arquivoDeLeitura(this->nomeDoArquivo.c_str());
	std::ifstream arquivoDeLeitura2;
	std::ofstream arquivoDeEscrita;

	try{
		CadeiaCaracteres::CDC::converteStringParaMaiuscula(nome);
		if(!arquivoDeLeitura.is_open())throw(4);

		int tam=0,posicao=0;
		std::string linha;
		for(;!arquivoDeLeitura.eof();tam++){
			std::getline(arquivoDeLeitura,linha);
		}


		arquivoDeLeitura.close();
		tam--;
		std::string vet[tam];

		arquivoDeLeitura2.open(this->nomeDoArquivo.c_str(),std::ios::in);


		for(int i=0;i < tam;i++){
			std::getline(arquivoDeLeitura2,vet[i]);//std::cout<<"Posicao ( "<<i<<" ) = "<<vet[i]<<std::endl;
			p.materializar(vet[i]);
			if(p.getNome()== nome){ std::cout<<"Nome : "<<nome<<" == "<<p.getNome()<<"Posicao == "<<i<<std::endl; posicao = i;}   //std::cout<<"POSICAO NO IF -> ( "<<i<<" ) = "<<vet[i]<<std::endl;}
		}


		arquivoDeLeitura2.close();
		arquivoDeEscrita.open(this->nomeDoArquivo.c_str());

		for(int i=0;i < tam;i++){
			if(i != posicao)
				arquivoDeEscrita << vet[i] <<std::endl;
		}
		arquivoDeEscrita.close();

	}catch(int valorErro){
		if(valorErro != 4){
			arquivoDeLeitura.close();
			arquivoDeLeitura2.close();
			arquivoDeEscrita.close();
		}
		throw valorErro;

	}

}




void Persistencia::alterar(Paciente &paciente)const{
	try{
		//Classe controle -> if( !this->buscar(paciente.getNome()) )throw (5);//Nome nao encontrado;
		this->apagar(paciente.getNome());
		this->gravar(paciente);

	}catch(int valorErro){
		throw valorErro;
	}
}

bool Persistencia::buscar(std::string nome)const{
	std::ifstream arquivoParaLeitura(this->nomeDoArquivo.c_str());
	try{
		CadeiaCaracteres::CDC::converteStringParaMaiuscula(nome);
		Paciente p;
		std::string linha;
		if(!arquivoParaLeitura.is_open())throw(4);

		for(;!arquivoParaLeitura.eof();){
			std::getline(arquivoParaLeitura,linha);//std::cout<<linha<<std::endl;
			if(linha != "")
				p.materializar(linha); //std::cout<<"Nome : "<<nome<<" == "<<p.getNome()<<std::endl;

			if(p.getNome() == nome)
				{std::cout<<"RETURN -> "<<p.getNome()<<std::endl;return true;}
		}

		return false;
	}catch(int valorErro){
		if(valorErro !=4)
			arquivoParaLeitura.close();
		throw valorErro;
	}

}


Container::Iterator<Paciente*> *Persistencia::listar()const{
	std::ifstream arquivoDeLeitura(this->nomeDoArquivo.c_str());

	try{
		if(!arquivoDeLeitura.is_open())throw (4);
		std::string linha;
		Paciente *paciente;



		std::list<Paciente*> lista;

		//lista = new std::list<Paciente>;

		for(;!arquivoDeLeitura.eof();){
			std::getline(arquivoDeLeitura,linha);
			if(linha != "") {
				paciente = new Paciente();
				paciente->materializar(linha);
				lista.push_back(paciente);
			}
		}
		arquivoDeLeitura.close();
		Container::Iterator<Paciente*> *it;
		it = new Container::Iterator<Paciente*>(lista);

		return it;


	}catch(int valorErro){
		if(valorErro != 4)
			arquivoDeLeitura.close();
		//delete it;
		throw valorErro;
	}catch(std::bad_alloc&){
		arquivoDeLeitura.close();
		throw (12);
	}

}



}
