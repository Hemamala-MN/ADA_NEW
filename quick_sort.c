#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; 
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        
        if (a[j] < pivot)  
        {  
            i++;
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  
  

void quick(int a[], int start, int end) 
{  
    if (start < end)  
    {  
        int p = partition(a, start, end); 
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  
void printarray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d      ",a[i]);
    }
}
int main()  
{  
    while(1)
    {
    int i,n;
    double time_taken;
    clock_t start,end;
    srand(time(0));
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    start=clock(); 
    quick(a, 0, n - 1);  
    end=clock();
    printf("The sorted array\n");
    printarray(a,n);
    time_taken=(end-start)/(double)CLOCKS_PER_SEC*1000;
    printf("\nTime taken for sorting %d elements is %lf\n",n,time_taken);
    }
   return 0;  
} 
