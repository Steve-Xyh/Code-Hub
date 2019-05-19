abstract class Father {
    public abstract void speak();
    public abstract void run();
    public Father(){
        System.out.println("*****Father类构造方法*****");
    }
}



class Dog extends Father{
  public void speak(){
    System.out.println("狗的声音:汪、汪！");
  }
  public void run(){
    System.out.println("狗用四肢跑步");
  }
  public Dog(){
    System.out.println("*****Dog类构造方法*****");
  }
}
class Person extends Father{
  public void speak(){
    System.out.println("人们见面时经常说:您好！");
  }
  public void run(){
    System.out.println("人用两腿跑步");
  }
  public Person(){
    System.out.println("*****Person类构造方法*****");
  }
}

class Bird extends Father{
  public void speak(){
    System.out.println("鸟的声音:叽叽喳喳！");
  }
  public void run(){
    System.out.println("鸟用翅膀飞翔");
  }
  public Bird(){
    System.out.println("*****Bird类构造方法*****");
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
