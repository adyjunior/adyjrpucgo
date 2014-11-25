package principal;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ConnectException;
import java.net.Socket;
import java.net.UnknownHostException;



public class Comunicacao {

	Socket socket;

	private static final int porta = 5000;
	private String host;

	public Comunicacao(){
	}

	public String requisicao(String msg) throws Exception{
		PrintWriter w = null;
		BufferedReader r = null;
		try {
			socket = new Socket(host,porta);

			w = new PrintWriter (socket.getOutputStream(), true);  // autoFlush
			r = new BufferedReader (new InputStreamReader (socket.getInputStream()) );
			
			w.println(msg);
			
			String resposta = r.readLine()+"\n";
			for(;r.ready();){
				resposta += r.readLine()+"\n";
			}
						
			return resposta;
		}catch(UnknownHostException u){
			throw new Exception("\nHost desconhecido !");
		}catch (ConnectException c) {
			System.err.println("\nConex�o mal sucedida !"+c.getMessage());
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
	

	public void setHost(String host) {
		if(host == null || host.length() == 0){
			host = "127.0.0.1";
		}else{
			this.host = host;			
		}
	}


}