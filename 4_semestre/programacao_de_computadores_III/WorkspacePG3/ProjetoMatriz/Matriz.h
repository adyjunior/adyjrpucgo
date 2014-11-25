#ifndef MATRIZ_H_
#define MATRIZ_H_




namespace PC3 {

class Matriz {
//Atributos
private:
		int quantidadeDeLinhas;
		int quantidadeDeColunas;
		int *matriz;
//Metodos
public:
		Matriz(int nLinhas, int nColunas);
		~Matriz();
		int getQuantidadeLinhas()const{return quantidadeDeLinhas;}
		int getQuantidadeColunas()const{return quantidadeDeColunas;}
		int getElemento(int linha, int coluna)const;
		void setElemento(int linha, int coluna, int elemento);
		void operator= (Matriz *matrizP);
		bool operator==(Matriz const &matriz)const;
		bool operator!=(Matriz const &matriz)const;
		Matriz *operator+(Matriz const &matriz)const;//ok
		Matriz *operator-(Matriz const &matriz)const;//ok
		Matriz *operator*(Matriz const &matriz)const;//ok
		bool eMatrizTriangularSuperior()const;//ok
		bool eMatrizTriangularInferior()const;//ok
		bool eMatrizIdentidade()const;//ok
		Matriz *multiplicarPorK(int k)const;//ok - podendo fazer sem retornar ponteiro
		Matriz *matrizTransposta()const;//ok - podendo fazer sem retornar ponteiro
		bool eMatrizSimetrica()const;//ok
		bool eMatrizAntiSimetrica()const;//ok
		bool eMatrizOrtagonal()const;//ok
		bool eMatrizDePermutacao()const;//ok
		Matriz *potenciaMatriz(int exp)const;//ok

};

}

#endif /* MATRIZ_H_ */
