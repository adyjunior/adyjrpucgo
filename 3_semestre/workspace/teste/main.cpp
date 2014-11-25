#include<iostream>

using namespace std;

/*int main()
{

	int d,m,a;
	bool x,y,z;



	cout<<"Digite o Dia\n";
	cin>>d;

	cout<<"Digite o Mes\n";
	cin>>m;

	cout<<"Digite o Ano\n";
	cin>>a;

	if(a<0)
		x=false;
	else{
		if( ((d>0)&&(d<32)) && ((m>0)&&(m<13)) )
			x=true;
		}




		if(m==2)
		{
				if(( ((a%4)==0) && ( ((a%100)!=0) || ((a%400)==0) ) ))
				{
				if(d<29)
					y=true;
				else
					y=false;
				}


				else{
					if(d<30)
						y=true;
					else
						y=false;
					}
		}
		else{
			y=true;
		}




		if(((m==4)&&(d<31))||((m==6)&&(d<31))||((m==9)&&(d<31))||((m==11)&&(d<31)))
			z=true;
		else
			z=false;



cout<<"\n"<<x;
cout<<"\n"<<y;
cout<<"\n"<<z;

}*/
#include<cstdlib>
#include<string>
#include<sstream>/*
int main()
{
	char Data[10],Data2[10],finalizar;


	int I,J=0,Numero,Data_final,Dia,Mes,Ano;


do{

	//stringstream ss(Data);



	cout<<"Digite a Data\n";
	cin>>Data;

	Numero=strlen(Data);


	for(I=0;I<Numero;I++)
	{
		if(Data[I]!='/')
		{
			Data2[J]=Data[I];
			J++;
		}

	}
	Data2[J] = '\0';
	//for(I=0;I<=Numero;I++)

		//cout<<Data[I]<<endl;




	//ss>>Datac;
	//cout<<"/n"<<Numero<<endl;

	Data_final= atoi(Data2);
	cout<<Data<<endl;
	cout<<Data2<<endl;
	cout<<Data_final<<endl;




	Dia=Data_final/1000000;
	if(Dia==0)
		Dia=Data_final/100000;

	cout<<"\n"<<Dia;





			Mes=Data_final/10000;
			Mes=Mes%1000;

			if(Mes>99)
				Mes=Mes%100;
			if((Data_final/1000000)==0)
				Mes=Mes%10;





	cout<<"\n"<<Mes;

	Ano=Data_final%10000;

	cout<<"\n"<<Ano;


	cout<<"Deseja voltar?\n";
	cin>>finalizar;



}
	while((finalizar=='S')||(finalizar=='s'));
}
*/
/*

int main()
{
	string Data,d,e;

	cout<<"Digite a data\n";
	cin>>Data;

	cout<<"\n\n"<<Data.size();
	cout<<"\n\n"<<Data.capacity();



	cout<<"\n\n"<<Data;

	//Data.assign(1,Data[1]);



	cout<<"\n\n"<<nome;






}














*/




/*

int main()
{
	int a,a2,X[10],c[10],J,I,d[10],e=0,final;
	double b;




	cout<<"Digite A\n";
	cin>>b;


	a=b/100;
	a2=b/10;

	cout<<a<<endl<<a2<<endl;
	X[0]=a/100000000;

	X[1]=a/10000000;
	X[1]=X[1]%10;

	X[2]=a/1000000;
	X[2]=X[2]%100;
	X[2]=X[2]%10;

	X[3]=a/100000;
	X[3]=X[3]%1000;
	X[3]=X[3]%100;
	X[3]=X[3]%10;

	X[4]=a/10000;
	X[4]=X[4]%10000;
	X[4]=X[4]%1000;
	X[4]=X[4]%100;
	X[4]=X[4]%10;

	X[5]=a/1000;
	X[5]=X[5]%100000;
	X[5]=X[5]%10000;
	X[5]=X[5]%1000;
	X[5]=X[5]%100;
	X[5]=X[5]%10;

	X[6]=a/100;
	X[6]=X[6]%1000000;
	X[6]=X[6]%100000;
	X[6]=X[6]%10000;
	X[6]=X[6]%1000;
	X[6]=X[6]%100;
	X[6]=X[6]%10;

	X[7]=a/10;
	X[7]=X[7]%10000000;
	X[7]=X[7]%1000000;
	X[7]=X[7]%100000;
	X[7]=X[7]%10000;
	X[7]=X[7]%1000;
	X[7]=X[7]%100;
	X[7]=X[7]%10;

	X[8]=a%100000000;
	X[8]=X[8]%10000000;
	X[8]=X[8]%1000000;
	X[8]=X[8]%100000;
	X[8]=X[8]%10000;
	X[8]=X[8]%1000;
	X[8]=X[8]%100;
	X[8]=X[8]%10;

	X[9]=a%1000000000;
	X[9]=X[9]%100000000;
	X[9]=X[9]%10000000;
	X[9]=X[9]%1000000;
	X[9]=X[9]%100000;
	X[9]=X[9]%10000;
	X[9]=X[9]%1000;
	X[9]=X[9]%100;
	X[9]=X[9]%10;

	J=12;
	for(I=0;I<10;I++)
	{
		J--;
		c[I]=J;

		cout<<"\t"<<J;
	}
	cout<<"\n\n";

	for(I=0;I<10;I++)
		cout<<"\t"<<X[I];


	cout<<"\n\n";

	for(I=0;I<10;I++)
	{	J=0;

		d[I]=c[J]*X[I];
		cout<<"\t"<<d[I];

	}

	cout<<"\n\n";

	for(I=0;I<9;I++)
	{
		e=e+d[I];
		cout<<"\t"<<e;
	}


	final=e%11;

	cout<<"\n\n"<<final;

}

*/


