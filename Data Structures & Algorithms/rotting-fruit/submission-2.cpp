class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int minutes = 0;

        // count fresh and add rotten
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 1) {
                    ++fresh;
                } else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // BFS
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            ++minutes;

            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; ++k) {
                    int nr = r + dir[k][0];
                    int nc = c + dir[k][1];

                    if (nr >= 0 && nr < ROWS && 
                        nc >= 0 && nc < COLS && 
                        grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        --fresh;
                    }
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};