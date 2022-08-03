#include<stdio.h>
int d[10][10],cost[10][10],i,j,k,n;
int min(int,int);
void floyd();
void main()
{
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    floyd();
    printf("Distance matrix is\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
             printf("%d\t",d[i][j]);
        }
        printf("\n");

    }
}
void floyd()
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            d[i][j]=cost[i][j];
        }


    }
    for(k=1;k<=n;k++)

      for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }


}
int min(int x,int y)
{
    if(x<y)
    {
        return x;
    }
    else
    {
        return y;
    }

}

