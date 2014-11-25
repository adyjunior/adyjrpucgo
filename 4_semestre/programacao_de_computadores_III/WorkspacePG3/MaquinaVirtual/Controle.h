#ifndef CONTROLE_H_
#define CONTROLE_H_

#include"ULA.h"
namespace Capsula {

class Controle {
private:
	std::string ibr;
	static int pc;
	std::string mbr;
	std::string ir;
	std::string mar;



public:
	Controle(){};
	~Controle(){};
	void decodificacao(std::string identificador,int endereco,std::string parametro2,int modulo=1);
	void escolhaDeOperacoes(int opcao,int endereco,int modulo,std::string parametro2="");
    void setIbr(std::string ibr){this->ibr = ibr;};
    void setIr(std::string ir){this->ir = ir;}
    void setMar(std::string mar){this->mar = mar;}
	void setMbr(std::string _mbr){mbr = _mbr;}
	ULA ula;
    static void setPc(int _pc){pc = _pc;}
    //void setULA(ULA ula){this->ula = ula;}
    //ULA getULA()const{return ula;}
    std::string getIbr() const{return ibr;}
    std::string getIr() const{return ir;}
    std::string getMar() const{return mar;}
	std::string getMbr(){return mbr;}
    static int getPc() {return pc;}

    // operacoesMemoria
    void controleCarregaMemoria(std::string nomeDoArquivo);
    //void getVetor(MemoriaPrincipal mem){this->ula.setVetor(mem);}
    //void setMemoria(MemoriaPrincipal mem){}




};

}

#endif /* CONTROLE_H_ */
