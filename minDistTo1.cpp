#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n, int m, vector<vector<int>>&grid, vector<vector<int>>&vis, vector<vector<int>>&ans) {
    queue<pair<pair<int, int>, int>>q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(!q.empty()) {
        int roww = q.front().first.first;
        int coll = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        ans[roww][coll] = steps;

        for(int i = 0; i < 4; i++) {
            int newr = roww + dr[i];
            int newc = coll + dc[i];
            if(newr >= 0 && newc >= 0 && newr < n && newc < m && !vis[newr][newc]) {
                q.push({{newr, newc}, steps + 1});
                vis[newr][newc] = 1;
            }
        }
    }

}

int main() {
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>vis(n, vector<int>(m, 0));
    vector<vector<int>>ans(n, vector<int>(m, 0));

    bfs(n, m, grid, vis, ans);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }


	


    return 0;
}