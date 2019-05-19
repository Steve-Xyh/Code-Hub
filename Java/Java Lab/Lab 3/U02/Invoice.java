import java.util.Date;

public class Invoice{
	public double amount;
	public Date date = new Date();
	public String customer;
	public String specification;
	public String administrator = "unspecified";
	static private int number_of_invoices=0;
	
	public Invoice(){	
		number_of_invoices++;
	}
	
	public void print() 
	{
		System.out.println("The number of invoices is "+number_of_invoices);
	}

	public static void main(String[] args) {
		for(int i=0;i<3;i++){
			Invoice a=new Invoice();
			a.print();
		}
	}
}
