//package view;

import java.util.Scanner;

//import negocio.Perceptron;

//import comunicacao.Comunicacao;

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

		int entradaA = str.charAt(0);//q = 113, q = 119, e = 101, r = 114, t = 116, y = 121
		int entradaB = str.charAt(1);
		int saida;
		entradaA = (entradaA == 113)? 1 : 0;
		entradaB = (entradaB == 119)? 1 : 0;

		Perceptron perceptron = new Perceptron();

		perceptron.treinamento();
		System.out.println("Pesos apos treinamento do Perceptron: ");
		System.out.println("Peso A : "+perceptron.getPesoA());
		System.out.println("Peso B : "+perceptron.getPesoB());
		System.out.println("Peso BIAS : "+perceptron.getPesoBias());

		saida = perceptron.calcularSaida(entradaA, entradaB);
		System.out.println("\nResultado retornado pelo Perceptron: "+saida);
		
		System.out.println("\nResultado parcial: "+saida);
		
		System.out.println("\nPrecione <Enter> para iniciar a comunicação com segundo nó.");
		cin.nextLine();

		Comunicacao comunicacao = new Comunicacao();
		comunicacao.setHost(host);

		comunicacao.requisicao(new Integer(saida).toString());
		

	}


}
