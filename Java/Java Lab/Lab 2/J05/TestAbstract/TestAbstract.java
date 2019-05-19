abstract class Animal{
  public abstract void speak();
  public abstract void run();
}

class Dog extends Animal{
  public void speak(){
    System.out.println("狗的声音:汪、汪！");
  }
  public void run(){
    System.out.println("狗用四肢跑步");
  }
}

class Person extends Animal{
  public void speak(){
    System.out.println("人们见面时经常说:您好！");
  }
  public void run(){
    System.out.println("人用两腿跑步");
  }
}

class Bird extends Animal{
  public void speak(){
    System.out.println("鸟的声音:咕咕咕咕咕咕🐦");
  }

  public void run(){
    System.out.println("鸟用两腿跑步");
  }
}

public class TestAbstract{
  public static void main(String[] args) {
    Dog d=new Dog();
    d.speak();
    d.run();

    Person p=new Person();
    p.speak();
    p.run();

    Bird b=new Bird();
    b.speak();
  }
}
