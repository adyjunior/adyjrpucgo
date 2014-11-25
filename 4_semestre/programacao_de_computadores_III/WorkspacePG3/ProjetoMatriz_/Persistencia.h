#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_
#include"Matriz.h"
#include<string>


namespace VilaNova {

class Persistencia {
public:
	Persistencia(){};
	~Persistencia(){};
	bool gravar(Matriz const &matriz, std::string const &nomeDoArquivo);
	Matriz * recuperar(std::string const &nomeDoArquivo);
};

}

#endif /* PERSISTENCIA_H_ */
