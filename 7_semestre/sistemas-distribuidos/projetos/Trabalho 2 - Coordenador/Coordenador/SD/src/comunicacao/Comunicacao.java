package comunicacao;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ConnectException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

import serializacao.Serializacao;

import coordenador.Coordenador;

public class Comunicacao implements Runnable{

	Socket socket;

	private static final int porta = 5000;
	private String host;
	
	private Coordenador coordenador;

	public Comunicacao(Coordenador coordenador, Socket socket){
		this.coordenador = coordenador;
		this.socket = socket;
	}

	public String receber(Coordenador coordenador) throws Exception{
		ServerSocket serv = null;
		BufferedReader r = null;
		
		DataInputStream dataInputStream = null;
		try {
/*			serv = new ServerSocket(porta);
			socket = serv.accept();
*/
			dataInputStream = new DataInputStream(socket.getInputStream());
			
			byte [] buffer = new byte[50000];
			
			dataInputStream.read(buffer);
			
			String msg = new String(buffer).trim();
			
/*			r = new BufferedReader (new InputStreamReader (socket.getInputStream()) );
			
			String msg = r.readLine()+"\n";;
			while(r.ready()){
				msg = msg+ r.readLine()+"\n";
			}
*/
			//System.out.println(msg);
			Serializacao.escreveEmArquivo("arq-msg-req",msg);
			
			String retorno;
			retorno = coordenador.tratarRequisicao(msg);
			
			resposta(retorno);
			
			return msg;
		}catch (IllegalArgumentException e) {
			System.err.println("ERRO: Intervalo de porta fora do escopo válido entre 0 e 65535.");
			throw e;
		} catch (IOException e) {
			System.err.print("Erro ao tratar mensagem enviada."+e.getMessage());			
			throw e;
		} catch (Exception e) {
			System.err.println(e.getMessage());
			throw e;
		}finally{
			//r.close();
			dataInputStream.close();
			socket.close();			
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
			System.out.println("Resultado enviado !\n");
			
			String resposta = r.readLine();
			System.out.println(resposta);			
			
			return resposta;
		}catch(UnknownHostException u){
			System.err.println("Host desconhecido !");
			throw u;
		}catch (ConnectException c) {
			System.err.println("Conexão mal sucedida !"+c.getMessage());
			throw c;
		}
		catch (IOException e) {
			System.err.println("Erro ao enviar msg :"+e.getMessage());
			throw e;
		} catch (Exception e) {
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
		DataOutputStream dataOutputStream = null;
		try{
			Serializacao.escreveEmArquivo("arq-msg-res",msg);
			//w = new PrintWriter (socket.getOutputStream(), true);  // autoFlush
			
			dataOutputStream = new DataOutputStream(socket.getOutputStream());
			
			dataOutputStream.write(msg.getBytes());
			//w.println(msg);
			//w.flush();
			
			
		}catch (IOException e) {
			System.err.println("Erro ao enviar resposta ao nó anterior."+e.getMessage());
			throw e;
		} catch (Exception e) {
			System.err.println(e.getMessage());
			throw e;
		}finally{
			//w.close();
			dataOutputStream.close();
		}
	}
	

	public void setHost(String host) {
		this.host = host;
	}

	@Override
	public void run() {
		try {
			this.receber(coordenador);
		} catch (Exception e) {
			//System.out.println(e.getMessage());
		}
	}


}