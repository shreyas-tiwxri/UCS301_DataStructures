#include<iostream>
using namespace std;

class DFS {
private:
    int n;
    vector<vector<int>> adj;
    vector<int> vis, tin, tout;
    int timer;

    void dfsUtil(int u) {
        vis[u] = 1;
        tin[u] = timer++;
        cout << u << " ";
        for (int v : adj[u]) if (!vis[v]) dfsUtil(v);
        tout[u] = timer++;
    }

public:
    DFS(int n) : n(n), adj(n), vis(n, 0), tin(n, -1), tout(n, -1), timer(0) {}
    void addEdge(int u, int v) { adj.at(u).push_back(v); adj.at(v).push_back(u); }
    void runAll() {
        cout << "DFS order: ";
        for (int i = 0; i < n; ++i) if (!vis[i]) dfsUtil(i);
        cout << "\nDiscovery times (tin):\n";
        for (int i = 0; i < n; ++i) cout << i << ": " << tin[i] << "\n";
        cout << "Finish times (tout):\n";
        for (int i = 0; i < n; ++i) cout << i << ": " << tout[i] << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    DFS dfs(n);
    for (int i = 0; i < m; ++i) { int u, v; cin >> u >> v; dfs.addEdge(u, v); }
    dfs.runAll();
    return 0;
}