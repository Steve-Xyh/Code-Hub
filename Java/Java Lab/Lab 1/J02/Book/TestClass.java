class Book{
	String Title;
	String Pdate;

	int Words;
	int year,month,day;

	double price(){
		double index1=1.2;
		double index2=1.18;
		double index;

		if(month>=1&&month<=6)index=index1;
		else index=index2;

		return Words*35*index/1000;
	}

	void getPdate(int y,int m,int d){
		Pdate=y+"-"+m+"-"+d;
	}

	public Book(String t,int y,int m,int d,int w){
		Title=t;
		year=y;
		month=m;
		day=d;
		Words=w;
		getPdate(y,m,d);
	}
}

public class TestClass{
	public static void main(String args[]){
		Book b1=new Book("Book 1",2019,4,13,10000);
		System.out.println("Title:\t"+b1.Title);
		System.out.println("Date :\t"+b1.Pdate);
		System.out.println("Words:\t"+b1.Words);
		System.out.println("Price:\t"+b1.price());
	}
}