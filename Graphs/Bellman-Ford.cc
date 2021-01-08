template <class T>
vector<T> bellman_ford(const vector<array<T, 3>> &edges, const T &starting_node, const T &number_of_nodes) {
    const T INF = T(1e9) + 9; // change to something bigger if T is 64-bit integer
    vector<T> distance(number_of_nodes, INF);
    distance[starting_node] = 0;
    for (int i = 0; i < number_of_nodes - 1; ++i) {
        for (auto edge : edges) {
            distance[edge[1]] = min(distance[edge[1]], distance[edge[0]] + edge[2]);
        }
    }
    return distance;
}

template <class T>
bool has_ncycle(const vector<array<T, 3>> &edges, const T &starting_node, const T &number_of_nodes) {
    const T INF = T(1e9) + 9; // change to something bigger if T is 64-bit integer
    vector<T> distance(number_of_nodes, INF);
    distance[starting_node] = 0;
    for (int i = 0; i < number_of_nodes - 1; ++i) {
        for (auto edge : edges) {
            distance[edge[1]] = min(distance[edge[1]], distance[edge[0]] + edge[2]);
        }
    }
    int64_t sum_before = accumulate(distance.begin(), distance.end(), 0LL);
    for (auto edge : edges) {
        distance[edge[1]] = min(distance[edge[1]], distance[edge[0]] + edge[2]);
    }
    int64_t sum_after = accumulate(distance.begin(), distance.end(), 0LL);
    return sum_before == sum_after ? false : true;
}
