package p2;
import p1.DefiPackage;

public class TestPackage {
	public void display(){
		System.out.println("in package p2");
	}


	public static void main(String[] args) {
		DefiPackage t=new DefiPackage();
		t.display();
	}
}
