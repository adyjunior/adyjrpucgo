package com.sintatico;

import java.util.ListIterator;

import com.analex.Token;

public class Sintatico {

	private ListIterator<Token> lookAHead;
	
	public Sintatico(ListIterator<Token> lookAHead) {
		this.lookAHead = lookAHead;		
	}
	
	public void A(){

		B();
		R();
	}

	public void B(){

		C();
		S();
	}

	public void R(){
		if(!lookAHead.hasNext()){
			return;
		}
		
		Token t = lookAHead.next();
		lookAHead.previous();
		if("+".equals(t.getLexema())){
			lookAHead.next();
			B();
			R();
		}else if("-".equals(t.getLexema())){
			lookAHead.next();
			B();
			R();
		}
	}

	public void C(){

		D();
		T();
	}

	public void S(){
		if(!lookAHead.hasNext()){
			return;
		}

		Token t = lookAHead.next();
		lookAHead.previous();
		if("*".equals(t.getLexema())){
			lookAHead.next();
			B();
			R();
		}else if("/".equals(t.getLexema())){
			lookAHead.next();
			B();
			R();
		}
	}

	public void D(){
		if(!lookAHead.hasNext()){
			return;
		}

		Token t = lookAHead.next();
		lookAHead.previous();
		if(t.getTipo() == 8 || t.getTipo() == 9){
			System.out.print(t.getLexema()+" ");
			//printf(" %s ",lookAHead->lexema);
			lookAHead.next();
		}else{
			System.out.println("ERRO : Numero esperado.");
			System.exit(0);
		}

	}

	public void T(){
		if(!lookAHead.hasNext()){
			return;
		}

		Token t = lookAHead.next();
		lookAHead.previous();
		if("%".equals(t.getLexema())){
			System.out.println(t.getLexema());
			lookAHead.next();
			D();
			T();
		}
	}	

}
