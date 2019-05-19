class CCircle{
	final double pi=3.14159;    
	double radius;
	double area;

	double getRadius(){
		return radius;
	}

	double getArea(){
		return pi*radius*radius;
	}

  	void setCircle(double r, double p){     
      	//pi=p;
      	radius=r;   
   	}

   	public CCircle(double r){
   		radius=r;
   		area=getArea();
   	}
}

public class TestCCircle{
   	public static void main(String args[])   {
		CCircle cir1=new CCircle(2.0);   
		//cir1.setCircle(2.0,3.1416);
		System.out.println("radius="+cir1.getRadius()); 
		System.out.println("area="+cir1.getArea()); 	
   	}
}
