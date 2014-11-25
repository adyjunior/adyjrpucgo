/*
 * Cilindro.h
 *
 *  Created on: 20/09/2009
 *      Author: jUniN C.Z.N
 */

#ifndef CILINDRO_H_
#define CILINDRO_H_


class Cilindro
{
private :
	float raio,altura;
public :

	Cilindro(){}
	~Cilindro(){};
	static bool cValido(float r, float al)
	{
		if ((r>0)&&(al>0))
			return true;
		else
			return false;
	}
	void setRaio(float raio);
	void setAltura(float altura);
	float getAreaLateral()const;
	float getArea()const;
	float getVolume()const;

};


#endif /* CILINDRO_H_ */
