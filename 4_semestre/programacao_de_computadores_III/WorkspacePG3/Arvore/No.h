/*
 * No.h
 *
 *  Created on: 19/09/2010
 *      Author: jolimpiof
 */

#ifndef NO_H_
#define NO_H_

#include <string>

class No {
	private:
		int chave;
		std::string nome;
		No *esq, *dir;
	public:
		No ();
		int getChave();
		bool setChave(int pChave);
		std::string getNome ();
		bool setNome(std::string pNome);
		No *getEsq();
		void setEsq(No *pEsq);
		No *getDir();
		void setDir(No *pDir);
		~No ();
};

#endif /* NO_H_ */
