class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int cnt = 0;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] == '1' && !visited[i][j]) {
                    cnt++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {

                        auto [r, c] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {

                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if (nr >= 0 && nr < row &&
                                nc >= 0 && nc < col &&
                                grid[nr][nc] == '1' &&
                                !visited[nr][nc]) {

                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};