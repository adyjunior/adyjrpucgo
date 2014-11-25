/*
 * Triangulo.h
 *
 *  Created on: 21/09/2009
 *      Author: jUniN C.Z.N
 */

#ifndef TRIANGULO_H_
#define TRIANGULO_H_
#include<string>

class Triangulo
{
private :
	float ladoa,ladob,ladoc;
	std::string tipoAngulo,tipoLado;

public :
	Triangulo(float a,float b, float c)
	{
		ladoa=a;
		ladob=b;
		ladoc=c;
	}
	~Triangulo(){};
	void setladoa(float ladoa);
	void setladob(float ladob);
	void setladoc(float ladoc);
	std::string getTipoAngulo();
	std::string getTipoLado();
	float getArea();




};



#endif /* TRIANGULO_H_ */
