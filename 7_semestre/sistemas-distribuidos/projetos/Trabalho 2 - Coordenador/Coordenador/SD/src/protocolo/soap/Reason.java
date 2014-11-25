package protocolo.soap;

import com.thoughtworks.xstream.annotations.XStreamAlias;

public class Reason {

	@XStreamAlias(value="env:Text")
	private String text;
	
	@XStreamAlias(value="env:recurso")
	private String recurso;
	
		
	public Reason() {
	}
	
	private Object readResolve() {
		return this;
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}

	public String getRecurso() {
		return recurso;
	}

	public void setRecurso(String recurso) {
		this.recurso = recurso;
	}

	
}
