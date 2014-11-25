#ifndef MATRIZ_H_
#define MATRIZ_H_

namespace VilaNova {

class Matriz {
//Atributos
private:
	int quantidadeDeLinhas;
	int quantidadeDeColunas;
	int *matriz;
//Metodos
public:
	Matriz(int linha, int coluna);
	Matriz(Matriz * matriz);
	~Matriz(){if(matriz) delete[] matriz;}
	int getQuantidadeLinhas()const{return quantidadeDeLinhas;}
	int getQuantidadeColunas()const{return quantidadeDeColunas;}
	bool getElemento(int linha, int coluna, int &elemento)const;
	bool setElemento(int linha, int coluna, int elemento);
	bool eResultanteDaAdicao(Matriz const &matA, Matriz const &matB );
	bool eResultadoDaSubtracao(Matriz const &matA, Matriz const &matB);
	bool eMatrizTriangularSuperior(Matriz const &mat);

};


}

#endif /* MATRIZ_H_ */
