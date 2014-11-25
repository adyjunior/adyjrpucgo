package com.analex;

public class Simbolo implements Comparable<Simbolo>{
	
	private Token token;
	private int valor;
	
	public Simbolo() {
	}
	
	public Simbolo(Token token,int valor) {
		this.token = token;
		this.valor = valor;
	}	
	
	public Token getToken() {
		return token;
	}
	public void setToken(Token token) {
		this.token = token;
	}
	public int getValor() {
		return valor;
	}
	public void setValor(int valor) {
		this.valor = valor;
	}

	@Override
	public int compareTo(Simbolo o) {
		
		return this.token.getLexema().compareTo(o.getToken().getLexema());
	}
	
	

}
