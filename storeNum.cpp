#include <iostream>
#include <vector>

using namespace std;

void saveInV(int a[], int n, int x, int i, vector<int> &v);
int saveInA(int a[], int n, int x, int o[], int j);

int main()
{
    vector<int> v;
    int a[] = {5, 5, 6, 5, 6, 7};
    int o[5];

    saveInV(a, 5, 5, 0, v);

    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";

    cout << endl;
    int count = saveInA(a, 5, 5, o, 0);
    for(int i=0; i<count; i++)
    {
        cout << o[i] << " ";
    }

    return 0;
}

int saveInA(int a[], int n, int x, int o[], int j)
{
    if(n==-1)
        return 0;

    if(a[n-1] == x)
    {
        o[j] = n-1;
        return 1 + saveInA(a, n-1, x, o, j+1);
    }
    else    
        return saveInA(a, n-1, x, o, j);

}

void saveInV(int a[], int n, int x, int i, vector<int> &v)
{
    //base case
    if(i == n) //we reached the end of array
        return;

    //storing in vector if value is found in array
    if(a[i] == x)
        v.push_back(i);
    
    //make next recursive call.  Advance to the next index in array
    saveInV(a, n, x, i+1, v);
}