/*

int main()
{
	int a,b,c,aux;

	cout<<"Digite o primeiro numero\n";
	cin>>a;

	cout<<"Digite o segundo numero\n";
	cin>>b;

	cout<<"Digite o terceiro numero\n";
	cin>>c;


	if((a<b)||(a<c))
	{
		if(b>c)
		{
			aux=a;
			a=b;
			b=aux;
		}
		else{
			aux=a;
			a=c;
			c=aux;
		}
	}

	if(b<c)
	{
		aux=b;
		b=c;
		c=aux;
	}


	cout<<"O maior eh "<<a<<" e o menor eh "<<c<<endl;

}
*/



/*
#include<stdio.h>
#include<conio.h>
int main()
{
int n,m, fatorial;

  cout<<"digite o numero que vc quer calcular: ";
  cin>>n;

  fatorial = 1;
  m=n;
  while(n > 0) {
    fatorial = fatorial *  n;
    n--;
  }
cout<<m<<"! = "<<fatorial<<endl;

}
*/


/*
int main()
{
	char c[11];
	int I,c2[11], J=11, c3[11],c4[11],c5[11],numero,cf1=0,cf2=0,cf3,cf4,cpf1[11],cpf2[11];

			cout<<"Digite c\n";
			cin>>c;

			numero=strlen(c);

			for(I=0;I<=numero;I++)
			{
				c2[I]=atoi(c[I]);
				cpf1[I]=c2[I];

				cout<<"\n"<<c2<<"\n\n"<<cpf1;
			}

			cout<<"\n\n"<<c2<<"\n\n"<<cpf1<<"\n\n";

			for(I=0;I<10;I++)
			{
				c3[I]=J;
				cpf2[I]=c3[I];
					J--;
			}

			J=1;
			for(I=0;I<9;I++)
			{
				c4[I]=c2[I]*c3[J];

				cf1=cf1+c4[I];
				J++;
			}

			for(I=0;I<10;I++)
			{
				c5[I]=c2[I]*c3[I];

				cf2=cf2+c5[I];
			}




			cf3=cf1%11;

			cf4=cf2%11;




			if(cf3<2)
				cpf1[9]=0;
			else
				cpf1[9]=11-c2[9];

			if(cf4<2)
				cpf2[10]=0;
			else
				cpf2[10]=11-c3[10];





			if((cpf1[9]==c2[9])&&(cpf2[10]==c3[10]))
				return true;
			else
				return false;
}
*/

/*int main ()
{
	string b;
	stringstream x;
	int i,j=0,cont,numero,a[10];

	cin>>numero;

	x << numero;//transformação de string para int ;

	cont=x.str().size();
	//cout<<cont<<endl;

	b=x.str();



	//cout<<b;
	for(i=cont;i!=0;i--)
	{

		a[j]=atoi(b.substr(i,1).c_str());
		cout<<a[j];
		j++;
	}

	//cout<<numero<<"\t\t"<<a;
*/

/*
	int a[10],b[10],j=0,num,tam,i,cont=0;

	string c;
	stringstream x;

	cin>>num;

	x << num;

	c=x.str();

	tam=c.size();
	for(i=0;i<tam;i++)
	a[i]=atoi(c.substr(i,1).c_str());

	for(i=tam-1;j<=tam-1;i--)
		{
		b[j]=a[i];

		if(b[j]==a[j])
			cont++;

		j++;
		}

		if(cont==tam)
			return true;
		else
			return false;









}
*/


int main()
{

	string vlr="0123456789ABCDEF";
	string resp="";
	int numero;

	int p,base;

	cout<<"digite base"<<vlr[4]<<endl;
	cin>>base;

	cout<<"digite numero"<<endl;
	cin>>numero;
	int aux=numero;



	while(aux){
		p=aux%base;
		resp=vlr[p] + resp;
		aux=aux/base;
	}
	cout<<resp;
}


