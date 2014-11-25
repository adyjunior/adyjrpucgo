package protocolo;


import com.thoughtworks.xstream.annotations.XStreamAlias;

public class Body {
	
	@XStreamAlias(value="p:dados")
	private Dados dados;
	
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

}
