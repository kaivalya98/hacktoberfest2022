#include <stdio.h>
float fknapsack(int wt[],int pft [],int n ,int qty)
{
    float x[n];
    int i;
    float profit=0.0;
    for (i=0;i<n;i++)
    {
        x[i]=0;
    }
    int u = qty;
    for (i=0;i<qty;i++)
    {
        if(wt[i]<=u)
        {
            x[i]=1;
            u = u - wt[i];
        }
        else
        {
            break;
        }
    }
    if(i<n)
    {
        x[i]=(float)u/(float)wt[i];
    }
    for (i=0;i<n;i++)
    {
        profit = profit + x[i]*pft[i];
    }
    return profit;
}
int main()
{
    int wt[] = {8,15,50};
    int pft[] = {24,15,25};
    int n = sizeof(wt)/sizeof(wt[0]);
    int qty = 25;
    float max_profit = fknapsack(wt,pft,n,qty);
    printf("Maximum Profit = %f",max_profit);
    return 0;
}