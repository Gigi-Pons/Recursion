#include <iostream>

using namespace std;

void mergeSort(int a[], int start, int end);

void mergeArrays(int x[], int y[], int a[], int start, int end);

int main()
{
    //Array will be passed into mergeSort
    int a[] = {10, 4, 3, 50, 8, 6, 9, -2, 7};
    int arrSize = sizeof(a)/sizeof(a[0]);

    mergeSort(a, 0, arrSize-1);

    for(int i=0; i <= arrSize-1; i++)
        cout << a[i] << " ";

    return 0;
}

void mergeArrays(int x[], int y[], int a[], int start, int end)
{
    int mid = start + (end - start)/2;
    //Declare index for x[], y[], and a[]
    int i_x = start;
    int i_y = mid+1;
    int i_a = start;

    //Populate array a[] by first checking which number from both arrays
    //comes before the other
    while(i_x <= mid && i_y <= end)
    {
        if(x[i_x] <= y[i_y])
        {
            a[i_a] = x[i_x];
            i_a++;
            i_x++;
        }
        else 
        {
            a[i_a] = y[i_y];
            i_a++;
            i_y++;
        }
    }

    //Outside of while loop because one of the statements broke the loop.
    //New while loop to populate a[] in case there are still some values
    //in either x[] or y[]

    while(i_x <= mid)
    {
        a[i_a] = x[i_x];
        i_a++;
        i_x++;
    }

    while(i_y <= end)
    {
        a[i_a] = y[i_y];
        i_a++;
        i_y++;
    }

}

void mergeSort(int a[], int start, int end)
{
    //Base case
    if(start>=end)
        return;

    //1. Divide the array in 2
    int mid = start + (end - start)/2;
    int x[10], y[10];

    //Populate both arrays
    for(int i=0; i<=mid; i++)
        x[i] = a[i];
    for(int i=mid+1; i<=end; i++)
        y[i] = a[i];

    //2. Apply mergeSort to both halves
    mergeSort(x, start, mid); //Sorted left half of array
    mergeSort(y, mid+1, end); //Sorted right half of array

    //3. Merge sorted arrays
    mergeArrays(x, y, a, start, end);
}