 interface Vehicle{
 	public void start(double speed);
 	public void stop(double speed);
 }

 class Bike implements Vehicle{
 	double speed;

 	public void start(double speed){
 		this.speed=speed;
 		System.out.println("自行车启动,速度为"+this.speed);
 	}

 	public void stop(double speed){
 		System.out.println("自行车停止,初速度为"+this.speed);
 	}
 }

 class Bus implements Vehicle{
 	double speed;

 	public void start(double speed){
 		this.speed=speed;
 		System.out.println("公交车启动,速度为"+this.speed);
 	}

 	public void stop(double speed){
 		System.out.println("公交车停止,初速度为"+this.speed);
 	}
 }

 public class interfaceDemo{
 	public static void main(String args[]){
 		Bike bk=new Bike();
 		Bus bs=new Bus();

 		bk.start(10);
 		bs.start(50);

 		bk.stop(10);
 		bs.stop(50);
 	}
 }