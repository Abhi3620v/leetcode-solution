class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // First pass: calculate next states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;

                // Count neighbours that were originally alive
                for (int d = 0; d < 8; d++) {
                    int r = i + dr[d];
                    int c = j + dc[d];

                    if (r >= 0 && r < m &&
                        c >= 0 && c < n &&
                        (board[r][c] == 1 ||
                         board[r][c] == -1)) {
                        live++;
                    }
                }

                // Live cell
                if (board[i][j] == 1) {
                    if (live < 2 || live > 3)
                        board[i][j] = -1;
                }
                // Dead cell
                else if (board[i][j] == 0) {
                    if (live == 3)
                        board[i][j] = 2;
                }
            }
        }

        // Second pass: convert temporary states to final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};