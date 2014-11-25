package principal;


import com.thoughtworks.xstream.XStream;

import protocolo.Body;
import protocolo.Dados;
import protocolo.Envelope;


public class Fibonacci {
	
	private XStream xStream;
	
	public Fibonacci() {
		xStream = new XStream();
		xStream.processAnnotations(Envelope.class);	
	}
	
	public String prepararXmlParaTransferenciaDeDados(String numero) {
		
		Envelope envelope = new Envelope();
		Body body = new Body();

		Dados dados = new Dados();
		dados.setNumero(numero);
		
		body.setDados(dados);
		envelope.setBody(body);
		
		xStream.processAnnotations(Envelope.class);
		return xStream.toXML(envelope);
	}
	
	
	public String tratarRequisicao(String msg) throws Exception{
		String retorno = null;
		Envelope envelope = getResponse(msg);		
		
		if(envelope != null){
			if(envelope.getBody() != null){
				Dados dados = envelope.getBody().getDados();
				
				if(dados != null){
					String resultato = dados.getResultado();
					System.out.println("Resultado eh: "+resultato);
				}
			}
		}
		
		retorno = prepararXmlParaTransferenciaDeDados(retorno);
		return retorno;
	}
	
	
	public Envelope getResponse(String xml){
		
		Object envelope =  xStream.fromXML(xml);
		
		return (Envelope)envelope;
	}
	
	
}
