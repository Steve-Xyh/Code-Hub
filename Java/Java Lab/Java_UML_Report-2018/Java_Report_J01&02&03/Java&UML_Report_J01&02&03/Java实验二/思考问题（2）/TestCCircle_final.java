class CCircle   {
    final double pi = 3.14159;    
    double radius;
    double getRadius(){
      return radius;
    } 
    double getSquare(){
      return pi*radius*radius;
    }
    void setCircle(double r){     
        //pi=p;
        radius=r;   
   }
}
public class TestCCircle_final{
   public static void main(String args[])   {
      CCircle cir1=new CCircle();   
      cir1.setCircle(2.0);
      System.out.println("radius="+cir1.getRadius());
      System.out.println("square="+cir1.getSquare()); 
   }
}
