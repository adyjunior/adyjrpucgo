package protocolo.soap;

import com.thoughtworks.xstream.annotations.XStreamAlias;

public class Fault {

	@XStreamAlias(value="env:Code")
	private Code code;
	
	@XStreamAlias(value="env:Reason")
	private Reason reason;
	
	
	public Fault() {
	}
	
	private Object readResolve() {
		return this;
	}

	public Code getCode() {
		return code;
	}

	public void setCode(Code code) {
		this.code = code;
	}

	public Reason getReason() {
		return reason;
	}

	public void setReason(Reason reason) {
		this.reason = reason;
	}
	
}
