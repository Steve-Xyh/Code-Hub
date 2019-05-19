interface Speakable{
  public void speak();
}
interface Runner{
  public void run();
}
class Dog implements Speakable,Runner{
  public void speak(){
    System.out.println("��������:��������");
  }
  public void run(){
    System.out.println("������֫�ܲ�");
  }
}
class Person implements Speakable,Runner{
  public void speak(){
    System.out.println("���Ǽ���ʱ����˵:���ã�");
  }
  public void run(){
    System.out.println("���������ܲ�");
  }
}

class Bird implements Speakable,Runner{
  public void speak(){
    System.out.println("�������:ߴߴ������");
  }
  public void run(){
    System.out.println("���ó�����");
  }
}

public class TestInterface{
  public static void main(String[] args) {
    Dog d=new Dog();
    d.speak(); d.run();
    Person p=new Person();
    p.speak();  p.run();
    Bird b=new Bird();
    b.speak();  b.run();
  }
}
