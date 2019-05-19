 public class SortByIncrease {
    public static void main(String[] args) {
        int arr[]=new int[5];
        int i,j;
        arr[0]=10;
        arr[1]=20;
        arr[2]=-9;
        arr[3]=8;
        arr[4]=98;

        for(i=0;i<5;i++){
            for(j=0;j<i;j++){
                if(arr[j]>arr[i]){
                    int t;
                    t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
        }
        for(int x : arr){
            System.out.print(x+" ");
        }
    }
}
