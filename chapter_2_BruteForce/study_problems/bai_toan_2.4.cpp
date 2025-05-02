#include <bits/stdc++.h>
using namespace std;

int StringMatching(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i < n-m+1; ++i)
    {
        bool flag = true;
        for (int j = 0; j < m; ++j)
            if (text[i+j] != pattern[j])
                flag = false;
        if (flag)
            return i;
    }
    return -1;
}


int main()
{
    string text[] = {"Fanstastic Beast", "Manificent", "Significant", "Marvelous"};
    string pattern[] = {"Beast", "nt"};
    for (string t : text)
    {
        for (string p : pattern)
        {
            int pos = StringMatching(t, p);
            if (pos == -1)
                cout << "Not exsit pattern \"" << p << "\" in text \"" << t << "\"\n";
            else
                 cout << "Pattern \"" << p << "\" is at position " << pos << " in text \"" << t << "\"\n";
        }
    }
     return 0;
}
