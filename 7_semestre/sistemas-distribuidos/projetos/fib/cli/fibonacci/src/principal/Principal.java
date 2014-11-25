package principal;

import java.util.Scanner;



public class Principal {

	public static void main(String[] args) {		
		
		Comunicacao c = new Comunicacao();
		c.setHost(args[0]);
		Fibonacci f = new Fibonacci();
		try {
			Scanner cin = new Scanner(System.in);
			String entrada = cin.nextLine();
			
			String msg = f.prepararXmlParaTransferenciaDeDados(entrada);
			
			msg = c.requisicao(msg);
			
			f.tratarRequisicao(msg);
			
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}

	}

}
