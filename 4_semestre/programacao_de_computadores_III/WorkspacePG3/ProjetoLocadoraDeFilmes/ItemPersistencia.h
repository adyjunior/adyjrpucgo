#ifndef ITEMPERSISTENCIA_H_
#define ITEMPERSISTENCIA_H_
#include<string>

//Situacao: Testada
// Classe abstrata ItemPersistencia
// Classe testada em C++ e modela no Jude
class ItemPersistencia
{
	//Atributos
	protected:
		int identificador;
		const int tipoDaClasse;
	//Metodos
	public:
		ItemPersistencia(const int identificador, const int tipoDaClasse):
								identificador(identificador),tipoDaClasse(tipoDaClasse){};
		virtual ~ItemPersistencia(){};
		int obterIdentificador()const {return identificador;}
		int obterTipoDaClasse()const {return tipoDaClasse;}
		virtual void materializar(const std::string cdc)=0;
		virtual std::string desmaterializar()const=0;
};

#endif /*ITEMPERSISTENCIA_H_*/
