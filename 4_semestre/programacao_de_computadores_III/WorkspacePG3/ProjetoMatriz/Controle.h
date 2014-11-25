#ifndef CONTROLE_H_
#define CONTROLE_H_
#include"Persistencia.h"
namespace PC3 {

class Controle {
private:
	Persistencia persistir;
public:
	Controle(){};
	~Controle(){};
	void processoGravar(Matriz const &matriz, std::string const &nomeDoArquivo)const;
	Matriz *processoRecuperar(std::string const &nomeDoArquivo)const;
	void processoApagar(std::string const &nomeDoArquivoNoDisco)const;
};

}

#endif /* CONTROLE_H_ */
