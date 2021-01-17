#include <bits/stdc++.h>

using namespace std;

template<class T>
vector<vector<T>> floyd_warshall(const vector<vector<T>>& graph) {
    const int n = (int) graph.size();
    const T INF = (T) 1e9 + 9; // set according to T;
    vector<vector<T>> distance(n, vector<T>(n, INF));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) distance[i][j] = 0;
            else if (graph[i][j]) distance[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
    return distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        v[a][b] = v[b][a] = w;
    }
    vector<vector<int>> d = floyd_warshall(v);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
