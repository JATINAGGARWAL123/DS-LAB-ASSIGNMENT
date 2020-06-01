#include<stdio.h>

void Bubblesort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

}

int main()
{
    int arr[10],n,i;
	printf("\n Enter the size:");
    scanf("%d",&n);
    printf("\n Enter the elements\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        fflush(stdin);
    }
	Bubblesort(arr,n);
	printf("Sorted array: \n");
    for (i=0; i < n; i++)
		printf("%d ", arr[i]);
}
