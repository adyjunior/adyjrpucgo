#ifndef ITEMPERSISTENCIA_H_
#define ITEMPERSISTENCIA_H_
#include<string>
//********************************************************************
//                                   Construida e testeda
//********************************************************************

class ItemPersistencia
{
	protected:
		unsigned int identificador;
		unsigned int tipoDaClasse;
	public:
		ItemPersistencia(unsigned int identificador):identificador(identificador){};
		virtual ~ItemPersistencia(){};
		unsigned int obterIdentificador()const{return identificador;};
		unsigned int obterTipoDaClasse()const{return tipoDaClasse;};
		virtual const std::string desmaterializar() = 0;
		virtual void materializar(const std::string s) = 0 ;
};

#endif /*ITEMPERSISTENCIA_H_*/

