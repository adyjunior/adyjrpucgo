#include "MemoriaPrincipal.h"

namespace Capsula {


int MemoriaPrincipal::indeceDeUso = 0;

Endereco *MemoriaPrincipal::memoria = new Endereco[SIZE];

std::string MemoriaPrincipal::getMemoria(int endereco){
	if(endereco < 0)throw(std::string)("FALHA DE SEGMENTACAO !");
	return memoria[endereco].getDado();
}


void MemoriaPrincipal::setMemoria(int endereco,std::string dado){
	if(endereco < 0)throw(std::string)("FALHA DE SEGMENTACAO !");
	memoria[endereco].setDado(dado);
	indeceDeUso++;
}

/*void MemoriaPrincipal::operator =(MemoriaPrincipal _memoria){
	for(int i=0;i < _memoria.getIndeceDeUso();i++){
		memoria[i] = _memoria.memoria[i];
	}
	indeceDeUso = _memoria.indeceDeUso;
}*/

}
