import java.util.*;  
public class FindWhere {
    public static void main(String[] args) {
        int arr[]=new int[5];
        int i,j;
        arr[0]=10;
        arr[1]=20;
        arr[2]=-9;
        arr[3]=8;
        arr[4]=98;
        
        boolean flag = true;

        while(flag){
            boolean f = false;
            System.out.println("Please input which number you want to find");
            Scanner sc = new Scanner(System.in);
            int input = sc.nextInt();
            for(i=0;i<5;i++){
                if(arr[i] == input){
                    System.out.println("The number " + input + " is "+ i +" in arr");
                    f = true ;
                }
            }
            if(!f)
                System.out.println("We can find this number");
        }
        

    }
}
