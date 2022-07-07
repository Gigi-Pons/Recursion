#include <iostream>

using namespace std;

int firstIndex(int a[], int n, int x, int i);

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    cout << firstIndex(a, 5, 4, 0);

    return 0;
}

int firstIndex(int a[], int n, int x, int i)
{
    if(i==n)
        return -1;

    if(a[i] == x)
        return i;
    else   
        return firstIndex(a, n, x, i+1);
}