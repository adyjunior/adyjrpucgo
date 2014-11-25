package server.concorrente;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.StringTokenizer;

public class FabricaSocket extends Thread{
	
	private Socket socket;
	
	public FabricaSocket(){
		try {
			socket = new ServerSocket(9999).accept();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
	}

	public FabricaSocket(Socket socket){
		this.socket = socket;
	}
	
	public void RunTheServer(){
		String requestMessageLine = null;
		String fileName = null;
		try{

			BufferedReader inFromClient = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			DataOutputStream outToClient = new DataOutputStream(socket.getOutputStream());
			requestMessageLine = inFromClient.readLine();
			StringTokenizer tokenizedLine = new StringTokenizer(requestMessageLine);
			if (!tokenizedLine.nextToken().equals("GET")){
			}

			fileName = tokenizedLine.nextToken();
			if (fileName.startsWith("/") == true ){
				fileName = fileName.substring(1);
			}
			File file = new File(fileName);
			int numOfBytes = (int) file.length();
			FileInputStream inFile = new FileInputStream (fileName);
			byte[] fileInBytes = new byte[30000];

			inFile.read(fileInBytes);
			outToClient.writeBytes("HTTP/1.0 200 Document Follows\r\n");
			if (fileName.endsWith(".jpg")){
				outToClient.writeBytes("Content-Type:image/jpeg\r\n");
			}
			if (fileName.endsWith(".gif")){
				outToClient.writeBytes("Content-Type:image/gif\r\n");
			}
			
			outToClient.writeBytes("Content-Length: " + numOfBytes + "\r\n");
			outToClient.writeBytes("\r\n");
			outToClient.write(fileInBytes, 0, numOfBytes);
			socket.close();			
		
		}catch(ArrayIndexOutOfBoundsException e){
			System.out.println("ERRO - ACESSOU POSICAO INVALIDA !!");			
		}catch (FileNotFoundException fl) {
			System.out.println("ERRO - Arquivo : "+fileName+" não existe !!");
		}catch (IOException Io) {
			System.out.println("ERRO de E/S ");
		}
	}
	
	
	public void run(){
		RunTheServer();
	}

}
