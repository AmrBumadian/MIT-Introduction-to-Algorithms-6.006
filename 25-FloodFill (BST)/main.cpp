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

int filled[1000][1000];
bool vis[1000][1000];
int n, m;
int dr[] = {1, 1, 1, 0, 0, -1, -1, -1}; // direction movement to traverse the grid
int dc[] = {1, 0, -1, 1, -1, 1, 0, -1};

inline bool can(int x, int y) {
    return x >= 0 && x < n && y < n && y >= 0;
}

void floodFill(int x, int y, int replacement) { // (BFS) replace all elements = current that are connected
    queue<ii> points; // store nodes to be changed
    points.push({x, y}); // push start node
    int color = filled[x][y]; // the color we want to change
    vis[x][y] = true;

    while (!points.empty()) {
        ii cur = points.front();
        points.pop(); // dequeue finished node
        int X = cur.first, Y = cur.second;
        filled[X][Y] = replacement; // change color
        for (int i = 0; i < 8; ++i) {  // traverse all 8 directions from (x,y)
            if (can(X + dr[i], Y + dc[i]) // if (x,y) not out of bounds
                && filled[X + dr[i]][Y + dc[i]] == color // and if current node color is the one we want
                && !vis[X + dr[i]][Y + dc[i]]) { // and if it's not already done
                points.push(ii(X + dr[i], Y + dc[i])); // add it to the queue
                vis[X + dr[i]][Y + dc[i]] = true; // flag it as visited
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> filled[i][j];
        }
    }
    int replacement, x, y;
    cin >> x >> y >> replacement; // coordinates to start from and replacement value
    floodFill(x, y, replacement);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << filled[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}