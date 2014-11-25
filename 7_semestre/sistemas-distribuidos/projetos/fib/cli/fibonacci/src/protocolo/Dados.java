package protocolo;

import com.thoughtworks.xstream.annotations.XStreamAlias;
import com.thoughtworks.xstream.annotations.XStreamAsAttribute;

public class Dados {

	@XStreamAlias(value="xmlns:p")
	@XStreamAsAttribute
	private String xmlns;
	
	@XStreamAlias(value="env:mustUnderstand")
	@XStreamAsAttribute
	private Boolean mustUnderstand;
	
	@XStreamAlias(value="p:numero")
	private String numero;
	
	@XStreamAlias(value="p:resultado")
	private String resultado;
	
	public Dados() {
		xmlns = "http://192.168.0.131:5000/";
	}
	
	private Object readResolve() {
		return this;
	}

	public Boolean getMustUnderstand() {
		return mustUnderstand;
	}

	public void setMustUnderstand(Boolean mustUnderstand) {
		this.mustUnderstand = mustUnderstand;
	}

	public String getNumero() {
		return numero;
	}

	public void setNumero(String numero) {
		this.numero = numero;
	}

	public String getResultado() {
		return resultado;
	}

	public void setResultado(String resultado) {
		this.resultado = resultado;
	}

}
