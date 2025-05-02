#include <bits/stdc++.h>
using namespace std;

long long sum(int n)
{
    long long sum = 1;
    for (int i = 2; i <= n; ++i)
        sum += i*i;
    return sum;
}

long long sum2(int n)
{
    return (n*(n+1)*(2*n+1))/6;
}

int main()
{
    int test[] = {5, 10, 100, 200};
    for (int i : test)
        cout << " n = " << i << ", sum = " << sum(i) << '\n';
    cout << "Use fast fomula\n";
     for (int i : test)
        cout << " n = " << i << ", sum = " << sum2(i) << '\n';
     return 0;
}
