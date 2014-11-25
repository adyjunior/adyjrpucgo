package protocolo.soap;

import com.thoughtworks.xstream.annotations.XStreamAlias;
import com.thoughtworks.xstream.annotations.XStreamAsAttribute;

@XStreamAlias("env:Envelope")
public class Envelope{
		
	//private final transient String xmlVersion = "<?xml version=\"1.0\"?>";
	
	@XStreamAlias("xmlns:Envelope")
	@XStreamAsAttribute
	private String xmlns;
		
	@XStreamAlias("env:Header")
	private Header header;
	
	@XStreamAlias("env:Body")
	private Body body;
	
	
	public Envelope() {
		//header = new Header();
		//body = new Body();
		xmlns = "http://www.w3.org/2003/05/soap-envelope";
	}
	
	private Object readResolve() {
           return this;
     }	


	public Header getHeader() {
		return header;
	}


	public void setHeader(Header header) {
		this.header = header;
	}


	public Body getBody() {
		return body;
	}


	public void setBody(Body body) {
		this.body = body;
	}


/*	public String getXmlVersion() {
		return xmlVersion;
	}
*/

	public String getXmlns() {
		return xmlns;
	}
	
}



/*
REQUEST:

POST /InStock HTTP/1.1
Host: www.example.org
Content-Type: application/soap+xml; charset=utf-8
Content-Length: nnn

<?xml version="1.0"?>
<soap:Envelope
xmlns:soap="http://www.w3.org/2001/12/soap-envelope"
soap:encodingStyle="http://www.w3.org/2001/12/soap-encoding">

<soap:Body xmlns:m="http://www.example.org/stock">
  <m:GetStockPrice>
    <m:StockName>IBM</m:StockName>
  </m:GetStockPrice>
</soap:Body>

</soap:Envelope>

 
RESPONSE:

HTTP/1.1 200 OK
Content-Type: application/soap+xml; charset=utf-8
Content-Length: nnn

<?xml version="1.0"?>
<soap:Envelope
xmlns:soap="http://www.w3.org/2001/12/soap-envelope"
soap:encodingStyle="http://www.w3.org/2001/12/soap-encoding">

<soap:Body xmlns:m="http://www.example.org/stock">
  <m:GetStockPriceResponse>
    <m:Price>34.5</m:Price>
  </m:GetStockPriceResponse>
</soap:Body>

</soap:Envelope>  
  */
