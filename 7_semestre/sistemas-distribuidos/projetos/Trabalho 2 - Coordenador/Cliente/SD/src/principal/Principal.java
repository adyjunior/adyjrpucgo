package principal;




import contexto.ContextoController;


public class Principal {

	public static void main(String[] args){
		
		ContextoController contextoController = ContextoController.getInstancia();
		
		try {
			contextoController.inicializacao();
		} catch (Exception e) {
			//System.err.println(e.getMessage());
		}
		
	}

}
