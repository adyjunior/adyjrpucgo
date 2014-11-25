package coordenador;


import java.net.Socket;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import protocolo.soap.Dados;
import protocolo.soap.Envelope;
import protocolo.soap.Protocolo;
import protocolo.soap.Recurso;
import protocolo.soap.Tipo;
import util.Uteis;

import comunicacao.Comunicacao;

public class Coordenador {
	
	private static final Integer ID = 1;
	
	private Map<Integer, String> mapaIDs;
	
	private List<String> listaTodosRecursos;
	
	private Map<Integer,List<String>> listaDeRecursosPorNo;
	
	private boolean ehCoordenador;
	
	
	public Coordenador() {
		System.out.println("### COORDENADOR INICIALIZADO COM SUCESSO !! ###\n\n");
		ehCoordenador = true;
		initMapaPIDs();
		initListaRecursos();
	}
	
	private void initMapaPIDs(){
		mapaIDs = new LinkedHashMap<Integer,String>();
		
		mapaIDs.put(1, "192.168.0.134");
		mapaIDs.put(2, "192.168.0.131");
		mapaIDs.put(3, "192.168.254.131");
		mapaIDs.put(4, "192.168.254.134");
		mapaIDs.put(5, "192.168.254.131");
	}
	
	
	private void initListaRecursos(){
		listaTodosRecursos = new ArrayList<>();
		listaTodosRecursos.add("recurso1.txt");
		listaTodosRecursos.add("recurso2.xml");
		listaTodosRecursos.add("recurso3.xml");
		listaTodosRecursos.add("recurso4.xml");
		listaTodosRecursos.add("recurso5.txt");
		
		
		listaDeRecursosPorNo = new HashMap<Integer, List<String>>();
		
		List<String> lista = new ArrayList<String>();
		
		lista.add("recurso1.txt");
		lista.add("recurso2.xml");		
		listaDeRecursosPorNo.put(2, lista);
		
		lista = new ArrayList<String>();
		
		lista.add("recurso1.txt");
		lista.add("recurso3.xml");
		listaDeRecursosPorNo.put(3, lista);
		
		lista = new ArrayList<String>();
		
		lista.add("recurso1.txt");
		lista.add("recurso4.xml");
		listaDeRecursosPorNo.put(4, lista);

		lista = new ArrayList<String>();

		lista.add("recurso1.txt");
		lista.add("recurso5.txt");
		listaDeRecursosPorNo.put(5, lista);
		
	}
	
	
	public void realizarEleicao() throws Exception{
		
		ehCoordenador = enviarMensagens(1);
		//ehCoordenador = enviarMensagens(3);
		//ehCoordenador = enviarMensagens(4);
		//ehCoordenador = enviarMensagens(5);		
		
	}
	
	
	private boolean enviarMensagens(int numeroID) throws Exception{

		Socket socket = new Socket();
		Comunicacao comunicacao = new Comunicacao(this, socket);
		comunicacao.setHost(mapaIDs.get(numeroID));

		String resposta = comunicacao.requisicao("1");

		if(Integer.parseInt(resposta) > ID){
			return true;
		}

		return false;
	}
	
	
	public String tratarRequisicao(String msg) throws Exception{
		Envelope envelope = null;
		String tipoRequisicao = "atualizar";
		String recurso= "";
		String retorno = null;
		String ip = "";
		String id = "";

		Protocolo protocolo = new Protocolo();
		
		msg = protocolo.lerCabecalho(msg);
		
		try {
			envelope = protocolo.getResponseXml(msg);			
		} catch (Exception e) {
			retorno = protocolo.prepararCabecalhoHttp("500", e.getMessage());
			retorno += protocolo.prepararXmlParaInformarExcecao(null, "500", e.getMessage());
			return retorno;
		}


		if(envelope == null){
			retorno = protocolo.prepararCabecalhoHttp("500", "A semantica da msg enviada ao coordenador eh Invalida");
			retorno += protocolo.prepararXmlParaInformarExcecao(null, "500", "A semantica da msg enviada ao coordenador eh Invalida");
			return retorno;
		}

		if(envelope.getHeader() != null){
			Tipo tp = envelope.getHeader().getTipo();
			if(tp != null && tp.getMustUnderstand() == Boolean.TRUE){
				if(!"request".equals(tp.getServico())){
					throw new Exception("Tipo de servico invalido. ");
				}
				ip = tp.getIp();
				tipoRequisicao = tp.getValor(); 					
			}
		}

		if(envelope.getBody() != null){
			Dados dados = envelope.getBody().getDados();

			if(dados != null){
				id = dados.getId();

				if("recurso".equals(tipoRequisicao)){// se quiser acesso a algum recurso
					recurso = dados.getRecurso();
					boolean test = false;
					try {
						test = temAcessoRecurso(id, ip, recurso);
					} catch (Exception e) {
						retorno = protocolo.prepararCabecalhoHttp("404", e.getMessage());
						retorno += protocolo.prepararXmlParaInformarExcecao(recurso, "404", e.getMessage());
						return retorno;
					}
					if(test){
						retorno = protocolo.prepararCabecalhoHttp("200", null);
						retorno += protocolo.prepararXmlParaTransferenciaDeDados(tipoRequisicao, Boolean.TRUE, recurso, null);
						System.out.println("O no de id "+id+" com ip "+ip+" ira acessar o recurso "+recurso+".  # "+Uteis.dateToStr(Coordenador.getTempo())+"\n");
					}else{
						retorno = protocolo.prepararCabecalhoHttp("200", null);
						retorno += protocolo.prepararXmlParaTransferenciaDeDados(tipoRequisicao, Boolean.FALSE, recurso, null);
						System.out.println("O no de id "+id+" com ip "+ip+" NAO possui permissao para acessar o recurso "+recurso+".  # "+Uteis.dateToStr(Coordenador.getTempo())+"\n");
					}
				}else{// se for atualizar o tempo
					retorno = protocolo.prepararCabecalhoHttp("200", null);
					retorno += protocolo.prepararXmlParaTransferenciaDeDados(tipoRequisicao, null, null, this.obterListaDeRecursosID(id));
					System.out.println("O no de id "+id+" com ip "+ip+" requisitou a atualizacao da lista de recursos e de seu relogio.  # "+Uteis.dateToStr(Coordenador.getTempo())+"\n");
				}
			}			
		}

		return retorno;
	}
	
	
	
