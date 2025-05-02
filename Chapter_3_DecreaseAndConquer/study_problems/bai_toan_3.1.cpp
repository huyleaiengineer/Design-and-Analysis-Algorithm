#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = a[i], key_index = i-1;
        while (key_index > -1 && a[key_index]>key)
        {
            a[key_index+1]=a[key_index];
            --key_index;
        }
        a[key_index+1]=key;
    }
}

void show(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl;
}

int main()
{
    int test[] = {5, 10, 100, 200, 199, -7, -5, 8, 4};
    int n = sizeof(test)/sizeof(test[0]);
    cout << "Before sorting: "; show(test, n);
    InsertionSort(test, n);
    cout << "After sorting: "; show(test, n);
     return 0;
}
