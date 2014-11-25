package util;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Uteis {
	
	public static String dateToStr(Date data){
		SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy - HH:mm:ss");
		
		try {
			return sdf.format(data);
		} catch (Exception e) {
			System.out.println("Erro na conversao de data");
		}
		return null;
	}
	
	public static String dateToStr(Date data, String padrao){
		SimpleDateFormat sdf = new SimpleDateFormat(padrao);
		
		try {
			return sdf.format(data);
		} catch (Exception e) {
		}
		return null;
		
	}
	
}
