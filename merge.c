#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100000
int main()
{
 
    srand(time(0));
    while(1)
    {
      int i,n;
      int a[SIZE];
    clock_t start,end;
    double time_taken;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
    }
    start=clock();
   
      merge(a,0,n-1);
      end=clock();
      //printf("\nSorted array elements are\n");
      //for(int i=0;i<n;i++)
   // {
       // printf("%d",a[i]);
    //}
      time_taken=(end-start)/(double)CLOCKS_PER_SEC*1000;
      printf("\nTime taken for sorting %d elements is %lf\n",n,time_taken);
    }
        
    return 0;
    
}



void merge(int a[],int low,int high)
{
    if(low<high)
    {
       int mid;
        mid=(low+high)/2;
        merge(a,low,mid);
        merge(a,mid+1,high);
        mergef(a,low,mid,high);
    }
   
}
void mergef(int a[],int low,int mid,int high)
{
    int c[SIZE],i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=a[j++];
        }
    }
   
    while(i<=mid)
    {
        c[k++]=a[i++];
    }
    while(j<=high)
    {
        c[k++]=a[j++];
       
    }
    for(i=low;i<=high;i++)
    {
        a[i]=c[i];
    }
}

