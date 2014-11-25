#include "MapeadorDeDadosCliente.h"

MapeadorDeDadosCliente::MapeadorDeDadosCliente():
					nomeDoArquivoNoDisco("ArquivoDeCliente.txt")
{
	std::fstream arquivo;
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
	if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc);
	arquivo.close();
}

bool MapeadorDeDadosCliente::buscarNoArmazenamento(int id, ItemPersistencia *objeto)
{
	std::fstream arquivo;
	try{

	std::string linha;
	Cliente pessoaAux;
	Cliente *pessoa;
	pessoa=static_cast<Cliente *>(objeto);
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
	
	if(!arquivo.is_open())throw(6);

	getline(arquivo,linha);
	while(!arquivo.eof()){
		pessoaAux.materializar(linha);
		if(id==pessoaAux.obterIdentificador()){
			arquivo.close();
			pessoa->materializar(linha);
			return true;
		}
		getline(arquivo,linha);
	}
	arquivo.close();
	return false;

	}catch(int valorErro){
        if(valorErro != 6)
                arquivo.close();

		throw valorErro;
	}

}

void MapeadorDeDadosCliente::gravarNoArmazenamento(ItemPersistencia *objeto)
{
	std::ofstream arquivo;
	try{
		// Convertendo da variavel polimorfica do tipo ItemPersistencia para uma do tipo Cliente
	  		Cliente *cliente;
	  		cliente=static_cast<Cliente *>(objeto);
	  		
	  	//  Gravar no arquivo	

			arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::app);
			
			if(!arquivo.is_open())throw(6);

			std::string linha = cliente->desmaterializar();
			arquivo<<linha<<std::endl;
			arquivo.close();		
	}catch(int valorErro){
        if(valorErro != 6)
                arquivo.close();

		throw valorErro;
	}

}

void MapeadorDeDadosCliente::removerNoArmazenamento(ItemPersistencia *objeto)
{
	std::fstream arquivo;
	std::fstream arquivoAux;
	try{
	  	// Criando Arquivo Auxiliar

	  	arquivoAux.open("ArquivoTemporario.txt",std::ios::out|std::ios::trunc);	

		if(!arquivoAux.is_open())throw(6);
	  		
	  	//  abrindo arquivo Original no inicio	

		arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);

		if(!arquivo.is_open())throw(6);

		std::string linha;
		Cliente pessoaAux;	
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
		comando += "ArquivoTemporario.txt  "; // mudar
		comando += nomeDoArquivoNoDisco;	// mudar
		system(comando.c_str()); // mudar
		
		comando = "del ";
		comando +="ArquivoTemporario.txt ";	 // mudar
		system(comando.c_str());  // mudar

	}catch(int valorErro){
        if(valorErro != 6){
                arquivo.close();
                arquivoAux.close();
        }
		throw valorErro;
	}

			
}

Container::Iterator<Cliente*> *MapeadorDeDadosCliente::listarNoArmazenamento(){
    std::ifstream arquivoDeLeitura(this->nomeDoArquivoNoDisco.c_str());

    try{
            if(!arquivoDeLeitura.is_open())throw (6);
            std::string linha;
            Cliente *cli;



            std::list<Cliente*> lista;


            for(;!arquivoDeLeitura.eof();){
                    std::getline(arquivoDeLeitura,linha);
                    if(linha != "") {
                            cli = new Cliente();
                            cli->materializar(linha);
                            lista.push_back(cli);
                    }
            }
            arquivoDeLeitura.close();
            Container::Iterator<Cliente*> *it;
            it = new Container::Iterator<Cliente*>(lista);

            return it;


    }catch(int valorErro){
            if(valorErro != 6)
                    arquivoDeLeitura.close();
            //delete it;
            throw valorErro;
    }catch(std::bad_alloc&){
            arquivoDeLeitura.close();
            throw (12);
    }

}






