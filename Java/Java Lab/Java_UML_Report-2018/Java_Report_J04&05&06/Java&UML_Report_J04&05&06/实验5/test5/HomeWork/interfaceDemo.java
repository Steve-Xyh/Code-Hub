interface Vehicle{
	public void start(int n);
	public void stop(int n);
}


class Bike implements Vehicle{
	public void start(int n){
		System.out.println("The Bike will start "+n+" hours later");
		
	}
	public void stop(int n){
		System.out.println("The Bike will start "+n+" hours later");

	}
}

class Bus implements Vehicle{
	public void start (int n ){
		System.out.println("The Bus will start "+n+" hours later");
	}
	public void stop (int n ){
		System.out.println("The Bus will start "+n+" hours later");
	}
}

public class interfaceDemo{
	public static void main(String[] args) {
		Bike a =new Bike();
		Bus b = new Bus();
		a.start(5);
		a.stop(6);
		b.start(7);
		b.stop(8);
	}
}