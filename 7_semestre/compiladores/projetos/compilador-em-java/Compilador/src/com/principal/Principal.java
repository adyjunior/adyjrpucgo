package com.principal;

import java.util.ListIterator;

import com.analex.Analex;
import com.analex.Token;
import com.sintatico.Sintatico;

public class Principal {
	
	public static void main(String[] args) {
		ListIterator<Token> lookAHead = null;
		Analex analex = new Analex();		
		
	    lookAHead = analex.lerArquivo("fonte1.txt");

		Sintatico sintatico = new Sintatico(lookAHead);
		
	    sintatico.A();

	    lookAHead.next();
	    if(lookAHead.hasNext()){
	    	System.out.println("ERRO");
	    	System.exit(0);
	    }
	}

}
