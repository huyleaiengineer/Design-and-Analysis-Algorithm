#include <bits/stdc++.h>
using namespace std;

double euclideDistance(pair<int, int> A, pair<int, int> B)
{
    return sqrt(pow(A.first-B.first, 2)+pow(A.second-B.second, 2));
}

void closetPair(vector<pair<int, int>> p)
{
    int n = p.size();
    double minDis = DBL_MAX;
    int first = 0, last = 0;
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
        {
            double newDis = euclideDistance(p[i], p[j]);
            if (newDis < minDis){
                minDis = newDis;
                first = i;
                last = j;
            }
        }
    cout << "Closet pair of points is: (" << p[first].first << ", " << p[first].second << ") and (" << p[last].first << ", " << p[last].second << ")\n";
    cout << "Distance = " << minDis << "\n";

}

int main()
{
    vector<pair<int, int>> Pairs = {{1, 2}, {12, 3}, {-1, 5}, {4, 6}, {8, 8}, {2, 7}};
    closetPair(Pairs);
     return 0;
}
