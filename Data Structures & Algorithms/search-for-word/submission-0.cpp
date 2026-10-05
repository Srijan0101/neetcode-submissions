class Solution {
   public:
    int n, m;

    bool func(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (k == word.size()) return true;
        if (i < 0 || j < 0 || i >= n || j >= m) return false;

        if (board[i][j] != word[k] || board[i][j] == '#') return false;

        board[i][j] = '#';
        bool res = func(board, word, i + 1, j, k + 1) || func(board, word, i, j + 1, k + 1) ||
                   func(board, word, i - 1, j, k + 1) || func(board, word, i, j - 1, k + 1);

        board[i][j] = word[k];

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (func(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};
