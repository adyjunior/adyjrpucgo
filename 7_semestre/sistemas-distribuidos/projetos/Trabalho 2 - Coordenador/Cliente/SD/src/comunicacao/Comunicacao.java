package comunicacao;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ConnectException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;


import coordenador.Coordenador;

public class Comunicacao {

	Socket socket;

	private static final int porta = 5000;
	private String host;

	public Comunicacao(){
	}

	public String receber() throws Exception{
		ServerSocket serv = null;
		BufferedReader r = null;
		try {
			serv = new ServerSocket(porta);

			System.out.println( "Servidor pronto..." );

			socket = serv.accept();

			r = new BufferedReader (new InputStreamReader (socket.getInputStream()) );

			String msg = r.readLine();

			resposta(msg);
			
			return msg;
		}catch (IllegalArgumentException e) {
			System.err.println("\nERRO: Intervalo de porta fora do escopo válido entre 0 e 65535.");
			throw e;
		} catch (IOException e) {
			System.err.print("\nErro ao tratar mensagem enviada pelo nó anterior."+e.getMessage());
			throw e;
		}catch (Exception e) {
			System.err.println(e.getMessage());
			throw e;
		}finally{
			r.close();
			socket.close();
			serv.close();
		}
	}

	public String requisicao(String msg) throws Exception{
		PrintWriter w = null;
		BufferedReader r = null;
		try {
			socket = new Socket(host,porta);

			w = new PrintWriter (socket.getOutputStream(), true);  // autoFlush
			r = new BufferedReader (new InputStreamReader (socket.getInputStream()) );
			
			w.println(msg);
			
			//System.out.println("Resultado enviado !\n");
			
			String resposta = r.readLine()+"\n";
			for(;r.ready();){
				resposta += r.readLine()+"\n";
			}
			
			//System.out.println(resposta);
						
			return resposta;
		}catch(UnknownHostException u){
			throw new Exception("\nHost desconhecido !");
		}catch (ConnectException c) {
			System.err.println("\nConexão mal sucedida !"+c.getMessage());
			throw c;
		}
		catch (IOException e) {
			System.err.println("\nErro ao enviar msg :"+e.getMessage());
			throw e;
		}catch (Exception e) {
			System.err.println(e.getMessage());			
			throw e;
		}finally{
			r.close();
			w.close();
			socket.close();			
		}
	}
	
	private void resposta(String msg) throws Exception{
		PrintWriter w = null;
		try{
			w = new PrintWriter (socket.getOutputStream(), true);  // autoFlush
			w.println(Coordenador.getId());
			w.flush();
		}catch (IOException e) {
			System.err.println("\nErro ao enviar msg :"+e.getMessage());
			throw e;
		}catch (Exception e) {
			System.err.println(e.getMessage());
			throw e;
		}finally{
			w.close();
		}
	}
	

	public void setHost(String host) {
		this.host = host;
	}


}