#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int sr, int sc,int iniColor, int newColor, vector<vector<int>>&image, vector<vector<int>>&ans) {
    int n = image.size();
    int m = image[0].size();
    ans[sr][sc] = newColor;
    queue<pair<int,int>>q;
    q.push({sr, sc});
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newr = row + dr[i];
            int newc = col + dc[i];

            if(newr >= 0 && newc >= 0 && newr < n && newc < m && image[newr][newc] == iniColor && ans[newr][newc] == 0) {
                ans[newr][newc] = newColor;
                q.push({newr, newc});
            }
        }
    }
}

int main() {
    vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};

    vector<vector<int>>ans(3, vector<int>(3, 0));

    bfs(1, 1, 1, 2, image, ans);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}