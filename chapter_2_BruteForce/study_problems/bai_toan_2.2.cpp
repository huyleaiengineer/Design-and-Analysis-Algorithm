#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n-1; ++i)
    {
        int min_val = a[i], min_index = i;
        for (int j = i+1; j < n; ++j)
            if (a[j] < min_val)
            {
                min_val = a[j];
                min_index = j;
            }
        swap(a[i], a[min_index]);
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
    int test[] = {5, 10, 100, 200, 199, -7};
    int n = sizeof(test)/sizeof(test[0]);
    cout << "Before sorting: "; show(test, n);
    SelectionSort(test, n);
    cout << "After sorting: "; show(test, n);
     return 0;
}
