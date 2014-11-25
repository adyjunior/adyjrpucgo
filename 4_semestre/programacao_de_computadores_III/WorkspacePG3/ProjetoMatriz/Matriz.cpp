#include "Matriz.h"
#include<exception>
#include<iostream>

namespace PC3 {

Matriz::Matriz(int nLinhas, int nColunas) {

	if(nLinhas<=0 || nColunas<=0){//verifica se e menor ou igual a zero
		quantidadeDeLinhas = quantidadeDeColunas = 0;
		matriz=0;
		throw(1);//termina o metodo//estarta um exeção//valores incondisentes
	}

	quantidadeDeLinhas = nLinhas;
	quantidadeDeColunas = nColunas;
	try{
		matriz = new int[nLinhas*nColunas];

	}catch(std::bad_alloc&){//estudar bad alloc//sem espaço de memoria
		throw (0);//grito de erro
	}
	catch(int valorErro){
		throw valorErro;
	}
}


Matriz::~Matriz() {
	if(matriz) delete[] matriz;// delete[] porque e vetor
	//nao se tem tratamento de exeção no destrutor
}

int Matriz::getElemento(int linha, int coluna)const{
	if(	linha<0 || coluna<0 || linha>=quantidadeDeLinhas ||	coluna>=quantidadeDeColunas)
		throw (1);
	return *(matriz+(linha*quantidadeDeColunas+coluna));
}

void Matriz::setElemento(int linha, int coluna, int elemento){
	if(	linha<0 || coluna<0 || linha>=quantidadeDeLinhas ||	coluna>=quantidadeDeColunas)
		throw (1);
	*(matriz+(linha*quantidadeDeColunas+coluna))=elemento;
}


void Matriz::operator= (Matriz *matrizP){
	try{
		if(matrizP==0)throw (3);
		if(matriz)delete[] matriz;
		quantidadeDeLinhas=matrizP->getQuantidadeLinhas();//copia quantidade de linhas
		quantidadeDeColunas=matrizP->getQuantidadeColunas();//copia quantidade de colunas
		matriz = matrizP->matriz;//aponta para a endereco temporaria
		matrizP->matriz = 0;//temporaria apontando para lugar algum
		delete matrizP;//deleta temporaria

	}catch(int valorErro){
		throw valorErro;
	}
}

bool Matriz::operator ==(Matriz const &matriz)const{
	try{
		if(		matriz.getQuantidadeLinhas()!= quantidadeDeLinhas ||
			matriz.getQuantidadeColunas() != quantidadeDeColunas) return false;//verifica se possuem mesma quant linhas e colunas

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++){

				if(this->getElemento(linha,coluna) != matriz.getElemento(linha,coluna))//compara elementos
					return false;
			}
		return true;

	}catch(int valorErro){
		throw valorErro;
	}

}

bool Matriz::operator !=(Matriz const &matriz)const{
	try{
		return !(*this == matriz);
	}catch(int valorErro){
		throw valorErro;
	}

}


Matriz *Matriz::operator+ (Matriz const &matriz)const{
	try{
		if(		matriz.getQuantidadeLinhas()!= quantidadeDeLinhas ||
				matriz.getQuantidadeColunas() != quantidadeDeColunas) throw (2);

		Matriz *matAdicao= new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
				int elemento = this->getElemento(linha,coluna)+matriz.getElemento(linha,coluna);
				matAdicao->setElemento(linha,coluna,elemento);
			}
		return matAdicao;

	}catch(int valorErro){
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw (0);
	}
}

Matriz *Matriz::operator-(Matriz const &matriz)const{
	try{
		if(		matriz.getQuantidadeLinhas()!= quantidadeDeLinhas ||
				matriz.getQuantidadeColunas() != quantidadeDeColunas) throw (2);

		Matriz *matSub = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++)
				matSub->setElemento(linha,coluna,this->getElemento(linha,coluna) - matriz.getElemento(linha,coluna));


		return matSub;

	}catch(int valorErro){
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw (0);
	}

}

Matriz *Matriz::operator* (Matriz const &matriz)const{
    try{
        if(matriz.getQuantidadeLinhas() != quantidadeDeColunas) throw (2);

        Matriz *matMulti= new Matriz(quantidadeDeLinhas,matriz.getQuantidadeColunas());//aloca dinamicamente

        for(int linha=0;linha<quantidadeDeLinhas;linha++)//limite e linhas da matriz A
            for(int coluna=0;coluna<matriz.getQuantidadeColunas();coluna++){//limite e colunas da matriz B
                int elemento = 0;
                    for (int x=0;x<quantidadeDeColunas;x++)
                    elemento = elemento + this->getElemento(linha,x)*matriz.getElemento(x,coluna);//soma a multiplicacao de A(i,x) com B(x,j)
                    matMulti->setElemento(linha,coluna,elemento);//seta o elemento na matriz C

             }

        return matMulti;

    }catch(int valorErro){
        throw valorErro;
    }
    catch(std::bad_alloc&){
            throw (0);
        }
}

