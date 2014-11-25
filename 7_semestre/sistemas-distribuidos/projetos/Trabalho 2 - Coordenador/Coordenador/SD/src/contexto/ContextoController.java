package contexto;


import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import comunicacao.Comunicacao;
import coordenador.Coordenador;


public class ContextoController {

	private Coordenador coordenador;
	
	public ContextoController() {
		coordenador = new Coordenador();
	}
	
	public void inicializacao(){
		
/*		Comunicacao c = new Comunicacao(coordenador);
		Thread thread = new Thread(c);
		
		for(;;){
			try {
				thread.start();
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}			
		}
*/		
		
		Socket socket = null;
		ServerSocket serverSocket= null;
		try {
			serverSocket = new ServerSocket(5000);

		for(;;){
			socket = serverSocket.accept();
			
			Comunicacao c = new Comunicacao(coordenador, socket);
			Thread thread = new Thread(c);

			thread.start();
		}
		
		} catch (IOException e) {
		}
		
		
	}
	
	
}
