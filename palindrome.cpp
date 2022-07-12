#include <iostream>

using namespace std;

bool checkPal(int a[], int s, int e);

int main()
{
    int a[6] = {1, 2, 3, 2, 1, 9};

    cout << checkPal(a, 0, 5);

    return 0;
}

bool checkPal(int a[], int s, int e)
{
    if(s > e)
        return true;

    if(a[s] == a[e])
        return checkPal(a, s+1, e-1);
    else   
        return false;
}