
package protocolo.soap;

import java.net.InetAddress;
import java.net.UnknownHostException;

import com.thoughtworks.xstream.XStream;

import coordenador.Coordenador;

public class Protocolo {
	
	private XStream xStream;
	
	
	public Protocolo() {
		xStream = new XStream();
		xStream.processAnnotations(Envelope.class);	
	}
	
	public void getRequestXml(){
		
/*		xStream.alias("req:Envelope", Envelope.class);		
		xStream.aliasAttribute(Envelope.class, "xmlns", "xmlns:Envelope");
		xStream.aliasAttribute(Envelope.class, "encodingStyle", "req:encodingStyle");
		xStream.alias("req:Header", envelope.getHeader().getClass());
		xStream.alias("req:Body", Body.class);
		
		xStream.alias("m:Msg", Msg.class);
		xStream.aliasAttribute(Msg.class, "xmlns", "xmlns:Msg");
		xStream.aliasAttribute(Msg.class, "mustUnderstand", "req:mustUnderstand");*/
		
		//xStream.processAnnotations(Envelope.class);		
		//return xStream.toXML(envelope);
	}
	
	public Envelope getResponseXml(String xml){
		Object envelope = null;
		
		try {
			envelope =  xStream.fromXML(xml);
		} catch (Exception e) {
			System.out.println("\nA Semantica da msg enviada pelo coordenador eh invalida.\n");
		}
		
		return (Envelope)envelope;
	}

	
	
	public String prepararXmlParaTransferenciaDeDados(String tipoRequisicao, String recurso) throws UnknownHostException{
		InetAddress inetAddress = InetAddress.getLocalHost();
		
		String hostAddress = inetAddress.getHostAddress();
		
		Envelope envelope = new Envelope();
		Header header = new Header();
		Body body = new Body();
		Tipo tipo = new Tipo();
		Dados dados = new Dados();
		
		tipo.setServico("request");
		tipo.setIp(hostAddress);
		tipo.setValor(tipoRequisicao);
		tipo.setMustUnderstand(Boolean.TRUE);
		header.setTipo(tipo);
		
		dados.setId(Coordenador.getId().toString());
		dados.setMustUnderstand(Boolean.TRUE);
		if(recurso != null){
			dados.setRecurso(recurso);			
		}
		body.setDados(dados);
		
		envelope.setHeader(header);
		envelope.setBody(body);
		
		
		return xStream.toXML(envelope);
	}
	
	public String lerCabecalho(String msg){
		String conteudo = msg;
		int index = 0, endIndex =0;	
		String codigo = null;
		String msgHttp = null;
		
		try {
			index = 8;
			index += conteudo.indexOf("HTTP/1.1 ");
			endIndex = conteudo.indexOf(" ", index+1);
			codigo = conteudo.substring(index, endIndex);
			
			index = endIndex + 1;
			endIndex = conteudo.indexOf("\n", index);
			msgHttp = conteudo.substring(index, endIndex);
			
			index = conteudo.indexOf("version");
			endIndex = 2;
			endIndex += conteudo.indexOf(">\n", index);
			
			conteudo = conteudo.substring(endIndex);
			
		} catch (Exception e) {
		}
		
		System.out.println("\nCoordenador retornou o codigo ["+codigo+" ] com a mensagem [ "+msgHttp+" ] realizando o servico:");
		
		return conteudo;
	}
	
	
	
	public String prepararCabecalhoHttp(){
		StringBuilder cabecalho = new StringBuilder();
		
		cabecalho.append("POST /Reservations HTTP/1.1\n");
		cabecalho.append("Host: 192.168.0.134:5000\n");
		cabecalho.append("Content-Type: application/soap+xml; charset=\"utf-8\"\n");
		cabecalho.append("Content-Length: nnnn\n\n");
		cabecalho.append("<?xml version='1.0' ?>\n");
		
		return cabecalho.toString();
	}
	
	public void prepararXmlParaInformarExcecao(){
		
	}
	

}
