#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> mpsi;
typedef map<int, int> mpii;

inline void BOOST() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
}

const int N = 2 * (1e5 + 1);
vector<vi> adj;
bool vis[N];
stack<int> topo;

void dfs(int v) {
    vis[v] = true; // mark this node as visited
    int neighbours = adj[v].size();
    for (int i = 0; i < neighbours; ++i) { // traverse all the neighbours of v and dfs at each one
        int node = adj[v][i];
        if (!vis[node]) {
            dfs(node);
        }
    }
    topo.push(v); // push current node to the stack as it's not finished yet
}

void topologicalSort(int n) { // dfs at each node
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i); // dfs at current node
            //cout << endl;
        }
    }
    while (!topo.empty()) {
        cout << topo.top() << " ";
        topo.pop();
    }
    cout << endl;
}


int main() {
    int nodes, edges, u, v;
    cin >> nodes >> edges; // number of nodes
    adj.resize(nodes + 1); // adjacency list
    for (int i = 0; i < edges; ++i) {
        cin >> v >> u; // vertex and edge
        adj[v].push_back(u); // directed only as Topological sorting needs a DAG graph
       
    }
    topologicalSort(nodes);
}
/*
 3 -> 4 -> 2
  ^ Graph ^
  |        \
  6-> 1 <-5
*/
/*
6 6
6 1
6 3
3 4
4 2
5 2
5 1
 */
