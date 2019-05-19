package mainpackage;

import mainpackage.Parent;

public class Sub extends Parent{
    
    int a=60;
	int b=300;
    
	public Sub(){
        
		System.out.println("a form SubClass is "+a);
		System.out.println("b form SubClass is "+b);
	}
}