// Online C compiler to run C program online
#include <stdio.h>
#define max 50

int arr[max], n=0;

//INSERTON SORT 
void insertionSort()
{
    int i, j, temp;
    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=arr[i];
        while(temp< arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

//SELECTION SORT 
void swap(int j , int k)
{
    int temp=arr[j];
    arr[j]=arr[k];
    arr[k]=temp;
}
void selectionSort()
{
    int i,j,small;
    for(i=0;i<n;i++)
    {   
        small=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[small])
                small=j;
        }
        swap(i, small);
    }
}

int main()
{
    int i, val;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements of array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    // insertionSort();
    selectionSort();
    for(i=0;i<n;i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
