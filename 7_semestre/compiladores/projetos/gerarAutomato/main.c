#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void geraAutomato();

int main(){
	geraAutomato();
return 0;
}

void geraAutomato(){


	char vetEstados[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_";
	char vetAfabeto[50] = "ld.\"c<bpx!>eouna=-";
	char vetEstadosFinais[50] = "BCFGIJKPQRSTUVYZ_";
	char estadoInicial = 'A';
	char matrizTransicao[50][50];
	char cadeia[50] = "10000";

	int qtdEstados = 26;
	int qtdAlfabeto = 18;
	int qtdEstadosFinais = 17;

	int i,j;
	for (i = 0; i < 50; ++i) {
		for (j = 0; j < 50; ++j) {
			matrizTransicao[i][j] = '*';
		}
	}

	matrizTransicao[0][0] = 'B';// l
	matrizTransicao[0][1] = 'C';// d
	matrizTransicao[0][2] = 'D';// .
	matrizTransicao[0][3] = 'E';// "
	//matrizTransicao[0][4] = '*';// c
	matrizTransicao[0][5] = 'F';// <
	matrizTransicao[0][6] = 'K';// b
	matrizTransicao[0][7] = 'J';// p
	matrizTransicao[0][8] = 'I';// x
	matrizTransicao[0][9] = 'H';// !
	matrizTransicao[0][10] = 'G';// >
	//matrizTransicao[0][11] = '*';// e
	//matrizTransicao[0][12] = '*';// o
	//matrizTransicao[0][13] = '*';// u
	//matrizTransicao[0][14] = '*';// n
	//matrizTransicao[0][15] = '*';// a
	//matrizTransicao[0][16] = '*';// =
	//matrizTransicao[0][17] = '*';// -

	matrizTransicao[1][0] = 'B';// l
	matrizTransicao[1][1] = 'B';// d
	//matrizTransicao[1][2] = '*';// .
	//matrizTransicao[1][3] = '*';// "
	//matrizTransicao[1][4] = '*';// c
	//matrizTransicao[1][5] = '*';// <
	//matrizTransicao[1][6] = '*';// b
	//matrizTransicao[1][7] = '*';// p
	//matrizTransicao[1][8] = '*';// x
	//matrizTransicao[1][9] = '*';// !
	///matrizTransicao[1][10] = '*';// >
	//matrizTransicao[1][11] = '*';// e
	//matrizTransicao[1][12] = '*';// o
	//matrizTransicao[1][13] = '*';// u
	//matrizTransicao[1][14] = '*';// n
	//matrizTransicao[1][15] = '*';// a
	//matrizTransicao[1][16] = '*';// =
	//matrizTransicao[1][17] = '*';// -

	//matrizTransicao[2][0] = '*';// l
	matrizTransicao[2][1] = 'C';// d
	matrizTransicao[2][2] = 'L';// .
	//matrizTransicao[2][3] = '*';// "
	//matrizTransicao[2][4] = '*';// c
	//matrizTransicao[2][5] = '*';// <
	//matrizTransicao[2][6] = '*';// b
	//matrizTransicao[2][7] = '*';// p
	//matrizTransicao[2][8] = '*';// x
	//matrizTransicao[2][9] = '*';// !
	//matrizTransicao[2][10] = '*';// >
	//matrizTransicao[2][11] = '*';// e
	//matrizTransicao[2][12] = '*';// o
	//matrizTransicao[2][13] = '*';// u
	//matrizTransicao[2][14] = '*';// n
	//matrizTransicao[2][15] = '*';// a
	//matrizTransicao[2][16] = '*';// =
	//matrizTransicao[2][17] = '*';// -

	matrizTransicao[3][11] = 'M';// e
	matrizTransicao[3][12] = 'N';// o
	matrizTransicao[3][14] = 'O';// n

	matrizTransicao[4][3] = 'P';// "
	matrizTransicao[4][4] = 'E';// c

	matrizTransicao[5][16] = 'Q';// =
	matrizTransicao[5][17] = 'R';// -

	matrizTransicao[6][16] = 'S';// =

	matrizTransicao[7][16] = 'T';// =

	matrizTransicao[11][1] = 'U';// d

	matrizTransicao[12][2] = 'V';// .

	matrizTransicao[13][13] = 'X';// u

	matrizTransicao[14][15] = 'W';// a

	matrizTransicao[15][3] = 'E';// "

	matrizTransicao[20][1] = 'U';// d

	matrizTransicao[22][12] = 'Z';// o

	matrizTransicao[23][2] = 'Y';// .

	matrizTransicao[25][2] = '_';// .

	i=0;
	j=0;
	int cont = 0;

	for(i = 0;cadeia[i] != '\0';i++,cont++);


	//printf("%i",cont);


	FILE *arq = fopen("fonte.c","wt");

	if (arq==NULL) return;

	fprintf(arq,"#include<stdio.h> \n\n");

	fprintf(arq,"int AFD(char *c,int tam,char *vetFinais,int qtdEstadosFinais,char *vetEstados,int qtdEstados);\n");
	fprintf(arq,"int buscarVet(char c,char *vetor,int tam);\n\n");

	fprintf(arq,"int main(){ \n\n");

	fprintf(arq,"	char vetEstados[50] = \"%s\";\n",vetEstados);
	fprintf(arq,"	int qtdEstados = %i;\n",qtdEstados);
	fprintf(arq,"	char cadeia[50] = \"%s\";\n",cadeia);
	fprintf(arq,"	char vetFinais[50] = \"%s\";\n",vetEstadosFinais);
	fprintf(arq,"	int qtdEstadosFinais = %i;\n",qtdEstadosFinais);

	fprintf(arq,"	int i = 0;\n");
	fprintf(arq,"	int tam = 0;\n");
	fprintf(arq,"	int posAceitacao = 0;\n\n");
	fprintf(arq,"	for(i = 0;cadeia[i] != '\\0';i++,tam++);\n\n");

	fprintf(arq,"	posAceitacao = AFD(cadeia,tam,vetFinais,qtdEstadosFinais,vetEstados,qtdEstados);\n");
	fprintf(arq,"	printf(\"%%i\",posAceitacao);\n\n");

	fprintf(arq,"return 0;\n");
	fprintf(arq,"}\n\n\n");

	fprintf(arq,"int AFD(char *c,int tam,char *vetFinais,int qtdEstadosFinais,char *vetEstados,int qtdEstados){\n\n");


	fprintf(arq,"	char estado = '%c';\n",estadoInicial);
	fprintf(arq,"	int i = 0;\n\n");

	fprintf(arq,"	for(;;){\n\n");

	fprintf(arq,"		switch(estado){\n");

	for(i = 0;i < qtdEstados;i++){

	fprintf(arq,"			case '%c':\n\n",vetEstados[i]);

	fprintf(arq,"				switch(c[i]){\n");

		for(j = 0;j < qtdAlfabeto;j++){
			if(matrizTransicao[i][j] != '*'){
	fprintf(arq,"					case '%c':{\n",vetAfabeto[j]);

	fprintf(arq,"						estado = '%c'; \n",matrizTransicao[i][j]);
	fprintf(arq,"						i++; \n");

	fprintf(arq,"					break;\n");
	fprintf(arq,"					}\n\n");
			}
		}
	fprintf(arq,"					case '\\0':\n");
	fprintf(arq,"						return -(buscarVet(estado,vetEstados,qtdEstados)+1);\n");

	fprintf(arq,"					default:\n");
	fprintf(arq,"						return 0;\n");
	fprintf(arq,"					break;\n");

	fprintf(arq,"				}\n\n");
	fprintf(arq,"			break;\n\n");

	}

	fprintf(arq,"			default:\n");
	fprintf(arq,"				return 0;\n");
	fprintf(arq,"			break;\n\n");

	fprintf(arq,"		}\n\n");
	fprintf(arq,"		if(i == tam)\n");
	fprintf(arq,"		break;\n");
	fprintf(arq,"	}\n\n");

	fprintf(arq,"	if(buscarVet(estado,vetFinais,qtdEstadosFinais) != -1){\n");
	fprintf(arq,"		return buscarVet(estado,vetEstados,qtdEstados)+1;\n");
	fprintf(arq,"	}else{\n");
	fprintf(arq,"		return -(buscarVet(estado,vetEstados,qtdEstados)+1);\n");
	fprintf(arq,"	}\n\n");

	fprintf(arq,"}\n\n");

	fprintf(arq,"int buscarVet(char c,char *vetor,int tam){\n");
	fprintf(arq,"	int i;\n");
	fprintf(arq,"	for(i=0;i < tam;i++){\n");
	fprintf(arq,"	if(vetor[i] == c)\n");
	fprintf(arq,"		return i;\n");
	fprintf(arq,"	}\n");
	fprintf(arq,"	return -1;\n");
	fprintf(arq,"}\n");

	fclose(arq);


}
