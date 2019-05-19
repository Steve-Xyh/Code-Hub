package MainPackage;

class ParentClass{
	int value1;
	int value2;

	public ParentClass(int value1,int value2){
		this.value1=value1;
		this.value2=value2;

		System.out.println("value1=\t"+value1);
		System.out.println("value2=\t"+value2);	
	}
}

public class SubClass extends ParentClass{
	public SubClass(int value1,int value2){
		super(value1,value2);
	}
}
