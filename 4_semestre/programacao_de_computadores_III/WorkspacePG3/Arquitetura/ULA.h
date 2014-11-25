#ifndef ULA_H_
#define ULA_H_


#include"Endereco.h"
#include"MemoriaPrincipal.h"
#include<sstream>
#include<iostream>
#include<fstream>


namespace Capsula {

class ULA {
private:
	Endereco acumulador;
	Endereco mq;
	MemoriaPrincipal memoria;


public:

	ULA(){}
	void load(){acumulador.setDado(mq.getDado());}//transfere o conteudo do registrador MQ para AC;
	void load(int endereco);//transfere o conteudo da posicao de memoria X para MQ
	void load(int endereco,int modulo);//transfere o conteudo da posicao de memoria X para AC;
	void stor(int endereco,std::string parametro2);//Transfere o conteudo do acumulador para a posicao de memoria X
	void jump(int endereco,std::string parametro2);
	static bool isJumpRigth;
	static bool isJumpLeft;

	void add(int endereco,int modulo);
	void sub(int endereco,int modulo);
	void mul(int endereco);
	void div(int endereco);

	void lsh();
	void rsh();


	void setAculumador(Endereco ac){acumulador = ac;}
	void setMq(Endereco _mq){mq = _mq;}

	Endereco getAcumulador(){return acumulador;}
	Endereco getMq(){return mq;}

	//Memoria
	void ulaCarregaMemoria(std::string nomeDoArquivo);
	std::string ulaGetMemoria(int endereco);
	void ulaSetMemoria(int endereco,std::string dado);
	int getIndeceDeUsoDaMemoria()const{return memoria.getIndeceDeUso();}


private:
	void equal(std::string &a,std::string &b);
	void add(int endereco,int binario,int c);
	void sub(int endereco,int binario,int c);


};

}

#endif /* ULA_H_ */
