class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::set<char> rows[9];
        std::set<char> cols[9];
        std::set<char> blocks[9];
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int blockIdx = (i / 3) * 3 + (j / 3);
                auto res = rows[i].insert(board[i][j]);
                auto res2 = cols[j].insert(board[i][j]);
                auto res3 = blocks[blockIdx].insert(board[i][j]);
                if (res.second == false || res2.second == false || res3.second == false) {
                    return false;
                }
            }
        }
        return true;
    }
};