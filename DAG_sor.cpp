#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int node, vector<vector<pair<int, int>>>& graph,
                     vector<bool>& visited, stack<int>& st) {
    visited[node] = true;

    for (auto edge : graph[node]) {
        int next = edge.first;

        if (!visited[next])
            topologicalSort(next, graph, visited, st);
    }

    st.push(node);
}

int main() {
    int n = 6;

    vector<vector<pair<int, int>>> graph(n);

    graph[0].push_back({1, 5});
    graph[0].push_back({2, 3});
    graph[1].push_back({3, 6});
    graph[1].push_back({2, 2});
    graph[2].push_back({4, 4});
    graph[2].push_back({5, 2});
    graph[2].push_back({3, 7});
    graph[3].push_back({4, -1});
    graph[4].push_back({5, -2});

    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            topologicalSort(i, graph, visited, st);
    }

    const int INF = 1e9;
    vector<int> dist(n, INF);

    int source = 0;
    dist[source] = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INF) {
            for (auto edge : graph[node]) {
                int next = edge.first;
                int weight = edge.second;

                dist[next] = min(dist[next],
                                 dist[node] + weight);
            }
        }
    }

    cout << "Shortest Distances:\n";

    for (int i = 0; i < n; i++) {
        cout << "0 -> " << i << " = ";

        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
