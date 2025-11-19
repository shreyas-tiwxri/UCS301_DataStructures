#include<iostream>
using namespace std;
using namespace ll = long long;

class Prim{
    private:
    int n;
    vector<vector<pair<int,ll>>> adj;
    public:
    Prim(int n) : n(n), adj(n) {}
    void addEdge(int u, int v, ll w) { adj.at(u).push_back({v,w}); adj.at(v).push_back({u,w});}

    void run(int start = 0) {
        const ll INF = LLONG_MAX;
        vector<ll> key(n, INF);
        vector<int> parent(n, -1);
        vector<bool> inMST(n, false);
        key[start] = 0;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [k, u] = pq.top(); pq.pop();
            if (inMST[u]) continue;
            inMST[u] = true;
            for (auto [v, w] : adj[u]) {
                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
        ll total = 0;
        cout << "Edges in MST:\n";
        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
                cout << parent[i] << " - " << i << " : " << key[i] << "\n";
                total += key[i];
            }
        }
        cout << "Total MST weight: " << total << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    Prim prim(n);
    for (int i = 0; i < m; ++i) { int u, v; long long w; cin >> u >> v >> w; prim.addEdge(u, v, w); }
    prim.run(0);
    return 0;
}
