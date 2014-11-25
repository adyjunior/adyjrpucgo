package protocolo.soap;

import com.thoughtworks.xstream.annotations.XStreamAlias;


/*
<soap:Header>
  <m:Trans xmlns:m="http://www.w3schools.com/transaction/"
  soap:mustUnderstand="1">234
  </m:Trans>
</soap:Header>
*/
@XStreamAlias(value="p:recurso")
public class Recurso {
	
	@XStreamAlias(value="p:nome")
	private String valor;
	
	public Recurso(String valor) {
		this.valor = valor;
	}
	
	private Object readResolve() {
		return this;
	}

	public String getValor() {
		return valor;
	}

	public void setValor(String valor) {
		this.valor = valor;
	}	
}
