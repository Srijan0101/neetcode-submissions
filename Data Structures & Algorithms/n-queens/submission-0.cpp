class Solution {
public:

    bool isValid(vector<string> &board, int i, int j){

        for(int r = i-1; r >= 0; r--){

            if(board[r][j] == 'Q') return false;
        }

        for(int r = i-1, c = j-1; r>=0 && c>=0; r--, c--){

            if(board[r][c]=='Q') return false;
        }

        for(int r = i-1, c = j+1; r>=0 && c<board.size(); r--, c++){

            if(board[r][c]=='Q') return false;
        }

        return true;
    }

    void func(int n, int i, vector<vector<string>> &res, vector<string> &board){

        if(i==n){
            res.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++){

            if(isValid(board, i, j)){
                board[i][j] = 'Q';
                func(n, i+1, res, board);
                board[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        func(n, 0, res, board);

        return res;
    }
};
