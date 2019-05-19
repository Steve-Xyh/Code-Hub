class Course{
	double score;
	double credit;
	
	public Course(double s,double c){
		score=s;
		credit=c;
	}
}

class GPATransfer{
	public static double transfer(double n){
		if(n>=85)return 4.0;
		else if(n>=75)return 3.0;
		else if(n>=60)return 2.0;
		else if(n>=45)return 1.0;
		else return 0;
	}

	public static double getGPA(Course a[]){
		double sumCredit=0;
		double sum=0;

		for(int i=0;i<3;i++){
			sumCredit+=a[i].credit;
			sum+=a[i].credit*a[i].score;
		}

		return transfer(1.0*sum/sumCredit);
	}

	public static void main(String args[]){
		Course[] a=new Course[3];

		
		a[0]=new Course(71.5,4);
		a[1]=new Course(80.4,3.5);
		a[2]=new Course(95.5,3);

		System.out.println("GPA=\t"+getGPA(a));
	}
}