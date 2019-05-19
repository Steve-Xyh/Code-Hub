public class GPA{

	public static float getGPA(double[][] A){
		for(int i=0; i<A.length; i++){
            if(A[i][1] >= 85.0){
                A[i][1] = 4.0;
            }
            else if(A[i][1] >= 75.0){
                A[i][1] = 3.0;
            }
            else if(A[i][1] >= 60.0){
                A[i][1] = 2.0;
            }
            else if(A[i][1] >= 45.0){
                A[i][1] = 1.0;
            }
            else{
                A[i][1] = 0.0;
            }
		}
		float temp1 = 0.0f, temp2 = 0.0f;
		for(int i=0; i<A.length; i++){
			temp1 += A[i][0]*A[i][1];
			temp2 += A[i][1];
		}
		return (temp1/temp2);
	}

    	public static void main(String[] args){

		double[][] stduent1 = {{4.0,71.5},{3.5,80.4},{3.0,95.5}};
		double[][] stduent2 = {{4.0,78.5},{3.0,54.5},{3.0,60.5}};
		double[][] stduent3 = {{4.0,88.5},{3.5,92.5},{3.0,71.5}};
		
		System.out.println("Student Zhang: " + getGPA(stduent1));
		System.out.println("Student   Li : " + getGPA(stduent2));
		System.out.println("Student Zhao : " + getGPA(stduent3));
		
	}
	
}