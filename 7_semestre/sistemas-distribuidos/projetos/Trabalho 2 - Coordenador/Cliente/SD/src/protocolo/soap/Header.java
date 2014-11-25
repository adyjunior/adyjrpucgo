package protocolo.soap;

import com.thoughtworks.xstream.annotations.XStreamAlias;

public class Header {
	
	@XStreamAlias(value="n:tipo")
	private Tipo tipo;
	
	public Header() {
		tipo = new Tipo();
	}
	
	private Object readResolve() {
		return this;
	}

	public Tipo getTipo() {
		return tipo;
	}

	public void setTipo(Tipo tipo) {
		this.tipo = tipo;
	}
	
}
