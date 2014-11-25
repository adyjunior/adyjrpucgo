package principal;


import java.net.UnknownHostException;


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
	
	public String prepararXmlParaTransferenciaDeDados(String resultado) {
		
		Envelope envelope = new Envelope();
		Body body = new Body();

		Dados dados = new Dados();
		dados.setResultado(resultado);
		
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
					String numero = dados.getNumero();
					System.out.println("Numero recebido : "+numero);
					long ret = calcularFiconacci(numero);
					retorno = Long.toString(ret);
				}
			}
		}
		
		retorno = prepararXmlParaTransferenciaDeDados(retorno);
		return retorno;
	}
	
	
	private long calcularFiconacci(String numero){
		int num = Integer.parseInt(numero);
		long retorno = 0;     // atual
		long ant = 0;   // anterior

		for (int i = 1; i <= num; i++) {

			if (i == 1) {
				retorno = 1;
				ant = 0;
			} else {
				retorno += ant;
				ant = retorno - ant;
			}
		}
		return retorno;
	}
	
	public Envelope getResponse(String xml){
		
		Object envelope =  xStream.fromXML(xml);
		
		return (Envelope)envelope;
	}
	
	
}
