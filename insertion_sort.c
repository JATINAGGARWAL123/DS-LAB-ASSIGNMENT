#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[10],i,j,temp,n;
    printf("Enter n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
    for(i=0;i<n;i++)
     printf("%d   ",arr[i]);
}
