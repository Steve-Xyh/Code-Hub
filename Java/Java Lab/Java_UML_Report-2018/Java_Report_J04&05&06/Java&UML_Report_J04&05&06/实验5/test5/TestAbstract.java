abstract class Father {
    public abstract void speak();
    public abstract void run();
    public Father(){
        System.out.println("*****Father�๹�췽��*****");
    }
}



class Dog extends Father{
  public void speak(){
    System.out.println("��������:��������");
  }
  public void run(){
    System.out.println("������֫�ܲ�");
  }
  public Dog(){
    System.out.println("*****Dog�๹�췽��*****");
  }
}
class Person extends Father{
  public void speak(){
    System.out.println("���Ǽ���ʱ����˵:���ã�");
  }
  public void run(){
    System.out.println("���������ܲ�");
  }
  public Person(){
    System.out.println("*****Person�๹�췽��*****");
  }
}

class Bird extends Father{
  public void speak(){
    System.out.println("�������:ߴߴ������");
  }
  public void run(){
    System.out.println("���ó�����");
  }
  public Bird(){
    System.out.println("*****Bird�๹�췽��*****");
  }
}

public class TestAbstract{
  public static void main(String[] args) {
    Father d=new Dog();
    d.speak(); d.run();
    Father p=new Person();
    p.speak();  p.run();
    Father b=new Bird();
    b.speak();  b.run();
  }
}
