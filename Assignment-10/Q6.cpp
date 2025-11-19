#include<iostream>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

class Dijkstra {
private:
    int n;
    vector<vector<pair<int,ll>>> adj;
public:
    Dijkstra(int n) : n(n), adj(n) {}
    void addEdge(int u, int v, ll w, bool undirected=false) {
        adj.at(u).push_back({v,w});
        if (undirected) adj.at(v).push_back({u,w});
    }

    void run(int src) {
        vector<ll> dist(n, INF);
        vector<int> parent(n, -1);
        dist[src] = 0;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        cout << "Distances from " << src << ":\n";
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INF) cout << i << ": INF\n";
            else cout << i << ": " << dist[i] << "\n";
        }
        cout << "\nPaths (reconstructed):\n";
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INF) { cout << i << ": unreachable\n"; continue; }
            vector<int> path; int cur = i;
            while (cur != -1) { path.push_back(cur); cur = parent[cur]; }
            reverse(path.begin(), path.end());
            cout << i << ": ";
            for (size_t j = 0; j < path.size(); ++j) {
                if (j) cout << " -> ";
                cout << path[j];
            }
            cout<<"\n";
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; if (!(cin >> n >> m)) return 0;
    Dijkstra dj(n);
    for (int i = 0; i < m; ++i) {
        int u, v; long long w; cin >> u >> v >> w;
        dj.addEdge(u, v, w); // treat input as directed; pass undirected=true if needed
    }
    int src; cin >> src;
    dj.run(src);
    return 0;
}