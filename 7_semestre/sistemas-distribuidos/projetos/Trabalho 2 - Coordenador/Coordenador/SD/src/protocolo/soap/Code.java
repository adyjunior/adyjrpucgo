package protocolo.soap;


import com.thoughtworks.xstream.annotations.XStreamAlias;

public class Code {
	
	@XStreamAlias(value="env:Value")
	private String value;
	
	public Code() {
	}
	
	private Object readResolve() {
           return this;
    }

	public String getValue() {
		return value;
	}

	public void setValue(String value) {
		this.value = value;
	}

}
