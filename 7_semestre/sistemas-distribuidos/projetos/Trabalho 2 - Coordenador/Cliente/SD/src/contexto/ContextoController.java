package contexto;


import java.text.SimpleDateFormat;
import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;

import protocolo.soap.Protocolo;

import comunicacao.Comunicacao;

import coordenador.Coordenador;

public class ContextoController {

	private static ContextoController instancia;
	
	private Coordenador coordenador;
	private Comunicacao comunicacao;
	private Protocolo protocolo;
	
	private ContextoController() {
		coordenador = new Coordenador();
		comunicacao = new Comunicacao();
		//comunicacao.setHost("192.168.0.134");
		comunicacao.setHost("172.30.7.53");
		protocolo = new Protocolo();
	}
	
	public static ContextoController getInstancia(){
		if(instancia == null){
			instancia = new ContextoController();
		}
		
		return instancia;
	}
	
	
	
	public void inicializacao() throws Exception{
		System.out.println("## No id "+Coordenador.getId()+" inicializado com sucesso as "+new SimpleDateFormat("dd/MM/yyyy - HH:mm:ss").format(Coordenador.getTempo())+" !! ##\n\n");
		
		Timer timer = new Timer();
		
		timer.schedule(new TimerTask() {
			@Override
			public void run(){
				try {
					atualizarRelogio();					
				} catch (Exception e) {
					//System.out.println(e.getMessage());
				}
			}
		}, 0, 60000);
	
					
			
			System.out.println("Se deseja acessar algum recurso tecle <enter>\n");
			Scanner cin = new Scanner(System.in);
			String flag = "S";			
			cin.nextLine();
			
			
			for(;"s".equalsIgnoreCase(flag);){
				
				String recurso = null;
				
				System.out.print("\nDigite o nome do recurso a ser ultilizado: ");
				recurso = cin.nextLine();
				
				try{
					utilizarRecurso(recurso);					
				}catch (Exception e) {
				}
				
				System.out.print("Se deseja acessar algum outro recurso tecle S se nao tecle N : ");
				flag = cin.nextLine();
			}
		
	}
	
	
	private void utilizarRecurso(String recurso) throws Exception{

			String tipoRequisicao = "recurso";
			//String recurso = "recurso1.txt";
			
			String requisicao = protocolo.prepararCabecalhoHttp();
			requisicao += protocolo.prepararXmlParaTransferenciaDeDados(tipoRequisicao, recurso);
			String resposta = comunicacao.requisicao(requisicao);
			coordenador.tratarRequisicao(resposta);

	}
	
	
	private void atualizarRelogio() throws Exception{
			String tipoRequisicao = "atualizar";

			String requisicao = protocolo.prepararCabecalhoHttp();
			requisicao += protocolo.prepararXmlParaTransferenciaDeDados(tipoRequisicao, null);
			String resposta = comunicacao.requisicao(requisicao);
			coordenador.tratarRequisicao(resposta);
			
	}
	
	
}
