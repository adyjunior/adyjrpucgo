package protocolo.soap;

import java.util.ArrayList;
import java.util.List;

import com.thoughtworks.xstream.annotations.XStreamAlias;
import com.thoughtworks.xstream.annotations.XStreamAsAttribute;

public class Dados {

	@XStreamAlias(value="xmlns:p")
	@XStreamAsAttribute
	private String xmlns;
	
	@XStreamAlias(value="env:mustUnderstand")
	@XStreamAsAttribute
	private Boolean mustUnderstand;
	
	@XStreamAlias(value="p:id")
	private String id;
	
	@XStreamAlias(value="p:time")
	private String tempo;
		
	@XStreamAlias(value="p:recurso")
	private String recurso;
	
	@XStreamAlias(value="p:permissaoRecurso")
	private Boolean permissaoRecurso;
	
	@XStreamAlias(value="p:listaRecursos")
	private List<Recurso> listaRecursos;

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

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getTempo() {
		return tempo;
	}

	public void setTempo(String tempo) {
		this.tempo = tempo;
	}

	public String getRecurso() {
		return recurso;
	}

	public void setRecurso(String recurso) {
		this.recurso = recurso;
	}

	public Boolean getPermissaoRecurso() {
		return permissaoRecurso;
	}

	public void setPermissaoRecurso(Boolean permissaoRecurso) {
		this.permissaoRecurso = permissaoRecurso;
	}

	public List<Recurso> getListaRecursos() {
		return listaRecursos;
	}

	public void setListaRecursos(List<Recurso> listaRecursos) {
		this.listaRecursos = listaRecursos;
	}
	
	public List<String> obterListaRecursosStr(){
		List<String> lista = new ArrayList<String>();
		
		if(listaRecursos != null){
			for(Recurso r : listaRecursos){
				lista.add(r.getValor());
			}
		}
		
		return lista;
	}

	
}
