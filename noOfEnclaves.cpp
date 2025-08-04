#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n, int m, vector<vector<int>>&grid, vector<vector<int>>&vis) {

    queue<pair<int, int>>q;

    for(int i = 0; i < n; i++) {
        if(!vis[i][0] && grid[i][0] == 1) {
            vis[i][0] = 1;
            q.push({i, 0});
        }
        if(!vis[i][m-1] && grid[i][m-1] == 1) {
            vis[i][m-1] = 1;
            q.push({i, m-1});
        }
    }

    for(int j = 0; j < m; j++) {
        if(!vis[0][j] && grid[0][j] == 1) {
            vis[0][j] = 1;
            q.push({0, j});
        }
        if(!vis[n-1][j] && grid[n-1][j] == 1) {
            vis[n-1][j] = 1;
            q.push({n-1, j});
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newr = row + dr[i];
            int newc = col + dc[i];
            
            if(newr >= 0 && newc >= 0 && newr < n && newc < m && !vis[newr][newc] && grid[newr][newc] == 1) {
                vis[newr][newc] = 1;
                q.push({newr, newc});
            }
        }

    }



}

int main() {

    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>vis(n, vector<int>(m, 0));

    bfs(n, m, grid, vis);

    vector<vector<int>>ans(n, vector<int>(m, 0));

    int numOfEnc = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && vis[i][j] == 0) {
                numOfEnc++;
                ans[i][j] = grid[i][j];
            }

        }
    }

    cout << numOfEnc << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}