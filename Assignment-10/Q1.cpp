#include<iostream>
using namespace std;
class graph{
    private:
    int n;
    bool directed;
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;

    public:
    graph{int n, bool directed = false} : n(n), directed(directed){
        adjList.assign(n,{});
        adjMatrix.assign(n,vector<int>(n,0));
    }

    void addEdge(int u, int v, int weight = 1) {
        adjList.at(u).push_back(v);
        adjMatrix.at(u).at(v) = weight;
        if (!directed) {
            adjList.at(v).push_back(u);
            adjMatrix.at(v).at(u) = weight;
        }
}

vector<int> adjacentVertices(int u) const { return adjList.at(u); }
    int outDegree(int u) const { return (int)adjList.at(u).size(); }
    int inDegree(int u) const {
        if (!directed) return outDegree(u);
        int deg = 0;
        for (int v = 0; v < n; ++v) if (adjMatrix[v][u]!=0) ++deg;
        return deg;
    }

    int numberOfEdges() const {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (adjMatrix[i][j] != 0) ++cnt;
        if (!directed) cnt /= 2;
        return cnt;
    }

    void printAdjacencyList() const {
        for (int i = 0; i < n; ++i) {
            cout << i << ": ";
            for (int v : adjList[i]) cout << v << " ";
            cout << "\n";
        }
    }

    void printAdjacencyMatrix() const {
        cout << "   ";
        for (int j = 0; j < n; ++j) cout << j << " ";
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            cout << i << ": ";
            for (int j = 0; j < n; ++j) cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }

    int size() const { return n; }
    const vector<vector<int>>& getAdjList() const {return adjList;}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cout << "Enter number of vertices: ";
    if (!(cin >> n)) return 0;
    char ch;
    cout << "Directed graph? (y/n): ";
    cin >> ch;
    bool dir = (ch == 'y' || ch == 'Y');
    Graph g(n, dir);

    cout << "Enter edges (u v). Enter -1 -1 to stop.\n";
    while (true) {
        int u, v; cin >> u >> v;
        if (u == -1 && v == -1) break;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid vertices, try again.\n";
            continue;
        }
        g.addEdge(u, v);
    }

    while(true){
        cout << "\n Menu:\n 1) Print adjacency list\n 2) Print adjacency matrix\n 3) Adjacent vertices of u\n 4) Degree of vertex u\n 5) In-degree/Out-degree (directed)\n 6) Number of edges\n 7) Exit\n Choose: ";
        int opt; cin >> opt;
        if (opt == 1) g.printAdjacencyList();
        else if (opt == 2) g.printAdjacencyMatrix();
        else if (opt == 3) {
            int u; cin >> u;
            auto adj = g.adjacentVertices(u);
            cout << "Adjacent to " << u << ": ";
            for (int v : adj) cout << v << " ";
            cout << "\n";
        }
        else if (opt == 4) {
            int u; cin >> u;
            cout << "Degree (out) of " << u << ": " << g.outDegree(u) << "\n";
        }
        else if (opt == 5) {
            if (!dir) cout << "Undirected graph: in-degree == out-degree.\n";
            int u; cin >> u;
            cout << "Out-degree: " << g.outDegree(u) << "\n";
            if (dir) cout << "In-degree: " << g.inDegree(u) << "\n";
        }
        else if (opt == 6) {
            cout<<"Number of edges: "<<g.numberOfEdges()<<"\n";
    }
    else break;
    }
return 0;
}