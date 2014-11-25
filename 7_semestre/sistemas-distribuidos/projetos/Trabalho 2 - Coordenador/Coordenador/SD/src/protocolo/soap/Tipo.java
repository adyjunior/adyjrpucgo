package protocolo.soap;

import com.thoughtworks.xstream.annotations.XStreamAlias;
import com.thoughtworks.xstream.annotations.XStreamAsAttribute;


public class Tipo {

	@XStreamAlias(value="xmlns:n")
	@XStreamAsAttribute
	private String xmlns;
	
	@XStreamAlias(value="env:mustUnderstand")
	@XStreamAsAttribute
	private Boolean mustUnderstand;
	
	@XStreamAlias(value="n:servico")
	private String servico;
	
	@XStreamAlias(value="n:ip")
	private String ip;
	
	@XStreamAlias(value="n:valor")
	private String valor;
	
	public Tipo() {
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

	public String getValor() {
		return valor;
	}

	public void setValor(String valor) {
		this.valor = valor;
	}

	public String getIp() {
		return ip;
	}

	public void setIp(String ip) {
		this.ip = ip;
	}

	public String getServico() {
		return servico;
	}

	public void setServico(String servico) {
		this.servico = servico;
	}
	
}
