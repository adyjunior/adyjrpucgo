#include "Matriz.h"

namespace VilaNova {

Matriz::Matriz(int linha, int coluna) {
	// TODO Auto-generated constructor stub
	if(linha<=0 || coluna<=0){
		quantidadeDeLinhas = quantidadeDeColunas = 0;
		matriz=0;
	}else{
		quantidadeDeLinhas = linha;
		quantidadeDeColunas = coluna;
		matriz = new int[linha*coluna];
	}
}



bool Matriz::getElemento(int linha, int coluna, int &elemento)const{
	if(	linha<0 || coluna<0 || linha>=quantidadeDeLinhas ||
		coluna>=quantidadeDeColunas) return false;
	elemento = *(matriz+(linha*quantidadeDeColunas+coluna));
	return true;
}

bool Matriz::setElemento(int linha, int coluna, int elemento){
	if(	linha<0 || coluna<0 || linha>=quantidadeDeLinhas ||
		coluna>=quantidadeDeColunas) return false;
	*(matriz+(linha*quantidadeDeColunas+coluna))=elemento;
	return true;
}


Matriz::Matriz(Matriz *matriz){
	int linha=0,coluna=0;
	if(!matriz){
		this->matriz = 0;
		quantidadeDeLinhas=quantidadeDeColunas=0;
		return;
	}
	quantidadeDeLinhas=linha=matriz->getQuantidadeLinhas();
	quantidadeDeColunas=coluna = matriz->getQuantidadeColunas();
	this->matriz = new int[linha*coluna];
	for(int i=0; i<linha; i++){//inicio do for_linha
		int a;
	   	for(int j=0; j<coluna; j++){//inicio do for_coluna
			matriz->getElemento(i,j,a);
			setElemento(i,j,a);
	   	}//fim do for_coluna
	}//fim do for_linha
	delete matriz;
}

bool Matriz::eResultanteDaAdicao(Matriz const &matA, Matriz const &matB ){
	if(	matA.getQuantidadeLinhas()!= matB.getQuantidadeLinhas() ||
		matA.getQuantidadeColunas() != matB.getQuantidadeColunas()) return false;
	if(matriz) delete[] matriz;
	this->quantidadeDeLinhas = matA.getQuantidadeLinhas();
	this->quantidadeDeColunas = matB.getQuantidadeColunas();
	matriz = new int[quantidadeDeLinhas*quantidadeDeColunas];
	for(int l=0; l<matA.getQuantidadeLinhas(); l++){
		for(int c=0; c<matB.getQuantidadeColunas(); c++){
			int elementoA, elementoB, elementoC;
			matA.getElemento(l,c,elementoA);
			matB.getElemento(l,c,elementoB);
			elementoC = elementoA + elementoB;
			this->setElemento(l,c,elementoC);
		}
	}
	return true;
}

bool Matriz::eResultadoDaSubtracao(Matriz const &matA, Matriz const &matB){

	if(matA.getQuantidadeLinhas() != matB.getQuantidadeLinhas() ||
	   matA.getQuantidadeColunas() != matB.getQuantidadeColunas())
		return false;

	if(matriz) delete[] matriz;
	this->quantidadeDeLinhas = matA.getQuantidadeLinhas();
	this->quantidadeDeColunas = matB.getQuantidadeColunas();
	matriz = new int[quantidadeDeLinhas*quantidadeDeColunas];
	for(int l=0;l< matA.getQuantidadeLinhas();l++)
		for(int c=0;c<matB.getQuantidadeColunas();c++){
			int elementoA,elementoB;
			matA.getElemento(l,c,elementoA);
			matB.getElemento(l,c,elementoB);
			this->setElemento(l,c,elementoA-elementoB);
		}

	return true;
}


bool Matriz::eMatrizTriangularSuperior()const{
    if (quantidadeDeLinhas!=quantidadeDeColunas) return false;
    int linha,coluna=0;
    for (linha=1;linha<quantidadeDeLinhas && linha==coluna+1;linha++)
    	for (coluna=0;coluna<linha && *(matriz+(linha*quantidadeDeColunas+coluna))==0;coluna ++);
    if (linha==quantidadeDeLinhas && coluna+1==quantidadeDeColunas)return true;
    return false;
}

bool Matriz::triangularInferior()const{
    if(quantidadeDeLinhas!=quantidadeDeColunas) return false;
    int linha,coluna=quantidadeDeColunas;
    for(linha=0;linha<quantidadeDeLinhas-1&&coluna==quantidadeDeColunas;linha++)
        for (coluna=linha+1;coluna<quantidadeDeColunas &&*(matriz+(linha*quantidadeDeColunas+coluna))==0;coluna ++);
    if(linha==quantidadeDeLinhas-1&&coluna==quantidadeDeColunas)return true;
    return false;
}



}
