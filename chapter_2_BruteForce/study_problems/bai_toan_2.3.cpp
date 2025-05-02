#include <bits/stdc++.h>
using namespace std;

int SequentialSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; ++i)
    {
       if (a[i] == key)
        return i;
    }
    return -1;
}

void show(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl;
}

int main()
{
    int test[] = {5, 10, 100, 200, 199, -7};
    int n = sizeof(test)/sizeof(test[0]);
    int keys[] = {5, -7, 40, 199, 36};
    cout << "Array: "; show(test, n);
    for (int i : keys)
    {
        int pos = SequentialSearch(test, n, i);
        if (pos == -1)
            cout << i << " is not exist in the array\n";
        else
            cout << "Position of " << i << " in the array (first position if the array have duplicated values) is " << pos << endl;
    }
     return 0;
}
