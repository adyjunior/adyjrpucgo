package principal;

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

	public String receber(Fibonacci coordenador) throws Exception{
		ServerSocket serv = null;
		BufferedReader r = null;
		try {
			serv = new ServerSocket(porta);

			socket = serv.accept();

			r = new BufferedReader (new InputStreamReader (socket.getInputStream()) );
			
			String msg = r.readLine()+"\n";;
			while(r.ready()){
				msg = msg+ r.readLine()+"\n";
			}

			//System.out.println(msg);
			
			String retorno;
			retorno = coordenador.tratarRequisicao(msg);
			
			resposta(retorno);
			
			return msg;
		}catch (IllegalArgumentException e) {
			throw e;
		} catch (IOException e) {
			throw e;
		} catch (Exception e) {
			throw e;
		}finally{
			r.close();
			socket.close();
			serv.close();			
		}
	}
	private void resposta(String msg) throws Exception{
		PrintWriter w = null;
		try{
			w = new PrintWriter (socket.getOutputStream(), true);  // autoFlush
			w.println(msg);
			w.flush();
		}catch (IOException e) {
			System.err.println("Erro ao enviar resposta ao nó anterior."+e.getMessage());
			throw e;
		} catch (Exception e) {
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