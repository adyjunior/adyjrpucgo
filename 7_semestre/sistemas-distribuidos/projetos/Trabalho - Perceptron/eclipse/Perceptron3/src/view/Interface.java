package view;

import java.util.Scanner;

import negocio.Perceptron;

import comunicacao.Comunicacao;

public class Interface {

	public static void main(String[] args) {
		String host = "127.0.0.1";
		if(args.length == 1){
			host = args[0];
		}
		Interface i = new Interface();
		i.entrada(host);
	}

	private void entrada(String host){
		String str = null;
		Scanner cin = new Scanner(System.in);

		for(;str == null || str.length() != 2;){

			System.out.println("Digite a entrada ");

			str = cin.nextLine();

			if(str == null || str.length() != 2){
				System.out.println("ERRO: Digite novamente a entrada!");
			}
		}

		int entradaA = str.charAt(0);//t = 116, y = 121
		int entradaB = str.charAt(1);
		int saida;
		entradaA = (entradaA == 116)? 1 : 0;
		entradaB = (entradaB == 121)? 1 : 0;

		Perceptron perceptron = new Perceptron();

		perceptron.treinamento();
		System.out.println("Pesos apos treinamento do Perceptron: ");
		System.out.println("Peso A : "+perceptron.getPesoA());
		System.out.println("Peso B : "+perceptron.getPesoB());
		System.out.println("Peso BIAS : "+perceptron.getPesoBias());

		saida = perceptron.calcularSaida(entradaA, entradaB);
		System.out.println("\nResultado retornado pelo Perceptron: "+saida);
		
		int entradaC = 0;
		Comunicacao comunicacao = new Comunicacao();
		comunicacao.setHost(host);
		
		System.out.println("\nPrecione <Enter> para iniciar o servidor.");
		cin.nextLine();

		entradaC = comunicacao.receber();
		System.out.println("\nMsg enviada pelo segundo nó: "+entradaC);
		
		System.out.println("\nResultado calculado pelo nó anterior: "+entradaC);
		System.out.println("Resultado calculado por este nó: "+saida);
		saida = perceptron.calcularSaida(entradaC, saida);
		System.out.println("Resultado Final: "+saida);
		
		if(saida == 1){
			System.out.println("\nCaminho Correto !");
		}else{
			System.out.println("\nCaminho Incorreto !");
		}
	}


}
