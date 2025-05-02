#include <bits/stdc++.h>
using namespace std;


void readFile(string s, int graph[15][15], int &n);
void showPath(vector<int> path, int n);
void showMatrix(int graph[15][15], int n);

int costCalculate(int graph[15][15], vector<int> path, int n)
{
    int cost = 0;
    for (int i = 0; i < n-1; ++i)
        cost += graph[path[i]][path[i+1]];
    cost += graph[path[n-1]][path[0]];
    return cost;
}

pair<int, vector<int>> tsp(int graph[15][15], int n)
{
    vector<int> path(n), best_path(n);
    generate(path.begin(), path.end(), [dem=0] ()mutable {return dem++;});
    best_path = path;
    int cost;
    int best_cost = INT_MAX;
    do{
        cost = costCalculate(graph, path, n);
        if (cost < best_cost)
        {
            best_cost = cost;
            best_path = path;
        }
    }while(next_permutation(path.begin()+1, path.end()));

    return {best_cost, best_path};
}

int main()
{
    int graph[15][15], n;
    string s = "tsp.txt";
    readFile(s, graph, n);
    cout << "Adjancent Matrix:\n";
    showMatrix(graph, n);
    pair<int, vector<int>> res = tsp(graph, n);
    cout << "Best path is "; showPath(res.second, n);
    cout << "Minimum cost = " << res.first << '\n';
    return 0;
}

void readFile(string s, int graph[15][15], int &n)
{
    ifstream f(s);
    f >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            f >> graph[i][j];
}


void showPath(vector<int> path, int n)
{
    for (int i = 0; i < n; ++i)
        cout << path[i] << " -> ";
    cout << path[0] << '\n';
}

void showMatrix(int graph[15][15], int n)
{
     for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            cout << graph[i][j] << " ";
        cout << endl;
     }
}
