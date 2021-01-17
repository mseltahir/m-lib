#include <bits/stdc++.h>

using namespace std;

template<class T>
vector<T> dijkstra(T start, const vector<vector<pair<T, T>>>& v) {
    const T n = (T) v.size();
    vector<T> distance(n, numeric_limits<T>::max());
    distance[start] = 0;
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> q;
    vector<bool> visited(n);
    q.push({0, start});
    while (!q.empty()) {
        T s = q.top().second; q.pop();
        if (visited[s]) continue;
        visited[s] = true;
        for (auto u : v[s]) {
            T e = u.first, w = u.second;
            if (distance[s] + w < distance[e]) {
                distance[e] = distance[s] + w;
                q.push({distance[e], e});
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
    vector<vector<pair<int, int>>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    vector<int> d = dijkstra(0, v);
    for (int i = 0; i < n; ++i) {
        cout << i + 1  << " : " << d[i] << '\n';
    }
    return 0;
}
