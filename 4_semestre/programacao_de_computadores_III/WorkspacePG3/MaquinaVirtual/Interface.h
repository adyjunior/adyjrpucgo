#ifndef INTERFACE_H_
#define INTERFACE_H_
#include"MaquinaVirtual.h"
#include"Controle.h"
#include"ULA.h"

namespace Capsula {

class Interface {
	MaquinaVirtual mv;
	std::string nomeDoArquivo;

public:
	Interface(std::string nomeDoArquivo):nomeDoArquivo(nomeDoArquivo){}
	~Interface(){};
	void menu();
	void instrucoesExistentes();
	void carregaArquivoNaMemoria();
	void conteudoMemoria();
	void conteudoRegistradores();
	void conteudoArquivo();
	void executarPrograma();

};

}

#endif /* INTERFACE_H_ */
