#ifndef ENDERECO_H_
#define ENDERECO_H_
#include<string>
namespace Capsula {

class Endereco {
private:
	std::string dado;
public:
	Endereco(){};
	~Endereco(){};

	void setDado(std::string dado){this->dado = dado;}
	std::string getDado()const{return this->dado;}
};

}

#endif /* ENDERECO_H_ */
