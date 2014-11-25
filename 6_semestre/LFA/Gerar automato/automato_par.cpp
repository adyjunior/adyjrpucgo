#include<cstdio>

int AFD();
void geraAutomato();

int main(int argc,char *argv[]){

 //printf(" - retorno = %i",AFD());

	geraAutomato();

return 0;
}


void geraAutomato(){


/*	char vetEstados[50] = "RS";
	char vetAfabeto[50] = "01";
	char vetEstadosFinais[50] = "S";
	char estadoInicial = 'R';
	char matrizTransicao[50][50];
	char cadeia[50] = "1010100";

	int qtdEstados = 2;
	int qtdAlfabeto = 2;
	int qtdEstadosFinais = 1;
	int i=0;
	int j=0;
	int cont = 0;

	matrizTransicao[0][0] = 'S';
	matrizTransicao[0][1] = 'R';

	matrizTransicao[1][0] = 'S';
	matrizTransicao[1][1] = 'R';


 */

	char vetEstados[50] = "ABCDEF";
	char vetAfabeto[50] = "01";
	char vetEstadosFinais[50] = "CDE";
	char estadoInicial = 'A';
	char matrizTransicao[50][50];
	char cadeia[50] = "10000";

	int qtdEstados = 6;
	int qtdAlfabeto = 2;
	int qtdEstadosFinais = 3;
	int i=0;
	int j=0;
	int cont = 0;

	for(i = 0;cadeia[i] != '\0';i++,cont++);


	printf("%i",cont);

	matrizTransicao[0][0] = 'B';
	matrizTransicao[0][1] = 'C';

	matrizTransicao[1][0] = 'A';
	matrizTransicao[1][1] = 'D';

	matrizTransicao[2][0] = 'E';
	matrizTransicao[2][1] = 'F';

	matrizTransicao[3][0] = 'E';
	matrizTransicao[3][1] = 'F';

	matrizTransicao[4][0] = 'E';
	matrizTransicao[4][1] = 'F';

	matrizTransicao[5][0] = 'F';
	matrizTransicao[5][1] = 'F';

	FILE *arq = fopen("fonte.c","wt");

	if (arq==NULL) return;

	fprintf(arq,"#include<cstdio> \n\n");

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

	fprintf(arq,"					case '%c':{\n",vetAfabeto[j]);

	fprintf(arq,"						estado = '%c'; \n",matrizTransicao[i][j]);
	fprintf(arq,"						i++; \n");
	//fprintf(arq,"						if(i == tam)\n");
	//fprintf(arq,"							return '%c';\n",matrizTransicao[i][j]);

	fprintf(arq,"					break;\n");
	fprintf(arq,"					}\n\n");

		}
	fprintf(arq,"					case '\\0':\n");
	fprintf(arq,"						return 0;\n");

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

	fprintf(arq,"	if(buscarVet(estado,vetFinais,qtdEstadosFinais) != -1){;\n");
	fprintf(arq,"		return buscarVet(estado,vetEstados,qtdEstados)+1;\n");
	fprintf(arq,"	}else{\n");
	fprintf(arq,"		return -buscarVet(estado,vetEstados,qtdEstados)+1;\n");
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


}

