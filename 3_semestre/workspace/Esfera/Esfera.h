/*
 * Esfera.h
 *
 *  Created on: 18/09/2009
 *      Author: jUniN C.Z.N
 */

#ifndef ESFERA_H_
#define ESFERA_H_
#define PI 3.14

class Esfera
{
	private :

		float raio,area,volume;

	public :
		Esfera(){}
		~Esfera(){};
		static bool eValido(float e){
			if (e>0)
				return true;
			else
				return false;
		}
		void setRaio(float r)
		{
			raio=r;
		}
		inline float getArea()const;
		float getVolume()const;



};



float Esfera::getArea()const
{
	return (4*PI*raio*raio);
}

float Esfera::getVolume()const
{
	((4/3)*PI*(3*raio));
}

#endif /* ESFERA_H_ */
