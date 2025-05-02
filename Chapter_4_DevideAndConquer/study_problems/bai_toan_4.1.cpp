#include <bits/stdc++.h>
using namespace std;

void show(int a[], int n)
{
    for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
    cout << '\n';
}

void Merge(int a[], int left, int mid, int right)
{
    int n1 = mid-left+1;
    int n2 = right-mid;
    int L[n1+1], R[n2+1];
    for (int i = 0; i < n1; ++i)
        L[i] = a[left+i];
    for (int i = 0; i < n2; ++i)
        R[i] = a[mid+1+i];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = left; k <= right; ++k)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            ++i;
        }else{
            a[k] = R[j];
            ++j;
        }
    }
}

void MergeSort(int a[], int left, int right)
{
   if (left < right)
   {
       int mid = (right+left)/2;
       MergeSort(a, left, mid);
       MergeSort(a, mid+1, right);
       Merge(a, left, mid, right);
   }
}


int main()
{
    int test[] = {5, 10, 100, 200, 199, -7, -5, 8, 4};
    int n = sizeof(test)/sizeof(test[0]);
    cout << "Before sorting: "; show(test, n);
    MergeSort(test, 0, n-1);
    cout << "After sorting: "; show(test, n);
     return 0;
}
