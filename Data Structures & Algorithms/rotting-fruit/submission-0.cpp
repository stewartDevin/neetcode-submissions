class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // create a queue of int pairs to keep track of rotten indexes
        queue<pair<int, int>> q;
        // get size of rows and cols
        const int ROWS = grid.size(); 
        const int COLS = grid[0].size();
        // keep track of num of fresh oranges, and time it took for all to rot
        int fresh = 0, time = 0;

        // loop through all oranges and increment fresh ones, 
        // and add rotten indexes to queue
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 1) {
                    ++fresh;
                }
                else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        // make a list for each direction we're checking so we can loop through
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty() && fresh > 0) {
            int length = q.size();
            for (int i = 0; i < length; ++i) {
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for (const auto& dir : directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;
                    
                    if (row >= 0 && row < ROWS &&
                        col >= 0 && col < COLS &&
                        grid[row][col] == 1) 
                    {
                        grid[row][col] = 2;
                        q.push({row, col});
                        --fresh;
                    }
                }
            }
            ++time;
        }
        return fresh == 0 ? time : -1;
    }
};
