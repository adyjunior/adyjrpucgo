#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_
#include"Matriz.h"
#include<fstream>
namespace PC3 {

class Persistencia {
public:
	Persistencia(){};
	~Persistencia(){};
	void gravar(Matriz const &matriz, std::string const &nomeDoArquivoNoDisco)const;
	Matriz * recuperar(std::string const &nomeDoArquivoNoDisco)const;
	void apagar(std::string const &nomeDoArquivo)const;
};

}



#endif /* PERSISTENCIA_H_ */
