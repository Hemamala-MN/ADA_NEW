#include <stdio.h>
#include<time.h>
#include<stdlib.h>
void heapify(int [], int , int );
void heapsort(int [], int );
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {

        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--) {

        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

void main()
{
    int k,a[100000];
    int n,ch;
    clock_t start,end;
    srand(time(0));
    while(1)
    {
        printf("1.for manual entry\n2.random values\n3.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of elements\n");
                    scanf("%d",&n);
                    printf("Enter the array elements\n");
                    for(k=0;k<n;k++)
                    {
                        scanf("%d",&a[k]);
                    }
                    start=clock();
                   heapsort(a,n);
                    for(long delay=0;delay<100000000;delay++);
                    end=clock();
                    printf("Sorted array is \n");
                    for(k=0;k<n;k++)
                    {
                        printf("%d\t",a[k]);
                    }
                    printf("Time taken for sorting %d elements is %lf ms\n",n,((double)(end-start)/CLOCKS_PER_SEC));
                    break;
            case 2:

                    n=1000;
            while(n<=10000)
            {
                    for(k=0;k<n;k++)
                    {
                       a[k]=(rand()%1000)+1;
                    }
                    start=clock();
                    heapsort(a,n);
                    for(long delay=0;delay<100000000;delay++);
                    end=clock();
                    printf("Time taken for sorting %d elements is %lf ms\n",n,((double)(end-start)/CLOCKS_PER_SEC));
                    n=n+1000;

            }
            break;

            case 3: exit(0);

        }
    }
}
