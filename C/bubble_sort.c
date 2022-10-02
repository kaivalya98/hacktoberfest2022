#include<stdio.h>
int main()
{
   int n, temp, i, j;
   printf ("Enter No of elements present in the array \n");
   scanf("%d",&n);
   int elements[n];
   printf ("Enter the elements of array \n");
   for(int i=0;i<n;i++)
    scanf("%d",&elements[i]);
   for(i=0;i<n-i;i++){
      for(j=0;j<=i;j++){
        if(elements[j]>elements[j+1]){
           temp=elements[j];
           elements[j]=elements[j+1];
           elements[j+1]=temp;
        }
      }
   }
   printf("Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %d",elements[i]);
   return 0;
}
