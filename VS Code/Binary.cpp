//***//二分(5*10^4/5/6)
//查找a[i]==key
int bsearch(int a[],int key)
{
    int l=0,r=n-1,tag=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]==key){
            tag=1;
            break;
        }
        else if(a[mid]<key)l=mid+1;
        else r=mid-1;
    }
    return tag;
}

//查找最小的i使得a[i]>key(>=同理)
int findmin(int a[],int key)
{
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]>key)r=mid-1; //查找a[i]>=key改为if(a[mid]>=key)
        else l=mid+1;
    }
    return r+1;                //r+1为所求
}

