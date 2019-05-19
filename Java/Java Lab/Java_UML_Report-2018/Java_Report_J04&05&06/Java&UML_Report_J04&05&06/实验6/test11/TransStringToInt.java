
public class TransStringToInt{
	public static void main(String[] args){
		String str = "Changer";
		try{
			int num = Integer.valueOf(str).intValue();
			System.out.println("Trans String To Int Success");
		}catch(NumberFormatException e){
			System.out.println(e.toString());
		}finally{
			System.out.println("Hava Done");
		}
	}
	
}