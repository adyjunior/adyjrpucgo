

#include"Data.h"

using namespace std;
int Data::getCalculoSemana()const
{
	if(ano>=1582)
		{
			int aa=ano;
			int f = aa+dia+3*(mes-1) -1;
			if(mes<3){aa--;}
			else{ f-= int(0.4*mes+2.3);
			f+=(int(ano/4) - int((aa/100+1)*0.75));
			f%=7;};
			return f;
		}
		else
			{
			int aa = (14-mes)/12;
			int yy = ano-aa;
			int mm = mes+(12*aa)-2;
			int qq = (dia+(31*mm/12)+yy+(yy/4)+5);
			int dd = qq%7;
			return dd;
			}
}

string Data::diaDaSemana()
{
	if(getCalculoSemana()==1)

		return "Segunda-feira";
	else{
		if(getCalculoSemana()==2)
			return "Terca-feira";
		else{
			if(getCalculoSemana()==3)
				return "Quarta-feira";
			else{
				if(getCalculoSemana()==4)
					return "Quinta-feira";
				else{
					if(getCalculoSemana()==5)
						return "Sexta-feira";
					else{
						if(getCalculoSemana()==6)
							return "Sabado";

						else return "Domingo";

						}
					}
				}
			}
		}

}

string Data::getMesExtenso()
{
	if(getMes()==1)
		return "janeiro";
	else{
		if(getMes()==2)
			return "fevereiro";
		else{
			if(getMes()==3)
				return "março";
			else{
				if(getMes()==4)
					return "abril";
				else{
					if(getMes()==5)
						return "maio";
					else{
						if(getMes()==6)
							return "junho";
						else{
							if(getMes()==7)
								return "julho";
							else{
								if(getMes()==8)
									return "agosto";
								else{
									if(getMes()==9)
										return "setembro";
									else{
										if(getMes()==10)
											return "outubro";
										else{
											if(getMes()==11)
												return "novembro";
											else{
												if(getMes()==12)
													return "dezembro";

												else return "\n";
												}
											}
										}
									}

								}

							}

						}
					}
				}
			}
		}


}







string Data::getDDMMAAAA()
{
	std::stringstream d, m, a;
	d << dia;
	m << mes;
	a << ano;

	return  d.str() + "/" + m.str() + "/" + a.str();
}
string Data::getMMDDAAAA()
{
	std::stringstream d,m,a;

	d<<dia;
	m<<mes;
	a<<ano;

	return m.str() + "/" + d.str() + "/" + a.str();
}
string Data::getDDMMAA()
{

	std::stringstream d, m, a;
	d<<dia;
	m<<mes;
	a<<ano;
	return d.str() + "/" + m.str() + "/" + a.str().substr(2,2);
}
string Data::getMMDDAA()
{
	std::stringstream d, m, a;
	d<<dia;
	m<<mes;
	a<<ano;
	return m.str() + "/" + d.str() + "/" + a.str().substr(2,2);
}
string Data::getDDmesAAAA()
{
	std::stringstream d, m, a;
	d<<dia;
	a<<ano;
	return d.str() + " de " + getMesExtenso() + " de " + a.str();
}
string Data::getDiasemanaDDmesAAAA()
{
	return  diaDaSemana() + "," + getDDmesAAAA();
}
string Data::getDiasemanaDDMMAAA()
{
	return 	diaDaSemana() + "," + getDDMMAAAA();
}



























