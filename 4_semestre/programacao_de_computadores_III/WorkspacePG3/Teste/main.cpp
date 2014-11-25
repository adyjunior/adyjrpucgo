#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"CDC.h"
#include"Memoria.h"

using namespace std;


Memoria vetor[100];

int isOperation(std::string linha){
	for(unsigned int i=0;i < linha.size();i++){
		if(linha[i] == '|')
			return 2; //Operaco modular EX: add|(10)|
		if(linha[i] == '(' || linha[i] == ')')
			return 1;//Operacao EX: load(10)

	}
	return 0; // se for Numero;
}

void trataOperacao(std::string instrucao="load(10)",int pos=0){

	int busca,busca2;
	std::string str;
	std::string Identificador;
	int parametro=0;

	busca = instrucao.find('(');
	busca2 = instrucao.find(')');

	if(instrucao[busca+1] == ')')
		Identificador = instrucao;
	else{
		Identificador = instrucao.substr(0,busca);
		str = instrucao.substr(busca+1,busca2-busca-1);
		parametro = std::atoi(str.c_str());
	}

	vetor[pos].setMSDado(Identificador);
	vetor[pos].setMSEndereco(parametro);
}

void trataModular(std::string instrucao="load|(10)|",int pos=0){

	int busca,busca2;
	std::string str;
	std::string Identificador;
	int parametro=0;

	busca = instrucao.find('|');
	busca2 = instrucao.find('|',busca+1);


	Identificador = instrucao.substr(0,busca);
	str = instrucao.substr(busca+2,busca2-busca-1);
	parametro = std::atoi(str.c_str());


	vetor[pos].setMSDado(Identificador);
	vetor[pos].setMSEndereco(parametro);

}

void trataValor(std::string linha="122212",int pos=0){
	vetor[pos].setConteudo(std::atoll(linha.c_str()));
}

void separaPalavra(std::string linha,std::string &parte1,std::string &parte2){

	int div,div2;

	div = linha.find(';');
	div2 = linha.find(';',div+1);

	parte1 = linha.substr(0,div);
	//cout<<parte1<<endl;

	parte2 = linha.substr(div+1,div2-div-1);
}

void defineInstrucoes(std::string instrucao,int pos){
	if(isOperation(instrucao)== 1){
		trataOperacao(instrucao,pos);
	}
	else if(isOperation(instrucao) == 2){
		trataModular(instrucao,pos);
	}

}

void compilador(){
	std::ifstream arquivo("arquitetura.txt");
	std::string linha;
	if(!arquivo.is_open())throw std::string("Arquivo nao pode ser aberto !");

	for(int pos=0;!arquivo.eof();pos++){
		std::getline(arquivo,linha);
		if(isOperation(linha) != 0){
			std::string primeiraInstrucao,segundaInstrucao;
			separaPalavra(linha,primeiraInstrucao,segundaInstrucao);

			defineInstrucoes(primeiraInstrucao,pos);
			defineInstrucoes(segundaInstrucao,pos);
		}
		else{
			if(linha != "")
				trataValor(linha,pos);
		}


	}

}



