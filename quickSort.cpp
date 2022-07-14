 #include <iostream>

 using namespace std;

 void quickSort(int a[], int start, int end);
 int partition(int a[], int start, int end);

 int main()
 {
     int a[10] = {5, 6, 8, 3, 1, 0};

    quickSort(a, 0, 5);
    for(int i=0; i<=5; i++)
        cout << a[i] << " ";

     return 0;
 }

 int partition(int a[], int start, int end)
 {
     int i = start;
     int pivot = a[end];
     for(int j=start; j<=end-1; j++)
     {
         if(a[j] < pivot)
         {
             swap(a[i], a[j]);
             i++;
         }
     }

     swap(a[i], a[end]);
     return i;
 }

 void quickSort(int a[], int start, int end)
 {
     //Base case
     if(start >= end)
        return;

    int p  = partition(a, start, end);
    quickSort(a, start, p-1);
    quickSort(a, p+1, end);

 }