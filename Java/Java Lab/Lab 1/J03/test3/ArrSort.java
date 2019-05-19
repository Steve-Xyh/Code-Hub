public class ArrSort {

  static void sort(int a[]){
    for(int i=0;i<5;i++){
      for(int j=i;j<5;j++){
        if(a[i]>a[j]){
          a[i]^=a[j];   //换位
          a[j]^=a[i];
          a[i]^=a[j];
        }
      }
    }
  }

  static void search(int a[],int n){
    System.out.println("数值为"+n+"的下标为:");
    for(int i=0;i<5;i++){
      if(a[i]==n)System.out.println(i);
    }
  }

  public static void main(String[] args) {
    int arr[]=new int[5];
    arr[0]=10;
    arr[1]=20;
    arr[2]=-9;
    arr[3]=8;
    arr[4]=98;
    int min=0,max=0;
    for(int i=0;i<5;i++){
      if(max<arr[i])
         max=arr[i];
      if(min>arr[i])
         min=arr[i];
    }

    sort(arr);
    for(int i=0;i<5;i++)System.out.println(arr[i]+" ");    

    System.out.println("数组的最大值是:" +max);
    System.out.println("数组的最小值是:"+min);

    search(arr,8);
  }
}
