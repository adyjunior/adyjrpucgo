#include "MapeadorDeDadosLocacao.h"

MapeadorDeDadosLocacao::MapeadorDeDadosLocacao():
					nomeDoArquivoNoDisco("ArquivoDeLocacao.txt")
{
	std::fstream arquivo;
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
	if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc);
	arquivo.close();
}

bool MapeadorDeDadosLocacao::buscarNoArmazenamento(int id, ItemPersistencia *objeto)
{
	std::fstream arquivo;

	try{
		std::string linha;
		Locacao locacaoAux;
		Locacao *locacao;
		locacao=static_cast<Locacao *>(objeto);
		arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);

		if(!arquivo.is_open())throw(8);

		getline(arquivo,linha);
		while(!arquivo.eof()){
			locacaoAux.materializar(linha);
			if(id==locacaoAux.obterIdentificador()){
				arquivo.close();
				locacao->materializar(linha);
				return true;
			}
			getline(arquivo,linha);
		}
		arquivo.close();
		return false;

	}catch(int valorErro){
		if(valorErro != 8)
			arquivo.close();

		throw valorErro;
	}
}

void MapeadorDeDadosLocacao::gravarNoArmazenamento(ItemPersistencia *objeto)
{
	std::ofstream arquivo;
	try{
		// Convertendo da variavel polimorfica do tipo ItemPersistencia para uma do tipo Locacao
		Locacao *locacao;
		locacao=static_cast<Locacao *>(objeto);

		//  Gravar no arquivo

		arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::app);

		if(!arquivo.is_open())throw(8);

		std::string linha = locacao->desmaterializar();
		arquivo<<linha<<std::endl;
		arquivo.close();

	}catch(int valorErro){
		if(valorErro != 8)
			arquivo.close();

		throw valorErro;
	}
}

void MapeadorDeDadosLocacao::removerNoArmazenamento(ItemPersistencia *objeto)
{
	std::fstream arquivoAux;
	std::fstream arquivo;
	try{
	  	// Criando Arquivo Auxiliar

	  	arquivoAux.open("ArquivoTemporario.txt",std::ios::out|std::ios::trunc);

		if(!arquivoAux.is_open())throw(8);
	  		
	  	//  abrindo arquivo Original no inicio	

		arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);

		if(!arquivo.is_open())throw(8);

		std::string linha;
		Locacao locacaoAux;	
		int id= objeto->obterIdentificador();
		
		getline(arquivo,linha);
		while(!arquivo.eof()){
			locacaoAux.materializar(linha);
			if(id!=locacaoAux.obterIdentificador())arquivoAux<<linha<<std::endl;
			getline(arquivo,linha);
		}
		arquivo.close();	
		arquivoAux.close();
		
		// Apagando arquivo Original
		std::string comando = "del "+nomeDoArquivoNoDisco;	// mudar
		system(comando.c_str()); // mudar
		
		// Renomeia arquivo Auxiliar
		comando = "copy  "; // mudar
		comando += "ArquivoTemporario.txt  "; // mudar
		comando += nomeDoArquivoNoDisco;	// mudar
		system(comando.c_str()); // mudar
		
		comando = "del ";
		comando +="ArquivoTemporario.txt ";	 // mudar
		system(comando.c_str());  // mudar

	}catch(int valorErro){
		if(valorErro != 8){
			arquivo.close();
			arquivoAux.close();
		}

		throw valorErro;
	}

			
}
