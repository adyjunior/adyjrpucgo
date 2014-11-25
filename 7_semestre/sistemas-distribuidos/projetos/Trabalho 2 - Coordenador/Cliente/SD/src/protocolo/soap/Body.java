package protocolo.soap;


import com.thoughtworks.xstream.annotations.XStreamAlias;

public class Body {
	
	@XStreamAlias(value="p:dados")
	private Dados dados;
	
	@XStreamAlias(value="env:Fault")
	private Fault fault;
	
	public Body() {
	}
	
	private Object readResolve() {
           return this;
    }

	public Dados getDados() {
		return dados;
	}

	public void setDados(Dados dados) {
		this.dados = dados;
	}

	public Fault getFault() {
		return fault;
	}

	public void setFault(Fault fault) {
		this.fault = fault;
	}
	
}
