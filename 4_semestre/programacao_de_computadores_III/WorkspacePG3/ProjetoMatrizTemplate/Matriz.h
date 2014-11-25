#ifndef MATRIZ_H_
#define MATRIZ_H_

namespace PG3 {//inicio namespace

template <class type>
class Matriz {
//Atributos
private:
	int quantidadeDeLinhas;
	int quantidadeDeColunas;
	type *matriz;

public:
	Matriz(int nLinhas, int nColunas);//ok
	~Matriz(){if(matriz) delete[] matriz;}//ok
	int getQuantidadeLinhas()const{return quantidadeDeLinhas;}//ok
	int getQuantidadeColunas()const{return quantidadeDeColunas;}//ok
	type getElemento(int linha, int coluna)const;//
	void setElemento(int linha, int coluna, type elemento);//ok
	void operator= (Matriz<type> *matrizP);
	bool operator==(Matriz<type> const &matriz)const;
	bool operator!=(Matriz<type> const &matriz)const;
	Matriz<type> *operator+(Matriz<type> const &matriz)const;//ok
	Matriz<type> *operator-(Matriz<type> const &matriz)const;//ok
	Matriz<type> *operator*(Matriz<type> const &matriz)const;//ok
	bool eMatrizTriangularSuperior()const;//ok
	bool eMatrizTriangularInferior()const;//ok
	bool eMatrizIdentidade()const;//ok
	Matriz<type> *multiplicarPorK(int k)const;//ok - podendo fazer sem retornar ponteiro
	Matriz<type> *matrizTransposta()const;//ok - podendo fazer sem retornar ponteiro
	bool eMatrizSimetrica()const;//ok
	bool eMatrizAntiSimetrica()const;//ok
	bool eMatrizOrtagonal()const;//ok
	bool eMatrizDePermutacao()const;//ok
	Matriz<type> *potenciaMatriz(int exp)const;//ok



};

template < class type>
Matriz<type>::Matriz(int nLinhas, int nColunas) {
	// TODO Auto-generated constructor stub
	if(nLinhas<=0 || nColunas<=0){
		quantidadeDeLinhas = quantidadeDeColunas = 0;
		matriz=0;
		throw (1);
	}
	quantidadeDeLinhas = nLinhas;
	quantidadeDeColunas = nColunas;
	try{
		matriz = new type[nLinhas*nColunas];
	}catch(std::bad_alloc&){
		throw (0);
	}
}


template < class type>
type Matriz<type>::getElemento(int linha, int coluna)const{
	if(	linha<0 || coluna<0 || linha>=quantidadeDeLinhas ||	coluna>=quantidadeDeColunas)
		throw (1);
	return *(matriz+(linha*quantidadeDeColunas+coluna));
}

template < class type>
void Matriz<type>::setElemento(int linha, int coluna, type elemento){
	if(	linha<0 || coluna<0 || linha>=quantidadeDeLinhas ||	coluna>=quantidadeDeColunas)
		throw (1);
	*(matriz+(linha*quantidadeDeColunas+coluna))=elemento;
}

template < class type>
void Matriz<type>::operator= (Matriz<type> *matrizP){
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

template < class type>
bool Matriz<type>::operator ==(Matriz<type> const &matriz)const{
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

template <class type>
bool Matriz<type>::operator !=(Matriz<type> const &matriz)const{
	try{
		return !(*this == matriz);
	}catch(int valorErro){
		throw valorErro;
	}

}

template <class type>
Matriz<type> *Matriz<type>::operator+ (Matriz<type> const &matriz)const{
	Matriz<type> *matAdicao;
	try{
		if(		matriz.getQuantidadeLinhas()!= quantidadeDeLinhas ||
				matriz.getQuantidadeColunas() != quantidadeDeColunas) throw (2);

		matAdicao= new Matriz<type>(quantidadeDeLinhas,quantidadeDeColunas);
		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
				type elemento = this->getElemento(linha,coluna)+matriz.getElemento(linha,coluna);
				matAdicao->setElemento(linha,coluna,elemento);
			}
		return matAdicao;

	}catch(int valorErro){
		//if(matAdicao) delete matAdicao;
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw (0);
	}
}

template <class type>
Matriz<type> *Matriz<type>::operator-(Matriz<type> const &matriz)const{
	Matriz<type> *matSub;
	try{
		if(		matriz.getQuantidadeLinhas()!= quantidadeDeLinhas ||
				matriz.getQuantidadeColunas() != quantidadeDeColunas) throw (2);

		matSub = new Matriz<type>(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++)
				matSub->setElemento(linha,coluna,this->getElemento(linha,coluna) - matriz.getElemento(linha,coluna));


		return matSub;

	}catch(int valorErro){
		//if(matSub) delete matSub;
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw (0);
	}

}

template < class type>
Matriz<type> *Matriz<type>::operator* (Matriz<type> const &matriz)const{
	Matriz<type> *matMulti;
    try{
        if(matriz.getQuantidadeLinhas() != quantidadeDeColunas) throw (2);

        matMulti= new Matriz<type>(quantidadeDeLinhas,matriz.getQuantidadeColunas());//aloca dinamicamente

        for(int linha=0;linha<quantidadeDeLinhas;linha++)//limite e linhas da matriz A
            for(int coluna=0;coluna<matriz.getQuantidadeColunas();coluna++){//limite e colunas da matriz B
                type elemento = 0;
                    for (int x=0;x<quantidadeDeColunas;x++)
                    elemento = elemento + this->getElemento(linha,x)*matriz.getElemento(x,coluna);//soma a multiplicacao de A(i,x) com B(x,j)
                    matMulti->setElemento(linha,coluna,elemento);//seta o elemento na matriz C

             }

        return matMulti;

    }catch(int valorErro){
		//if(matMulti) delete matMulti;
        throw valorErro;
    }
    catch(std::bad_alloc&){
            throw (0);
        }
}

template <class type>
bool Matriz<type>::eMatrizTriangularSuperior()const{
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

template <class type>
bool Matriz<type>::eMatrizTriangularInferior()const{
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

template <class type>
bool Matriz<type>::eMatrizIdentidade()const{
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

template <class type>
Matriz<type> *Matriz<type>::multiplicarPorK(int k)const{
	Matriz<type> *mat;
	try{
		mat = new Matriz<type>(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++)
				mat->setElemento(linha,coluna,this->getElemento(linha,coluna)*k);


		return mat;

	}catch(int valorErro){
		//if(mat) delete mat;
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw(0);
	}


}

template <class type>
Matriz<type> *Matriz<type>::matrizTransposta()const{
	Matriz<type> *mat;
	try{

		mat = new Matriz<type>(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++)
				mat->setElemento(coluna,linha,this->getElemento(linha,coluna));
				// inverte linha,coluna POR coluna,linha;

		return mat;

	}catch(int valorErro){
		//if(mat) delete mat;
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw(0);
	}
}

template <class type>
bool Matriz<type>::eMatrizSimetrica()const{
	Matriz<type> *mat;
	try{

		mat = new Matriz<type>(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		mat = this->matrizTransposta();//temporaria recebe transposta

		bool ret = (*this == *mat);//compara original com transposta
		delete mat;

		return ret;

	}catch(int valorErro){
		if(mat) delete mat;
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw(0);
	}

}

template <class type>
bool Matriz<type>::eMatrizAntiSimetrica()const{
	Matriz<type> *matTrans;
	Matriz<type> *matOposta;
	try{

		matTrans = new Matriz<type>(this->quantidadeDeLinhas,this->quantidadeDeColunas);
		matOposta = new Matriz<type>(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		matTrans = this->matrizTransposta();

		for(int linha=0;linha<quantidadeDeLinhas;linha++)
			for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
				type inverso = this->getElemento(linha,coluna)*-1;
				matOposta->setElemento(linha,coluna,inverso);//calcula oposta
			}

		bool ret= *matTrans == *matOposta;//compara transposta com oposta
		delete matTrans;
		delete matOposta;

		return ret;

	}catch(int valorErro){
		//if(matTrans) delete matTrans;		if(matOposta) delete matOposta;
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw(0);
	}
}

template <class type>
bool Matriz<type>::eMatrizDePermutacao()const{
	try{
		type aux=0;
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

template <class type>
bool Matriz<type>::eMatrizOrtagonal()const{
	Matriz<type> *matTrans;
	Matriz<type> *matResult;
	try{
		if(this->quantidadeDeLinhas != this->quantidadeDeColunas) throw (5);//verifica se e quadrada.

		matTrans = new Matriz<type>(this->quantidadeDeLinhas,this->quantidadeDeColunas);
		matResult = new Matriz<type>(this->quantidadeDeLinhas,this->quantidadeDeColunas);

		matTrans = this->matrizTransposta();//matriz transposta temporaria recebendo valores

		*matResult = (*matTrans) * (*this);//matriz resultado da multiplicacao da transposta com original

		delete matTrans;

		bool ret = matResult->eMatrizIdentidade();//verifica se resultado e igual identidade
		delete matResult;
		return ret;


	}catch(int valorErro){
		//if(matTrans) delete matTrans;		if(matResult) delete matResult;
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw (0);
	}
}

template <class type>
Matriz<type> *Matriz<type>::potenciaMatriz(int exp)const{
	Matriz<type> *mat;
	try{
		if(exp < 0) throw(6);
		mat = new Matriz<type>(this->quantidadeDeLinhas,this->quantidadeDeColunas);


		for(int linha=0;linha<quantidadeDeLinhas;linha++)
		for(int coluna=0;coluna<quantidadeDeColunas;coluna++)
		{mat->setElemento(linha,coluna,this->getElemento(linha,coluna));} // copia MAT = THIS;


		if(exp == 0){//expoente igual a zero todos valores sao iguais a 1
			for(int linha=0;linha<quantidadeDeLinhas;linha++)
				for(int coluna=0;coluna<quantidadeDeColunas;coluna++){
					type elemento = 1;
					mat->setElemento(linha,coluna,elemento);
				}
		}
		else{
			for(int cont=1;cont < exp;cont++)//limite e o expoente
				*(mat) = (*(mat)) * (*(this));

		}

		return mat;

	}catch(int valorErro){
		//if(mat) delete mat;
		throw valorErro;
	}
	catch(std::bad_alloc&){
		throw(0);
	}
}





}//fim namespace

#endif /* MATRIZ_H_ */