int main(){
	try{
		//compilador();
		//for(int i=0;i < 25;i++)
			//cout<<"Pos "<<(i+1)<<" - instrucoes -> "<<vetor[i].getMSDado()<<"("<<vetor[i].getMSEndereco()<<") - "<<vetor[i].getMSDado()<<"("<<vetor[i].getLSEndereco()<<")  | Conteudo = "<<vetor[i].getConteudo()<<endl;

		for(int i=0;i < 5;i++){
			std::cout<<"--------------------------------------------------"<<std::endl;//50
			std::cout<<"Aperte < ENTER >"<<std::endl;
			std::getchar();

		}

	}catch(std::string erro){
		cout<<erro<<endl;
	}
/*
	cout<<endl<<endl<<endl<<endl;
	cout<<"                              \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB"<<endl;
	cout<<"                              \xba       MENU MATRIZ      \xba"<<endl;
	cout<<"                              \xba                        \xba"<<endl;
	cout<<"                              \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9"<<endl;
	cout<<"                              \xba  1 - MANIPULAR MATRIZES\xba"<<endl;
	cout<<"                              \xba  2 - OPERACOES         \xba"<<endl;
	cout<<"                              \xba  0 - SAIR              \xba"<<endl;
	cout<<"                              \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc"<<endl;

	cout<<endl<<endl<<"  OPCAO: ";


	cout<<endl<<endl<<endl<<endl;
	cout<<"                              \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB"<<endl;
	cout<<"                              \xba    MANIPULAR MATRIZ    \xba"<<endl;
	cout<<"                              \xba                        \xba"<<endl;
	cout<<"                              \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9"<<endl;
	cout<<"                              \xba  1 - GRAVAR            \xba"<<endl;
	cout<<"                              \xba  2 - RECUPERAR         \xba"<<endl;
	cout<<"                              \xba  3 - APAGAR            \xba"<<endl;
	cout<<"                              \xba  0 - SAIR              \xba"<<endl;
	cout<<"                              \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc"<<endl;


	cout<<endl<<endl<<endl<<endl;
	cout<<"                              \xC9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB"<<endl;
	cout<<"                              \xba        OPERACAO MATRIZES       \xba"<<endl;
	cout<<"                              \xba                                \xba"<<endl;
	cout<<"                              \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9"<<endl;
	cout<<"                              \xba  01 - ADICAO                   \xba"<<endl;
	cout<<"                              \xba  02 - SUBTRACAO                \xba"<<endl;
	cout<<"                              \xba  03 - MULTIPLICACAO            \xba"<<endl;
	cout<<"                              \xba  04 - MATRIZES IGUAIS          \xba"<<endl;
	cout<<"                              \xba  05 - MATRIZES DIFERENTES      \xba"<<endl;
	cout<<"                              \xba  06 - TRIANGULAR SUPERIOR      \xba"<<endl;
	cout<<"                              \xba  07 - TRIANGULAR INFERIOR      \xba"<<endl;
	cout<<"                              \xba  08 - SIMETRICA                \xba"<<endl;
	cout<<"                              \xba  09 - ANTI-SIMETRICA           \xba"<<endl;
	cout<<"                              \xba  10 - IDENTIDADE               \xba"<<endl;
	cout<<"                              \xba  11 - TRANSPOSTA               \xba"<<endl;
	cout<<"                              \xba  12 - PERMUTACAO               \xba"<<endl;
	cout<<"                              \xba  13 - MULTIPLICACAO POR K      \xba"<<endl;
	cout<<"                              \xba  14 - ORTOGONAL                \xba"<<endl;
	cout<<"                              \xba  15 - POTENCIACAO DE MATRIZ    \xba"<<endl;
	cout<<"                              \xba  16 - RECUPERAR                \xba"<<endl;
	cout<<"                              \xba  0  - SAIR                     \xba"<<endl;
	cout<<"                              \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc"<<endl;
*/

/*

	std::string  a = "10101100";
	std::string  b = "1111100000000000";

	std::string resultante ;
	int diferenca,tam;
	if(a.size() > b.size()){

		diferenca = a.size() - b.size();
		tam = a.size();
		resultante = a;

		for(int i=0;i < tam;i++){
			if(i < diferenca)
				resultante[i] = '0';
			else
				resultante[i] = b[i-diferenca];
		}

		b = resultante;

	}
	else{

		diferenca = b.size() - a.size();

		tam = b.size();
		resultante = b;
		for(int i=0;i < tam;i++){
			if(i < diferenca)
				resultante[i] = '0';
			else
				resultante[i] = a[i-diferenca];
	}
		a = resultante;

	}

		cout<<endl<<a;



	CadeiaCaracteres::CDC conversao;

	std::string nome;
	long telefone;
	std::string endereco;
	std::string email;
	long long cpf;
	int d,m,a;

	std::string materializada;
	std::string data;
	//materializada = nome + ";" + strTelefone + ";" +  endereco + ";" + strCPF + ";" + data + ";" + email;
	//int dia,mes,ano;
	//this->getDataDeNascimento(dia,mes,ano);


	cout<<materializada;


	std::string linha="Ady Junior;32103584;Av Genesio de lima brito;1234567890;10102000;tigrao@gmail.com";

	unsigned int pos=0;


	nome = conversao.buscarSubString(linha,pos,';');
	telefone = conversao.converteStrParaInteiroLongo(conversao.buscarSubString(linha,pos,';'));
	endereco = conversao.buscarSubString(linha,pos,';');
	cpf = conversao.converteStrParaInteiroLongoLongo(conversao.buscarSubString(linha,pos,';'));
	data = conversao.buscarSubString(linha,pos,';');
	email = conversao.buscarSubString(linha,pos,';');

	d = conversao.converteStrParaInteiro(data.substr(0,2));
	m = conversao.converteStrParaInteiro(data.substr(2,2));
	a =  conversao.converteStrParaInteiro(data.substr(4,4));


	cout<<nome<<endl;
	cout<<telefone<<endl;
	cout<<endereco<<endl;
	cout<<cpf<<endl;
	cout<<d<<m<<a<<endl;
	cout<<email<<endl;

	*/

	///////////////////////////////////////////////////////////////////////

/*	cout<<"Inicio";
	std::ifstream arquivoDeEntrada("arquivoPaciente.txt");



	std::string l,l2;
	int tam;
	for(tam=0;!arquivoDeEntrada.eof();tam++){std::getline(arquivoDeEntrada,l2);}
	//const int tamanho = tam;
	cout<<"euvi";
	std::string linha2[tam];



	for(int i=0;i < tam;i++){
		cout<<"For 1"<<endl;
		std::getline(arquivoDeEntrada,l);
			if(i == 2)
				 linha2[i] = l;
	}

	cout<<"meio";

	arquivoDeEntrada.close();

	std::ofstream arquivoDeSaida("arquivoPaciente.txt");


	for(int i = 0;i < tam;i++){
		cout<<"For 2"<<endl;
		arquivoDeSaida << linha2[i];
	}

	arquivoDeSaida.close();

	*/



//system("pause");
}



