#include <bits/stdc++.h>
using namespace std;

int BS1(int a[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (right-left)/2;
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
            return BS1(a, mid+1, right, key);
        return BS1(a, left, mid-1, key);
    }
    return -1;
}

int BS2(int a[], int n, int key)
{
    int l = 0, r = n-1;
    while (l <= r)
    {
        int m = l + (r-l)/2;
        if (a[m] == key)
            return m;
        else if (key > a[m])
            l = m+1;
        else
            r = m-1;
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
    int a[] = {5, 10, 100, 200, 199, -7, -5, 8, 4};
    int n = sizeof(a)/sizeof(a[0]);
    sort(a, a+n);
    int keys[] = {0, -89, 100, 234, -2, 4, 5};
    cout << "Array: "; show(a, n);
    cout << "USING BINARY SEARCH - RECURSION\n";
    for (int i : keys)
    {
        int pos = BS1(a, 0, n-1, i);
        if (pos!=-1)
            cout << "Phan tu co gia tri " << i << " nam o vi tri " << pos << endl;
        else
            cout << "Khong ton tai phan tu gia tri " << i << " trong mang\n";
    }

    cout << "USING BINARY SEARCH - LOOP\n";
    for (int i : keys)
    {
        int pos = BS2(a, n, i);
        if (pos!=-1)
            cout << "Phan tu co gia tri " << i << " nam o vi tri " << pos << endl;
        else
            cout << "Khong ton tai phan tu gia tri " << i << " trong mang\n";
    }
    return 0;
}
