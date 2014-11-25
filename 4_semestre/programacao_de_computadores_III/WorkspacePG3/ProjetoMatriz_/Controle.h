
#ifndef CONTROLE_H_
#define CONTROLE_H_
#include<string>
#include"Persistencia.h"
#include"Matriz.h"

namespace VilaNova {

class Controle {
private:
	Persistencia matrizesEmArquivo;
public:
	Controle(){};
	~Controle(){};
	void gravarMatriz(Matriz const &matriz, std::string const &nomeDoArquivo);
	Matriz *recuperarMatriz(std::string const &nomeDoArquivo);
	void apagarMatriz(std::string const &nomeDoArquivo);
};

}

#endif /* CONTROLE_H_ */
