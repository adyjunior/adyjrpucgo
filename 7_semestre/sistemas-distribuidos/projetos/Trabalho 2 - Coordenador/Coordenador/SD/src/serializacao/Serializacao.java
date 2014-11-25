package serializacao;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.util.Date;

import util.Uteis;

public class Serializacao {
	
	
	public static String gravar(Object object) throws Exception{
		String caminhoArquivo = "temp/";
		caminhoArquivo += "arqtemp";
		try {
			
			FileOutputStream fileOutputStream = new FileOutputStream(caminhoArquivo);
			
			ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
			
			objectOutputStream.writeObject(object);
			
			objectOutputStream.flush();
			
			objectOutputStream.close();
			
		} catch (FileNotFoundException e) {
			System.err.println(e.getMessage());
			throw e;
		} catch (IOException e) {
			System.err.println(e.getMessage());
			throw e;
		}
		
		return caminhoArquivo;
	}
	
	
	public static void escreveEmArquivo(String nomeArquivo,String conteudo) throws IOException{
		String caminhoArquivo = "temp/";
		caminhoArquivo += nomeArquivo+Uteis.dateToStr(new Date(), "_dd-MM-yyyy_HH-mm-ss")+".xml";
		
		try {
			FileWriter writer = new FileWriter(caminhoArquivo);
			
			writer.write(conteudo);
			
			writer.flush();
			writer.close();
		} catch (IOException e) {
		}
		
	}
	
	public static void recuperar(){
		
	}
	
	public static void imprimirArquivo(String arquivo) throws Exception{
		String path = "recursos/";
		BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader(path+arquivo));
		
		System.out.println(reader.readLine());

		for(;reader.ready();){
			System.out.println(reader.readLine());
		}
		
		
		} catch (Exception e) {
			System.err.println("Erro na leitura do arquivo: "+arquivo+" !\n"+e.getMessage());
			throw e;
		}
	}
	
	
	public static void transferencia(PrintWriter writer, String msg){
		
		
		
	}
	
	

}
