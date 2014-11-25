package coordenador;


import java.util.Date;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import protocolo.soap.Body;
import protocolo.soap.Dados;
import protocolo.soap.Envelope;
import protocolo.soap.Fault;
import protocolo.soap.Protocolo;
import protocolo.soap.Tipo;
import serializacao.Serializacao;
import util.Uteis;

import comunicacao.Comunicacao;

public class Coordenador {
	
	private static final Integer ID = 2;
		
	private Map<Integer, String> mapaIDs;
	
	private List<String> listaRecursos;
	
	private boolean ehCoordenador;
	
	private static Date tempo;
	
	static{
		tempo = new Date();
	}
	
	public Coordenador() {
		initMapaPIDs();
	}
	
	private void initMapaPIDs(){
		mapaIDs = new LinkedHashMap<Integer,String>();
		
		mapaIDs.put(1, "192.168.0.134");
		mapaIDs.put(2, "192.168.0.131");
		//mapaPIDs.put(3, "192.168.254.131");
		//mapaPIDs.put(4, "192.168.254.134");
		//mapaPIDs.put(5, "192.168.254.131");
	}
	
	
	public void realizarEleicao() throws Exception{
		
		ehCoordenador = enviarMensagens(2);
		//ehCoordenador = enviarMensagens(3);
		//ehCoordenador = enviarMensagens(4);
		//ehCoordenador = enviarMensagens(5);		
		
	}
	
	
	public void tratarRequisicao(String msg) throws Exception{
		String ip;
		String tipoRequisicao = "atualizar";
		Protocolo protocolo = new Protocolo();
		
		msg = protocolo.lerCabecalho(msg);
		
		Envelope envelope = protocolo.getResponseXml(msg);

		if(envelope == null || envelope.getHeader() == null){
			System.out.println("\nA Semantica da msg enviada pelo coordenador eh invalida.\n");
			throw new Exception();
		}

		Tipo tipo = envelope.getHeader().getTipo();
		if(tipo != null && tipo.getMustUnderstand() == Boolean.TRUE){
			if(!"response".equals(tipo.getServico())){
				System.out.println("Tipo de servico invalido");
				throw new Exception();
			}
			ip = tipo.getIp();
			tipoRequisicao = tipo.getValor();
		}


		Body body = envelope.getBody();

		if(body == null){
			System.out.println("\nA Semantica da msg enviada pelo coordenador eh invalida.\n");
			throw new Exception();
		}

		if("atualizar".equals(tipoRequisicao)){
			atualizacaoTempo(body);
		}else if("recurso".equals(tipoRequisicao)){
			requisicaoDeRecurso(body);
		}else if("excecao".equals(tipoRequisicao)){
			tratarExcecao(body);
		}

	}
	
	private void requisicaoDeRecurso(Body body) throws Exception{
		Dados dados = body.getDados();
		
		if(dados == null){
			System.out.println("\nA Semantica da msg enviada pelo coordenador eh invalida.\n");
			throw new Exception();				
		}

		//id = dados.getId();
		if(dados.getPermissaoRecurso()){
			System.out.println("# Coordenador permitiu a utilizacao do recurso "+dados.getRecurso()+"\n");
			Serializacao.imprimirArquivo(dados.getRecurso());
		}else{
			System.out.println("# Coordenador NAO permitiu a utilizacao do recurso "+dados.getRecurso()+"\n");			
		}

	}		
		
	
	
	private void atualizacaoTempo(Body body) throws Exception{
		Dados dados = body.getDados();
		
		if(dados == null){
			System.out.println("\nA Semantica da msg enviada pelo coordenador eh invalida.\n");
			throw new Exception();				
		}
		
		tempo = Uteis.strToDate(dados.getTempo());
		System.out.println("# Relogio atualizado: "+Uteis.dateToStr(tempo));
		System.out.println("# Lista de recursos disponiveis para este no : "+dados.obterListaRecursosStr());
	}
	
	private void tratarExcecao(Body body) throws Exception{
		Fault fault = body.getFault();
		
		if(fault == null || fault.getCode() == null || fault.getReason() == null){
			System.err.println("Semantica de msg invalida");
			throw new Exception();
		}
		
		String numErro = fault.getCode().getValue();
		String razaoErro = fault.getReason().getText();
		String recurso = fault.getReason().getRecurso();
		
		String msgErro = null;
		
		if(recurso != null && recurso.length() != 0){
			msgErro = "Erro "+numErro+" na solicitacao de permissao do recurso "+recurso+
					"\nO coordenador informou que a causa do erro foi: "+razaoErro+"\n";			
		}else{
			msgErro = "Erro "+numErro+", o coordenador informou que a causa do erro foi: "+razaoErro+"\n";			
		}
		
		
		System.out.println(msgErro);
		
	}

	
	
	private boolean enviarMensagens(int numeroID) throws Exception{
		
		Comunicacao comunicacao = new Comunicacao();
		comunicacao.setHost(mapaIDs.get(numeroID));
		
		String resposta = comunicacao.requisicao("");
		
		if(Integer.parseInt(resposta) > ID){
			return true;
		}
		
		return false;
	}

	public static Integer getId() {
		return ID;
	}

	public static Date getTempo() {
		return tempo;
	}

	public static void setTempo(Date t) {
		tempo = t;
	}
	

}
