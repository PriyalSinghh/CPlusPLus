#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int n, int m, vector<vector<char>>& mat, vector<vector<int>>& vis) {
    
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        if (mat[i][0] == 'O' && !vis[i][0]) {
            q.push({i, 0});
            vis[i][0] = 1;
        }
        if (mat[i][m - 1] == 'O' && !vis[i][m - 1]) {
            q.push({i, m - 1});
            vis[i][m - 1] = 1;
        }
    }

    for (int j = 0; j < m; j++) {
        if (mat[0][j] == 'O' && !vis[0][j]) {
            q.push({0, j});
            vis[0][j] = 1;
        }
        if (mat[n - 1][j] == 'O' && !vis[n - 1][j]) {
            q.push({n - 1, j});
            vis[n - 1][j] = 1;
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newr = row + dr[i];
            int newc = col + dc[i];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                mat[newr][newc] == 'O' && !vis[newr][newc]) {
                vis[newr][newc] = 1;
                q.push({newr, newc});
            }
        }
    }
}

int main() {
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    bfs(n, m, mat, vis);

    vector<vector<char>> ans(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'O' && !vis[i][j])
                ans[i][j] = 'X'; 
            else
                ans[i][j] = mat[i][j]; 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
