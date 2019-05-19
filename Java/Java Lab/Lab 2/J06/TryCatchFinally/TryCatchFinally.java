public class TryCatchFinally{
	public static void main(String[] args){

		String str[]={"123","12323","5324","132443","abcde"};

    	for(int i=0;i<str.length ;i++){
			try {
				int n=Integer.parseInt(str[i]);
				System.out.println("数字为:\t"+n);
			}
			catch(NumberFormatException exc){
				System.out.println("数字格式错误");
			}
			catch(ArrayIndexOutOfBoundsException exc){
				System.out.println("No matching element found.");
			}
			finally{
				System.out.println("Finally巳执行");
			}
    	}
	}
}