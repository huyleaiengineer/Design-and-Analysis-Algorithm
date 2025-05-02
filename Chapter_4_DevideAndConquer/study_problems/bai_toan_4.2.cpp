#include <bits/stdc++.h>
using namespace std;

int Partition(int a[], int left, int right)
{
    int x = a[right], i = left-1;
    for (int j = left; j < right; ++j)
    {
        if (a[j] <= x)
        {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[right]);
    return i+1;
}

void QuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivot = Partition(a, left, right);
        QuickSort(a, left, pivot-1);
        QuickSort(a, pivot+1, right);
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
    QuickSort(test, 0, n-1);
    cout << "After sorting: "; show(test, n);
     return 0;
}
