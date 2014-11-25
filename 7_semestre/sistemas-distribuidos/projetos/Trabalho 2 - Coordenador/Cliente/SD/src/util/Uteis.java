package util;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Uteis {

	
	public static Integer gerarValor(){		
		return	(int)(Math.random()*3000);
	}
	
	public static String dateToStr(Date data) throws Exception{
		SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd/MM/yyyy - HH:mm:ss");
		
		try {
			return simpleDateFormat.format(data);
		} catch (Exception e) {
			throw new Exception("Erro na conversao de data");
		}
	}
	
	public static Date strToDate(String str) throws Exception{
		SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd/MM/yyyy - HH:mm:ss");
		
		try {
			return simpleDateFormat.parse(str);
		} catch (Exception e) {
			throw new Exception("Erro na conversao de data");
		}
	}
	
}
