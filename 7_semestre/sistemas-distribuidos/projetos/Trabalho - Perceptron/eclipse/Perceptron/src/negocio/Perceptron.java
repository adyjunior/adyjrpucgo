package negocio;

public class Perceptron {
	
	private int entradaA1;
	private int entradaB1;
	private int saidaDesejada1;

	private int entradaA2;
	private int entradaB2;
	private int saidaDesejada2;
	
	private int entradaA3;
	private int entradaB3;
	private int saidaDesejada3;
	
	private int entradaA4;
	private int entradaB4;
	private int saidaDesejada4;
	
	private static final int BIAS = 1;
	
	
	private double pesoA;
	private double pesoB;
	private double pesoBias;
	
	private double saidaCalculada;	
	private double valorErro;// resposta desejada - resposta real	
	private static final double taxaAprendizagem = 0.5;
	
	
	
	public Perceptron(){
		entradaA1 = 0;
		entradaB1 = 0;
		saidaDesejada1 = 0;
		
		entradaA2 = 0;
		entradaB2 = 1;
		saidaDesejada2 = 0;
		
		entradaA3 = 1;
		entradaB3 = 0;
		saidaDesejada3 = 0;
		
		entradaA4 = 1;
		entradaB4 = 1;
		saidaDesejada4 = 1;
		
		pesoA = 0;
		pesoB = 0;
		pesoBias = 0;
		
	}
	
	
	private double calcularErro(int saidaDesejada){
		return saidaDesejada - saidaCalculada;
	}
	
	private double calcularPeso(double pesoAnterior, double valorEntrada){
		return pesoAnterior + (taxaAprendizagem*valorErro*valorEntrada);
	}
	
	
	public int calcularSaida(int entradaA,int entradaB){
		double saida = 0.0;
		saida = saida +((entradaA*pesoA) + (entradaB*pesoB));
		saida = saida + (BIAS*pesoBias);
		
		if(saida > 0){
			return 1;
		}
		return 0;
	}
	
	public void treinamento(){
		
		boolean treinou = false;
		//repetir enquanto erro for diferente de 0
		for(;!treinou;){
			
			treinou = true;
			
			
			treinou = passoTreinamento(entradaA1, entradaB1, saidaDesejada1);
			if(!treinou)continue;
			treinou = passoTreinamento(entradaA2, entradaB2, saidaDesejada2);
			if(!treinou)continue;
			treinou = passoTreinamento(entradaA3, entradaB3, saidaDesejada3);
			if(!treinou)continue;
			treinou = passoTreinamento(entradaA4, entradaB4, saidaDesejada4);
			
		}
	}
		
	
	private boolean passoTreinamento(int entradaA,int entradaB,int saidaDesejada){
		boolean treinou = true;
		saidaCalculada = calcularSaida(entradaA, entradaB);
		
		valorErro = calcularErro(saidaDesejada);
		
		if(valorErro != 0){
			pesoA =  calcularPeso(pesoA, entradaA);
			pesoB = calcularPeso(pesoB, entradaB);
			pesoBias = calcularPeso(pesoBias, BIAS);
			treinou = false;
		}
		
		return treinou;
	}


	public double getPesoA() {
		return pesoA;
	}


	public double getPesoB() {
		return pesoB;
	}


	public double getPesoBias() {
		return pesoBias;
	}

}
