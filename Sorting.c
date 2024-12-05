// Online C compiler to run C program online
#include <stdio.h>
#define max 50

int arr[max], temp[max], n=0;

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

//QUICK SORT 
void quick_sort(int low, int high)
{
    int partition_index, pivot, i, j, temp;

    if (low < high)
    {
        // Choosing the last element as pivot
        pivot = arr[high];
        i = low - 1;

        for (j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                // Swap array[i] and array[j]
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Swap pivot element with element at i+1
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        partition_index = i + 1; // that is the index for pivot
        //to left of pivot , everything is lesser , and to right everything is greater

        // Recursively sort elements before and after partition
        quick_sort(low, partition_index - 1);
        quick_sort(partition_index + 1, high);
    }
}

//MERGE SORT
void merge_sort(int arr[], int temp[], int left, int right) {
    if (left >= right) 
        return;

    int mid = left + (right - left) / 2;

    // Recursively sort the left and right halves
    merge_sort(arr, temp, left, mid);
    merge_sort(arr, temp, mid + 1, right);

    // Merge the two halves
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    // Copy remaining elements from the left half
    while (i <= mid) 
        temp[k++] = arr[i++];

    // Copy remaining elements from the right half
    while (j <= right) 
        temp[k++] = arr[j++];

    // Copy the sorted elements back to the original array
    for (i = left; i <= right; i++) 
        arr[i] = temp[i];
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
    //selectionSort();
    //quick_sort(0, n-1)
    merge_sort(arr, temp, 0, n - 1);
    for(i=0;i<n;i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