bool Matriz::eMatrizTriangularSuperior()const{
	try{
		if(this->quantidadeDeLinhas != this->quantidadeDeColunas) throw(5);

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
				if( linha > coluna)
					if(this->getElemento(linha,coluna) != 0)//verifica se os elementos acima da diagonal e igual a zero
						return false;
			}
		return true;

	}catch(int valorErro){
		throw valorErro;
	}
}

bool Matriz::eMatrizTriangularInferior()const{
	try{
		if(this->quantidadeDeLinhas != this->quantidadeDeColunas) throw(5);

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
				if( linha < coluna)
					if(this->getElemento(linha,coluna) != 0)//verifica se os elementos abaixo da diagonal e igual a zero
						return false;
			}
		return true;

	}catch(int valorErro){
		throw valorErro;
	}
}

bool Matriz::eMatrizIdentidade()const{
	try{
		if(this->quantidadeDeLinhas != this->quantidadeDeColunas) throw(5);

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++){ //  |10000|
				if(linha == coluna){							//     |01000|
					if(this->getElemento(linha,coluna) != 1)	//     |00100|
						return false;							//     |00010|
				}												//     |00001|
				else{
					if(this->getElemento(linha,coluna) != 0)
						return false;
				}
			}

		return true;

	}catch(int valorErro){
		throw valorErro;
	}
}

Matriz *Matriz::multiplicarPorK(int k)const{
	try{
		Matriz *mat = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++)
				mat->setElemento(linha,coluna,this->getElemento(linha,coluna)*k);


		return mat;

	}catch(int valorErro){
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw(0);
	}


}

Matriz *Matriz::matrizTransposta()const{
	try{

		Matriz *mat = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++)
				mat->setElemento(coluna,linha,this->getElemento(linha,coluna));
				// inverte linha,coluna POR coluna,linha;

		return mat;

	}catch(int valorErro){
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw(0);
	}
}


bool Matriz::eMatrizSimetrica()const{
	try{

		Matriz *mat = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		mat = this->matrizTransposta();//temporaria recebe transposta

		bool ret = (*this == *mat);//compara original com transposta
		delete mat;

		return ret;

	}catch(int valorErro){
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw(0);
	}

}

bool Matriz::eMatrizAntiSimetrica()const{
	try{

		Matriz *matTrans = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);
		Matriz *matOposta = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		matTrans = this->matrizTransposta();

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
				int inverso = this->getElemento(linha,coluna)*-1;
				matOposta->setElemento(linha,coluna,inverso);//calcula oposta
			}

		bool ret= *matTrans == *matOposta;//compara transposta com oposta
		delete matTrans;
		delete matOposta;

		return ret;

	}catch(int valorErro){
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw(0);
	}
}

bool Matriz::eMatrizDePermutacao()const{
	try{
		int aux=0;
		for(int linha=0;linha<quantidadeDeLinhas;linha++){
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
				if( this->getElemento(linha,coluna) != 0 && this->getElemento(linha,coluna) !=1 )//verifica se ha apenas 1 e 0
					return false;
				else
					aux=getElemento(linha,coluna)+aux;//soma das linhas
			}
			if(aux!=1)return false;//verifica se a soma e 1
			aux=0;
		}

		for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
				for(int linha=0;linha<quantidadeDeLinhas;linha++){
					aux=getElemento(linha,coluna)+aux;//somas das colunas
					}
				if(aux!=1)return false;//verifica se a soma e 1
				aux=0;
		}


		return true;

	}catch(int valorErro){
		throw valorErro;
	}
}

bool Matriz::eMatrizOrtagonal()const{
	try{
		if(this->quantidadeDeLinhas != this->quantidadeDeColunas) throw (5);//verifica se e quadrada.

		Matriz *matTrans = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);
		Matriz *matResult = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		matTrans = this->matrizTransposta();//matriz transposta temporaria recebendo valores

		*matResult = (*matTrans) * (*this);//matriz resultado da multiplicacao da transposta com original

		delete matTrans;

		bool ret = matResult->eMatrizIdentidade();//verifica se resultado e igual identidade
		delete matResult;
		return ret;


	}catch(int valorErro){
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw (0);
	}
}

Matriz *Matriz::potenciaMatriz(int exp)const{
	try{
		if(exp < 0) throw(6);
		Matriz *mat = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);


		for(int linha=0;linha<quantidadeDeLinhas;linha++)
		for(int coluna=0;coluna<quantidadeDeColunas;coluna++)
		{mat->setElemento(linha,coluna,this->getElemento(linha,coluna));} // copia MAT = THIS;


		if(exp == 0){//expoente igual a zero todos valores sao iguais a 1
			for(int linha=0;linha<quantidadeDeLinhas;linha++)
				for(int coluna=0;coluna<quantidadeDeColunas;coluna++)
					mat->setElemento(linha,coluna,1);
		}
		else{
			for(int cont=1;cont < exp;cont++)//limite e o expoente
				*(mat) = (*(mat)) * (*(this));

		}

		return mat;

	}catch(int valorErro){
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw(0);
	}
}


}