	private boolean temAcessoRecurso(String id, String ip, String recurso) throws Exception{
		Integer idInt = Integer.parseInt(id);
		
		boolean flag = false;
		for(String str : listaTodosRecursos){
			if(str.equals(recurso)){
				flag = true;
			}
		}
		
		if(! flag){
			System.err.println("O no de id "+id+" com ip "+ip+" tentou acessar um recurso que nao existe.  # "+Uteis.dateToStr(Coordenador.getTempo())+"\n");
			throw new Exception("Recurso "+recurso+" nao existe.");
		}
		
		List<String> lista = listaDeRecursosPorNo.get(idInt);
		
		if(lista != null){
			for(String s : lista){
				if(s.equals(recurso)){
					return true;
				}			
			}			
		}
		
		return false;
	}	

	public static Integer getId() {
		return ID;
	}
	
	public static Date getTempo(){
		return new Date();
	}

	public boolean isEhCoordenador() {
		return ehCoordenador;
	}

	public void setEhCoordenador(boolean ehCoordenador) {
		this.ehCoordenador = ehCoordenador;
	}

	public Map<Integer, List<String>> getListaDeRecursosPorNo() {
		return listaDeRecursosPorNo;
	}
	
	public List<Recurso> obterListaDeRecursosID(String id){
		if(id == null){
			return null;
		}
		
		Integer idInt = null;
		try {
			idInt = Integer.parseInt(id);			
		} catch (Exception e) {
			return null;
		}
		
		List<String> lista = listaDeRecursosPorNo.get(idInt);
		
		if(lista == null){
			return null;
		}
		
		List<Recurso> listaRecursos = new ArrayList<Recurso>();
		
		for(String str : lista){
			listaRecursos.add(new Recurso(str));
		}
		
		return listaRecursos;
		
	}
	

}
