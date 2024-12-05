// Online C compiler to run C program online
#include <stdio.h>
#define max 50

int arr[max], n=0;

//LINEAR SEARCH 
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

//BINARY SEARCH 
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


// FIBONACCI SEARCH 
void  fibonacciSearch(int fib1, int fib2, int fibM,  int target) {
    int offset = -1;
    while (fibM > 1) {
        int i = (offset + fib1 < n) ? (offset + fib1) : n - 1;

        if (arr[i] < target) {
            fibM = fib2;
            fib2 = fib1;
            fib1 = fibM - fib2;
            offset = i;
        } 
        else if (arr[i] > target) {
            fibM = fib1;
            fib2 = fib2 - fib1;
            fib1 = fibM - fib2;
        } 
        else {
            printf("Value %d is found at index %d", target, i);
            return;  // Found
        }
    }

    // Check the last element
    if (fib2 && arr[offset + 1] == target) {
        printf("Value %d is found at index %d", target, offset+1);
        return;
    }
    printf("Value %d is not found in the array", target);
    // Not found
}
void fibonacci( int val) {
    int fib1 = 0, fib2 = 1, fibM = fib1 + fib2;
    while (fibM < n) {
        fib1 = fib2;
        fib2 = fibM;
        fibM = fib1 + fib2;
    }
    fibonacciSearch(fib1, fib2, fibM, val );
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
    //linearSearch(val);
    //binarySearch(val);
    //fibonacci(val);
    return 0;
}
