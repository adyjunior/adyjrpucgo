
package protocolo.soap;

import java.net.InetAddress;
import java.util.List;

import util.Uteis;

import com.thoughtworks.xstream.XStream;

import coordenador.Coordenador;

public class Protocolo {
	
	private XStream xStream;
	
	public Protocolo() {
		xStream = new XStream();
		xStream.processAnnotations(Envelope.class);	}
	
	public void getRequestXml(){
		
/*		xStream.alias("req:Envelope", Envelope.class);		
		xStream.aliasAttribute(Envelope.class, "xmlns", "xmlns:Envelope");
		xStream.aliasAttribute(Envelope.class, "encodingStyle", "req:encodingStyle");
		xStream.alias("req:Header", envelope.getHeader().getClass());
		xStream.alias("req:Body", Body.class);
		
		xStream.alias("m:Msg", Msg.class);
		xStream.aliasAttribute(Msg.class, "xmlns", "xmlns:Msg");
		xStream.aliasAttribute(Msg.class, "mustUnderstand", "req:mustUnderstand");*/
		
				
		//return xStream.toXML(envelope);
	}
	
	public Envelope getResponseXml(String xml) throws Exception{
		Object envelope = null;
		try {
			envelope = xStream.fromXML(xml);
			
		} catch (Exception e) {
			String msgErro = "A semantica da msg enviada ao coordenador eh Invalida";
			System.err.println(msgErro);			
			throw new Exception(msgErro);
		}
		
		return (Envelope)envelope;
	}

	
	public String prepararXmlParaTransferenciaDeDados(String tipoRequisicao, Boolean permissaoRecurso, String recurso, List<Recurso> listaRecursos) throws Exception{
		InetAddress inetAddress = InetAddress.getLocalHost();
		
		String hostAddress = inetAddress.getHostAddress();
		
		Envelope envelope = new Envelope();
		Header header = new Header();
		Body body = new Body();
		Tipo tipo = new Tipo();
		Dados dados = new Dados();
		
		tipo.setServico("response");
		tipo.setIp(hostAddress);
		tipo.setValor(tipoRequisicao);
		tipo.setMustUnderstand(Boolean.TRUE);
		header.setTipo(tipo);
		
		dados.setId("1");
		if("atualizar".equals(tipoRequisicao)){
			dados.setTempo(Uteis.dateToStr(Coordenador.getTempo()));
			dados.setListaRecursos(listaRecursos);
		}else{
			dados.setRecurso(recurso);
			dados.setPermissaoRecurso(permissaoRecurso);
		}
		body.setDados(dados);
		
		envelope.setHeader(header);
		envelope.setBody(body);
		
		xStream.processAnnotations(Envelope.class);
		return xStream.toXML(envelope);
	}
	
	public String prepararXmlParaInformarExcecao(String recurso, String codigoErro, String msgErro) throws Exception{
		InetAddress inetAddress = InetAddress.getLocalHost();
		
		String hostAddress = inetAddress.getHostAddress();
		
		Envelope envelope = new Envelope();
		Header header = new Header();
		Tipo tipo = new Tipo();
		Body body = new Body();
		Fault fault = new Fault();
		Code code = new Code();
		Reason reason = new Reason();
		
		tipo.setServico("response");
		tipo.setIp(hostAddress);
		tipo.setValor("excecao");
		tipo.setMustUnderstand(Boolean.TRUE);
		header.setTipo(tipo);
		
		code.setValue(codigoErro);
		reason.setText(msgErro);
		if(recurso != null){
			reason.setRecurso(recurso);			
		}
		//detail.setMessage("O Recurso "+recurso+" foi procurado na lista de recursos do coordenador, mais nao foi encontrado.");
		
		fault.setCode(code);
		fault.setReason(reason);
		
		body.setFault(fault);
		envelope.setHeader(header);
		envelope.setBody(body);
		
		xStream.processAnnotations(Envelope.class);
		return xStream.toXML(envelope);		
	}
	
	public String lerCabecalho(String msg){
		String conteudo = msg;
		int index = 0, endIndex =0;	
		String metodo = null;
		String host = null;
		String tipoAplicacao = null;
		
		try {
			endIndex = conteudo.indexOf("/");
			metodo = conteudo.substring(0, endIndex);
			
			index = 5;
			index += conteudo.indexOf("Host:");			
			endIndex = conteudo.indexOf(":", index);
			host = conteudo.substring(index, endIndex);
			
			index = 12;
			index += conteudo.indexOf("application/");
			endIndex = conteudo.indexOf(";", index);
			tipoAplicacao = conteudo.substring(index, endIndex);
			
			index = conteudo.indexOf("version");
			endIndex = 2;
			endIndex += conteudo.indexOf(">\n", index);
			
			conteudo = conteudo.substring(endIndex);
			
		} catch (Exception e) {
		}
		
		System.out.println("Uma aplicacao usando "+tipoAplicacao+" fez uma requisicao com metodo "+metodo+"do protocolo HTTP :");
		
		return conteudo;
	}
	
	public String prepararCabecalhoHttp(String codigo, String msgErro){
		StringBuilder cabecalho = new StringBuilder();
		
		if(msgErro == null || msgErro.length() == 0){
			cabecalho.append("HTTP/1.1 "+codigo+" OK\n");
		}else{
			cabecalho.append("HTTP/1.1 "+codigo+" "+msgErro+"\n");
		}
		
		cabecalho.append("Content-Type: application/soap+xml; charset=\"utf-8\"\n");
		cabecalho.append("Content-Length: nnnn\n\n");
		
		cabecalho.append("<?xml version='1.0' ?>\n");
		
		return cabecalho.toString();
	}
	
	

}
