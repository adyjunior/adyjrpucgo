package com.analex;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.ListIterator;

public class Analex {


	private String [] PALAVRAS_RESERVADAS = {"se","senao","inicio","fim","enquanto","principal","inteiro","real","literal"};
	private String [] CATEGORIAS = {"","Identificadores", "Operador condicional", "Operador aritmetico", "Pontuacao", "Delimitador", "Caracteres", "Operador de atribuicao", "Inteiro", "Ponto flutuante", "Operador logico", "Operador de comparacao", "\\n ou \\0", "Palavras reservadas"};
	private int qtdPalavrasReservadas = 9;
	private int [] vetEstados = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
	private char [] vetAfabeto = {'l','d','.','\"','c','<','b','p','x','!','>','e','o','u','n','a','=','-'};
	private int qtdEstados = 29;
	private int qtdAlfabeto = 18;
	private int [] vetFinais = {2,3,4,6,7,9,10,11,16,17,18,19,20,21,22,25,27,28,29};
	private int qtdEstadosFinais = 19;
	private int tamCadeia = 0;	

	private static final int CTE_MUDALINHA = 12;
	
	private ListIterator<Token> lookAHead;

	private List<Token> listaToken;
	private List<Simbolo> listaSimbolo;
	private Integer pos;
	
	public Analex() {
		listaToken = new ArrayList<Token>();
		listaSimbolo = new ArrayList<Simbolo>();
	}

	public boolean buscarVetStr(String str,int tam){
		int i;
		for(i = 0;i < tam;i++){
			if(str.equals(PALAVRAS_RESERVADAS[i])){
				return true;
			}
		}

		return false;
	}
	
	public void zerarVetor(char []vet){
		
		for(int i = 0;i < vet.length;i++){
			if(vet[i] == '\u0000'){
				break;
			}
			vet[i] = '\u0000';
		}
	}

	public int codigoCategoria(int estado,String lexema){

		if(estado == 2){//var if
			if(buscarVetStr(lexema,qtdPalavrasReservadas)){
				return 13;
			}else{
				return 1;
			}
		}else if(estado == 6 || estado == 7 || estado == 17 || estado == 19 || estado == 20){// <= <
			return 2;
		}else if(estado == 9){// + -
			return 3;
		}else if(estado == 10 || estado == 4 ){ // , ;
			return 4;
		}else if(estado == 11){// { ]
			return 5;
		}else if(estado == 16){// "string"
			return 6;
		}else if(estado == 18){// <-
			return 7;
		}else if(estado == 3){// 12
			return 8;
		}else if(estado == 21){// 50.2
			return 9;
		}else if(estado == 22 || estado == 25 || estado == 27){// .e. .ou. .nao.
			return 10;
		}else if(estado == 28){// =
			return 11;
		}else if(estado == 29){ // \n ou \0
			return 12;
		}

		return 0;
	}
	



	public char ehLetra(char c){

		if(( c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z')){
			return 'l';
		}
		return '*';
	}

	public char ehDigito(char c){
		if(c >= '0' && c <= '9'){
			return 'd';
		}
		return '*';
	}

	public char ehCaractere(char c){
		if(c !=  '\"'  ){
			if(c != '\n' && c != '\0'){
				return 'c';
			}else{
				return c;
			}
		}
		return '\"';
	}	

	public char tipoCaractere(char c){

		if(ehDigito(c) == 'd'){
			return 'd';
		}

		if(ehLetra(c) == 'l'){
			return 'l';
		}

		if(c == ',' || c == ';'){
			return 'p';
		}

		if(c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']'){
			return 'b';
		}

		if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
			return 'x';
		}


		return c;
	}

	public int buscarVet(int c,int [] vetor,int tam){
		int i;
		for(i=0;i < tam;i++){
			if(vetor[i] == c)
				return i;
		}
		return -1;
	}


	public ListIterator<Token> lerArquivo(String nomeArquivo){
		//File entrada = new File(nomeArquivo);
		char [] linha = new char[255];
		char [] lexema = new char[255];
		ListIterator<Token> iteratorToken;


		separaTokens(linha,lexema,nomeArquivo);

		iteratorToken = listaToken.listIterator();
		//printf("\n");

		//divideLexemaPorCategoria(lexema,iteratorToken);

		//struct Simbolo *iniSimb=NULL, *auxSimb;

		separaIdentificadores();

		for(Simbolo simbolo : listaSimbolo){
			System.out.println("Lexema: "+simbolo.getToken().getLexema());
			//printf("LEXEMA: %s\n",auxSimb->token->lexema);
		}

		return iteratorToken;
	}	

	public void separaIdentificadores(){

		for(Token token : listaToken){
		    	if(token.getTipo() == 1){
		    		//insereListaSimbolo(aux,&(*iniSimb));
		    		Simbolo simbolo = new Simbolo(token,0);
		    		listaSimbolo.add(simbolo);
		    		Collections.sort(listaSimbolo);
		    	}
		    }
	}



