#ifndef CONTROLE_H_
#define CONTROLE_H_
#include"Persistencia.h"

namespace PSP {

class Controle {
private:
	Persistencia *gravar;
public:
	Controle(std::string const &nomeDoArquivo){gravar = Persistencia::getInstancia(nomeDoArquivo);}
	void inclusaoPaciente(Paciente & paciente)const;
	void exclusaoPaciente(std::string const &nome)const;
	void alteracaoPaciente(Paciente &paciente)const;
	void recuperarPaciente(Paciente &paciente)const;
	Container::Iterator<Paciente*> *listarPaciente()const;
};

}

#endif /* CONTROLE_H_ */
