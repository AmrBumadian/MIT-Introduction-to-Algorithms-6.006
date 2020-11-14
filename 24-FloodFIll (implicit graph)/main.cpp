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

void floodFill(int x, int y, int current, int replacement) { // replace all elements  = current that are connected
    if (x < 0 || y < 0 || x >= n || y >= m) { // if out of grid return
        return;
    }
    if (vis[x][y] || filled[x][y] != current) return; // if already changed or not equal current return
    vis[x][y] = true;
    filled[x][y] = replacement; // replace

    for (int i = 0; i < 8; ++i) {
        floodFill(x + dr[i], y + dc[i], current, replacement); // traverse all 8 directions from (x,y)
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
    floodFill(x, y, filled[x][y], replacement);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << filled[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}