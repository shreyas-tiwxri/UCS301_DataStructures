#include<iostream>
using namespace std;
class Edge {
private:
    int u, v;
    long long w;
public:
    Edge(int u=0,int v=0,long long w=0): u(u), v(v), w(w) {}
    int from() const { return u; }
    int to() const { return v; }
    long long weight() const { return w; }
    bool operator<(const Edge& other) const { return w < other.w; }
};

class DSU {
private:
    vector<int> parent, rankv;
public:
    DSU(int n) : parent(n), rankv(n, 0) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) ++rankv[a];
        return true;
    }
};

class Kruskal {
private:
    int n;
    vector<Edge> edges;
public:
    Kruskal(int n) : n(n) {}
    void addEdge(int u, int v, long long w) { edges.emplace_back(u, v, w); }
    void buildMST() {
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        vector<Edge> mst;
        long long total = 0;
        for (const auto &e : edges) {
            if (dsu.unite(e.from(), e.to())) {
                mst.push_back(e);
                total += e.weight();
            }
        }
        cout << "MST weight: " << total << "\nEdges:\n";
        for (const auto &e : mst) cout << e.from() << " - " << e.to() << " : " << e.weight() << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    Kruskal kr(n);
    for (int i = 0; i < m; ++i) { int u, v; long long w; cin >> u >> v >> w; kr.addEdge(u, v, w); }
    kr.buildMST();
    return 0;
}