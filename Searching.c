// Online C compiler to run C program online
#include <stdio.h>
#define max 50

int arr[max], n=0;

void linearSearch(int val)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==val)
        {
            printf("Required vale %d found at index %d of array.", val, i);
            return;
        }
    }
    printf("Required value %d not found in array.", val);
}
void binarySearch(int val)
{
    int beg=0, end=n-1, mid;
    while(beg <= end)
    {
        mid= (beg+end)/2;
        if(val== arr[mid])
        {
            printf("Required vale %d found at index %d of array.", val, mid);
            return;
        }
        else if(val > arr[mid])
        {
            beg=mid+1;
        }
        else if( val < arr[mid])
        {
            end=mid-1;
        }
    }
    printf("Required value %d not found in array.", val);
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
    printf("\nEnter value to be found:");
    scanf("%d", &val);
    linearSearch(val);
    binarySearch(val);
    return 0;
}
