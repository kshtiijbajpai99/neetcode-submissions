class Solution {
public:

    int n, m;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};


    // DFS:
    // Current cell se un cells ki taraf ja rahe hain
    // jahan se water reverse direction mein aa sakta hai.
    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        // Current cell ko visited mark karo
        visited[r][c] = true;


        // Current cell ke 4 neighbours check karo
        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];


            // Grid ke bahar hai toh ignore
            if(nr < 0 || nr >= n ||
               nc < 0 || nc >= m) {
                continue;
            }


            // Agar already visited hai toh dobara DFS nahi
            if(visited[nr][nc]) {
                continue;
            }


            // Reverse flow mein:
            //
            // current = 3
            // neighbour = 4
            //
            // 3 -> 4 allowed
            //
            // Isliye neighbour ki height
            // current se >= honi chahiye.
            if(heights[nr][nc] < heights[r][c]) {
                continue;
            }


            // Valid neighbour mila,
            // ab usse bhi aage explore karo.
            dfs(nr, nc, heights, visited);
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();


        // Pacific se reachable cells
        vector<vector<bool>> pacific(
            n, vector<bool>(m, false)
        );


        // Atlantic se reachable cells
        vector<vector<bool>> atlantic(
            n, vector<bool>(m, false)
        );


        // ==========================================
        // PACIFIC
        // Top row + Left column
        // ==========================================

        for(int j = 0; j < m; j++) {

            // Top row
            dfs(0, j, heights, pacific);
        }

        for(int i = 0; i < n; i++) {

            // Left column
            dfs(i, 0, heights, pacific);
        }


        // ==========================================
        // ATLANTIC
        // Bottom row + Right column
        // ==========================================

        for(int j = 0; j < m; j++) {

            // Bottom row
            dfs(n - 1, j, heights, atlantic);
        }

        for(int i = 0; i < n; i++) {

            // Right column
            dfs(i, m - 1, heights, atlantic);
        }


        // ==========================================
        // FINAL ANSWER
        // ==========================================

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Agar cell Pacific aur Atlantic
                // dono se reachable hai
                if(pacific[i][j] && atlantic[i][j]) {

                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};