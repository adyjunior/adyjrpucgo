//package comunicacao;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ConnectException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

public class Comunicacao {

	Socket socket;

	private static final int porta = 5000;
	private String host;

	public Comunicacao(){
	}

	public int receber(){
		ServerSocket serv;
		try {
			serv = new ServerSocket(porta);

			System.out.println( "Servidor pronto..." );

			socket = serv.accept();

			BufferedReader r = new BufferedReader (new InputStreamReader (socket.getInputStream()) );


			int msg = Integer.parseInt( r.readLine() );

			resposta(msg);
			
			r.close();
			socket.close();
			serv.close();
			return msg;
		}catch (IllegalArgumentException e) {
			System.err.println("ERRO: Intervalo de porta fora do escopo válido entre 0 e 65535.");
			System.exit(0);
			return 0;
		} catch (IOException e) {
			System.err.print("Erro ao tratar mensagem enviada pelo nó anterior."+e.getMessage());			
			System.exit(0);
			return 0;
		}
	}

	public void requisicao(String msg){
		try {
			socket = new Socket(host,porta);


			PrintWriter w = new PrintWriter (socket.getOutputStream(), true);  // autoFlush
			BufferedReader r = new BufferedReader (new InputStreamReader (socket.getInputStream()) );
			

			w.println(msg);
			System.out.println("Resultado enviado !\n");
			System.out.println(r.readLine());
			
			r.close();
			w.close();

			socket.close();
		}catch(UnknownHostException u){
			System.err.println("Host desconhecido !");
			System.exit(0);
		}catch (ConnectException c) {
			System.err.println("Conexão mal sucedida !"+c.getMessage());
			System.exit(0);
		}
		catch (IOException e) {
			System.err.println("Erro ao enviar msg :"+e.getMessage());
			System.exit(0);
		}

	}
	
	private void resposta(int msg){
		try{
			PrintWriter w = new PrintWriter (socket.getOutputStream(), true);  // autoFlush
			w.println("Mensagem recebida pelo servidor: "+ msg +"\r");
			w.flush();
			w.close();
		}catch (IOException e) {
			System.err.println("Erro ao enviar resposta ao nó anterior."+e.getMessage());
			System.exit(0);
		}
	}
	

	public void setHost(String host) {
		this.host = host;
	}


}
