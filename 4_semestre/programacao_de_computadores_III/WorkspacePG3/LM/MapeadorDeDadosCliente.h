//***********************************************************************************
//			CLASSE MAPEADOR DE DADOS DO CLIETNE NA PERSISTENCIA
//***********************************************************************************
class MapeadorDeCliente:  public MapeadorDeDados
{
		private:
			const std::string nomeDoArquivoNoDisco;
	  	public:
	  		MapeadorDeCliente();
	  		void gravarNoArmazenamento(ItemPersistencia *item);
	  		bool buscarNoArmazenamento(unsigned int id,ItemPersistencia *item);
	  		void removerNoArmazenamento(ItemPersistencia *item);
};

MapeadorDeCliente::MapeadorDeCliente():
					nomeDoArquivoNoDisco("ArquivoDeCliente.txt")
{
	std::fstream arquivo;
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
	if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc);
	arquivo.close();
}

bool MapeadorDeCliente::buscarNoArmazenamento(unsigned int id, ItemPersistencia *item)
{
	std::fstream arquivo;
	std::string linha;
	Cliente pessoaAux;
	Cliente *pessoa;
	pessoa=static_cast<Cliente *>(item);
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
	getline(arquivo,linha);
	while(!arquivo.eof()){
		pessoaAux.materializar(linha);
		if(id==pessoaAux.obterIdentificador()){
			arquivo.close();
			std::string nome,email;
			unsigned int id;
			long telefone;
			pessoaAux.obter(id,nome,telefone,email);
			pessoa->atribuir(id,nome,telefone,email);
			return true;
		}
		getline(arquivo,linha);
	}
	arquivo.close();
	return false;
}

void MapeadorDeCliente::gravarNoArmazenamento(ItemPersistencia *item)
{
		// Convertendo da variavel polimorfica do tipo ItemPersistencia para uma do tipo Cliente
	  		Cliente *cliente;
	  		cliente=static_cast<Cliente *>(item);

	  	//  Gravar no arquivo
	  		std::ofstream arquivo;
			arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::app);

			std::string linha = cliente->desmaterializar();
			arquivo<<linha<<std::endl;
			arquivo.close();
}


//   ESTOU AQUI

void MapeadorDeCliente::removerNoArmazenamento(ItemPersistencia *item)
{
		// Convertendo da variavel polimorfica do tipo ItemPersistencia para uma do tipo Cliente
	  	//	Cliente *cliente;
	  	//	cliente=static_cast<Cliente *>(item);

	  	// Criando Arquivo Auxiliar
	  	std::fstream arquivoAux;
	  	arquivoAux.open("ArquivoTemporario.txt",std::ios::out|std::ios::trunc);

	  	//  abrindo arquivo Original no inicio
	  	std::fstream arquivo;
		arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);

		std::string linha;
		Cliente pessoaAux;
		unsigned int id= item->obterIdentificador();

		getline(arquivo,linha);
		while(!arquivo.eof()){
			pessoaAux.materializar(linha);
			if(id!=pessoaAux.obterIdentificador())arquivoAux<<linha<<std::endl;
			getline(arquivo,linha);
		}
		arquivo.close();
		arquivoAux.close();

		// Apagando arquivo Original
//		std::string comando = "rm "+nomeDoArquivoNoDisco;
//		system(comando.c_str());

		// Renomeia arquivo Auxiliar
//		comando =

}
