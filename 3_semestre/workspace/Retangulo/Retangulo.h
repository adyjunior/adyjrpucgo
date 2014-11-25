/*
 * Retangulo.h
 *
 *  Created on: 18/09/2009
 *      Author: jUniN C.Z.N
 */

#ifndef RETANGULO_H_
#define RETANGULO_H_


class Retangulo
{
private:
	float comprimento, largura;

public :
	Retangulo(){}
	~Retangulo(){};
	static bool Rvalido(float c,float l)
	{
		if((c>0)&&(l>0))
			return true;
		else
			return false;
	}
	void setComprimento(float comprimento);
	void setLargura(float altura);
	float getArea()const;
	float getPerimetro()const;



};

#endif /* RETANGULO_H_ */
