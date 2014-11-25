#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_
#include<string>
#include<fstream>
#include<list>
#include"Paciente.h"
#include"Iterator.h"


namespace PSP {

class Persistencia {
private:
	std::string nomeDoArquivo;
	Persistencia(std::string const &nomeDoArquivo);
	static Persistencia *instancia;
public:
	~Persistencia(){if(instancia) delete instancia;}
	static Persistencia *getInstancia(std::string const &nomeDoArquivo);
	void gravar(Paciente const &paciente)const;
	void recuperar(Paciente &paceiente)const;
	void apagar(std::string const &nome)const;
	void alterar(Paciente &paciente)const;
	bool buscar(std::string const &nome)const;
	Container::Iterator<Paciente*> *listar()const;

};

}

#endif /* PERSISTENCIA_H_ */