	public void separaTokens(char []linha,char []lexema,String nomeArquivo){
		
		int categoria = 0, posAceitacao;
		BufferedReader bufferedReader = null;
		try{
			
			//for(fgets(linha,255,entrada);!feof(entrada);fgets(linha,255,entrada)){
			bufferedReader = new BufferedReader(new FileReader(nomeArquivo));

			String str = null;

			for(;bufferedReader.ready();){
				str = bufferedReader.readLine();

				str = str+"\n ";
				linha = str.toCharArray();
				pos = 0;

				posAceitacao = AFD(linha,lexema);

				if(posAceitacao > 0){
					categoria = codigoCategoria(vetEstados[posAceitacao],String.valueOf(lexema));
					//insereLista(lexema,c,&(*lstTokenIni),&(*lstTokenFim));
					Token token = new Token();
					String strLexema = String.valueOf(lexema);
					strLexema = strLexema.replaceAll("\u0000", "");
					token.setLexema(strLexema);
					token.setTipo(categoria);
					
					listaToken.add(token);

				}else{
					System.out.println("ERRO TOKEN: "+String.valueOf(lexema));
					System.exit(0);
				}
				
				zerarVetor(lexema);

				for(;categoria != CTE_MUDALINHA;){
					if(posAceitacao > 0){
						categoria = 0;
					}

					posAceitacao = AFD(linha,lexema);

					if(posAceitacao > 0){
						categoria = codigoCategoria(vetEstados[posAceitacao],String.valueOf(lexema));
						Token token = new Token();
						String strLexema = String.valueOf(lexema);
						strLexema = strLexema.replaceAll("\u0000", "");
						token.setLexema(strLexema);
						token.setTipo(categoria);
						listaToken.add(token);
						//insereLista(lexema,categoria,&(*lstTokenIni),&(*lstTokenFim));
					}else{
						System.out.println("ERRO TOKEN: "+String.valueOf(lexema));
						System.exit(0);
					}
					
					zerarVetor(lexema);
				}
			}

			bufferedReader.close();
		}catch (IOException e) {
			System.out.println(e.getStackTrace());
		}
	}	

	
	void divideLexemaPorCategoria(char []lexema,ListIterator<Token> iterator){
		
		for(Token token: listaToken){
			System.out.println("Lexema: "+token.getLexema()+" Categoria: "+CATEGORIAS[token.getTipo()]);
		}
	}

	public int verificaDefault(char [] lexema,char [] cadeia,int i,int j,int estado){
		if(buscarVet(estado,vetFinais,qtdEstadosFinais) != -1){
			lexema[j] = '\0';
			pos = i;
			return buscarVet(estado,vetEstados,qtdEstados);
		}else{
			lexema[j] = cadeia[i];
			pos = ++i;
			j++;
			lexema[j] = '\0';
			return -(buscarVet(estado,vetEstados,qtdEstados));
		}
	}

	public int AFD(char [] cadeia,char [] lexema){

		int estado = 1;
		int i = pos;
		int j = 0;
		
		while(cadeia[i] == ' ' || cadeia[i] == '\t'){
			i++;
		}

		for(;;){


			switch(estado){
			case 1:

				switch(tipoCaractere(cadeia[i])){
				case 'l'  :
					estado = 2;
					break;

				case 'd':
					estado = 3;
					break;

				case '.':
					estado = 4;
					break;

				case '\"':
					estado = 5;
					break;

				case '<':
					estado = 6;
					break;

				case 'b':
					estado = 11;
					break;

				case 'p':
					estado = 10;
					break;

				case 'x':
					estado = 9;
					break;

				case '!':
					estado = 8;
					break;

				case '>':
					estado = 7;
					break;

				case '=':
					estado = 28;
					break;

				case '\n':
					estado = 29;
					break;

				case '\0':
					estado = 29;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 2:

				switch(tipoCaractere(cadeia[i])){
				case 'l':
					estado = 2;
					break;

				case 'd':
					estado = 2;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 3:

				switch(tipoCaractere(cadeia[i])){
				case 'd':
					estado = 3;
					break;

				case '.':
					estado = 12;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 4:

				switch(cadeia[i]){
				case 'e':
					estado = 13;
					break;

				case 'o':
					estado = 14;
					break;

				case 'n':
					estado = 15;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 5:

				switch(ehCaractere(cadeia[i])) {
				case '\"':
					estado = 16;
					break;

				case 'c':
					estado = 5;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 6:

				switch(cadeia[i]){
				case '=':
					estado = 17;
					break;

				case '-':
					estado = 18;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 7:

				switch(cadeia[i]){
				case '=':
					estado = 19;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 8:

				switch(cadeia[i]){
				case '=':
					estado = 20;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 9:

				switch(tipoCaractere(cadeia[i])){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				//break;

			case 10:

				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				//break;

			case 11:

				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				//break;

			case 12:

				switch(tipoCaractere(cadeia[i])){
				case 'd':
					estado = 21;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 13:

				switch(cadeia[i]){
				case '.':
					estado = 22;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 14:

				switch(cadeia[i]){
				case 'u':
					estado = 24;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					///break;
				}

				break;

			case 15:

				switch(cadeia[i]){
				case 'a':
					estado = 23;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 16:

				switch(ehCaractere(cadeia[i])){
				case '\"':
					estado = 5;
					break;

				case 'c'://exception
					estado = 5;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 17:

				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				//break;

			case 18:

				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				//break;

			case 19:

				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				//break;

			case 20:

				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				//break;

			case 21:

				switch(tipoCaractere(cadeia[i])){
				case 'd':
					estado = 21;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 22:

				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//	break;
				}

				//break;

			case 23:

				switch(cadeia[i]){
				case 'o':
					estado = 26;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 24:

				switch(cadeia[i]){
				case '.':
					estado = 25;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 25:

				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				//break;

			case 26:

				switch(cadeia[i]){
				case '.':
					estado = 27;
					break;

				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				break;

			case 27:

				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				//break;

			case 28:

				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}

				//break;

			case 29:
				switch(cadeia[i]){
				default:
					return verificaDefault(lexema,cadeia,i,j,estado);
					//break;
				}
				//break;

			default:
				return 0;
				//break;

			}

			lexema[j] = cadeia[i];
			i++;
			j++;
		}

		//return 0;
	}


}
