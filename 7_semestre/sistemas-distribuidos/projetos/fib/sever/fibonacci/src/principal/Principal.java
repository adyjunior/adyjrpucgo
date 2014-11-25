package principal;



public class Principal {

	public static void main(String[] args) {		
		
		Comunicacao c = new Comunicacao();
		Fibonacci f = new Fibonacci();
		try {
			for(;;){
				c.receber(f);				
			}
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}


	}

}
