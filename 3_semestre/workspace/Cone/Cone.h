/*
 * Cone.h
 *
 *  Created on: 18/09/2009
 *      Author: jUniN C.Z.N
 */

#ifndef CONE_H_
#define CONE_H_

class Cone
{
private :
	float raio,altura,geratriz;
public :
	Cone(){}
	~Cone(){};
	static bool cValido(float r, float al)
	{
		if((r>0)&&(al>0))
			return true;
		else
			return false;
	}
	void setRaio(float raio);
	void setAltura(float altura);
	void setGeratriz(float geratriz);
	float getGeratriz();
	float getAreaLateral();
	float getArea();
	float getVolume();

};



#endif /* CONE_H_ */
