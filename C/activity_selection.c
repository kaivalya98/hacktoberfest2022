#include <stdio.h>
void activity_selection(int start[],int end[], int n)
{
    int i=0,j;
    printf("Selected jobs:-\n");
    printf("%d\t",i);
    for(j=1;j<n;j++)
    {
        if(end[i]<=start[j])
        {
            printf("%d\t",j);
            i=j;
        }
    }
}
int main()
{
    int start[]= {10,12,20,25,34,40,47,32,51};
    int end[] = {20,25,30,32,40,47,50,40,70};
    int n = sizeof(start)/sizeof(start[0]);
    activity_selection(start,end,n);
    return 0;
}