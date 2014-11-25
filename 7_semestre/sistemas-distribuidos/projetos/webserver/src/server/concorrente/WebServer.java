package server.concorrente;

import java.io.*;
import java.net.*;
class WebServer{
	ServerSocket listenSocket;
	Socket connectionSocket; 
	public static void main(String argv[]) throws Exception {

		//WebServer webServer = new WebServer();

		//webServer.start();
			Socket socket = null;
			ServerSocket serverSocket= null;
			try {
				serverSocket = new ServerSocket(9999);

			for(;;){				
				socket = serverSocket.accept();
				
				FabricaSocket fs = new FabricaSocket(socket);

				fs.start();
			}
			
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
	}


}
