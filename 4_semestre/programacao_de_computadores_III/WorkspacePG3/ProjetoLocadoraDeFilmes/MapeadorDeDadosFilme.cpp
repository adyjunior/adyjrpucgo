#include "MapeadorDeDadosFilme.h"

MapeadorDeDadosFilme::MapeadorDeDadosFilme():
					nomeDoArquivoNoDisco("ArquivoDeFilme.txt")
{
	std::fstream arquivo;
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
	if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc);
	arquivo.close();
}

bool MapeadorDeDadosFilme::buscarNoArmazenamento(int id, ItemPersistencia *objeto)
{
	std::fstream arquivo;

	try{
	std::string linha;
	Filme filmeAux;
	Filme *filme;
	filme=static_cast<Filme *>(objeto);
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);

	if(!arquivo.is_open())throw(7);

	getline(arquivo,linha);
	while(!arquivo.eof()){
		filmeAux.materializar(linha);
		if(id==filmeAux.obterIdentificador()){
			arquivo.close();
			filme->materializar(linha);
			return true;
		}
		getline(arquivo,linha);
	}
	arquivo.close();
	return false;
	}catch(int valorErro){
        if(valorErro != 7)
        	arquivo.close();
        throw valorErro;
	}
}

void MapeadorDeDadosFilme::gravarNoArmazenamento(ItemPersistencia *objeto)
{
		std::ofstream arquivo;

	try{
		// Convertendo da variavel polimorfica do tipo ItemPersistencia para uma do tipo Cliente
			Filme *filme;
	  		filme=static_cast<Filme *>(objeto);

	  	//  Gravar no arquivo
			arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::app);

			if(!arquivo.is_open())throw(7);

			std::string linha = filme->desmaterializar();
			arquivo<<linha<<std::endl;
			arquivo.close();
	}catch(int valorErro){
        if(valorErro != 7)
        	arquivo.close();
        throw valorErro;
	}
}

void MapeadorDeDadosFilme::removerNoArmazenamento(ItemPersistencia *objeto)
{
	std::fstream arquivo;
	std::fstream arquivoAux;
	try{
	  	// Criando Arquivo Auxiliar

	  	arquivoAux.open("ArquivoTemporarioFilme.txt",std::ios::out|std::ios::trunc);

		if(!arquivoAux.is_open())throw(7);
	  	//  abrindo arquivo Original no inicio

		arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);

		if(!arquivo.is_open())throw(7);
		std::string linha;
		Filme pessoaAux;
		int id= objeto->obterIdentificador();

		getline(arquivo,linha);
		while(!arquivo.eof()){
			pessoaAux.materializar(linha);
			if(id!=pessoaAux.obterIdentificador())arquivoAux<<linha<<std::endl;
			getline(arquivo,linha);
		}
		arquivo.close();
		arquivoAux.close();

		// Apagando arquivo Original
		std::string comando = "del "+nomeDoArquivoNoDisco;	// mudar
		system(comando.c_str()); // mudar

		// Renomeia arquivo Auxiliar
		comando = "copy  "; // mudar
		comando += "ArquivoTemporarioFilme.txt  "; // mudar
		comando += nomeDoArquivoNoDisco;	// mudar
		system(comando.c_str()); // mudar

		comando = "del ";
		comando +="ArquivoTemporarioFilme.txt ";	 // mudar
		system(comando.c_str());  // mudar
	}catch(int valorErro){
        if(valorErro != 7){
        	arquivo.close();
        	arquivoAux.close();
        }
		throw valorErro;
	}

}


Container::Iterator<Filme*> *MapeadorDeDadosFilme::listarNoArmazenamento(){
    std::ifstream arquivoDeLeitura(this->nomeDoArquivoNoDisco.c_str());

    try{
            if(!arquivoDeLeitura.is_open())throw (7);
            std::string linha;
            Filme *filme;



            std::list<Filme*> lista;


            for(;!arquivoDeLeitura.eof();){
                    std::getline(arquivoDeLeitura,linha);
                    if(linha != "") {
							filme = new Filme();
							filme->materializar(linha);
                            lista.push_back(filme);
                    }
            }
            arquivoDeLeitura.close();
            Container::Iterator<Filme*> *it;
            it = new Container::Iterator<Filme*>(lista);

            return it;


    }catch(int valorErro){
            if(valorErro != 7)
            	arquivoDeLeitura.close();
            //delete it;
            throw valorErro;
    }catch(std::bad_alloc&){
            arquivoDeLeitura.close();
            throw (9);
    }

}


