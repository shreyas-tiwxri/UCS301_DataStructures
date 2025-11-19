#include<iostream>
using namespace std;

class BFS {
private:
    int n;
    vector<vector<int>> adj;

public:
    BFS(int n) : n(n), adj(n) {}
    void addEdge(int u, int v) { adj.at(u).push_back(v); adj.at(v).push_back(u); }
    void run(int src) {
        vector<int> dist(n, -1), parent(n, -1);
        queue<int> q;
        dist[src] = 0; q.push(src);
        cout << "BFS order: ";
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        cout << "\nDistances from " << src << ":\n";
        for (int i = 0; i < n; ++i) cout << i << ": " << dist[i] << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    BFS bfs(n);
    for (int i = 0; i < m; ++i) { int u, v; cin >> u >> v; bfs.addEdge(u, v); }
    int src; cin >> src;
    bfs.run(src);
    return 0;
}