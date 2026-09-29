class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        
        for(int row = 0; row< 9; row++){
            unordered_set<char>s;
            for(int col = 0; col<9; col++){
                if(s.find(b[row][col])!=s.end()) return false;
                if(b[row][col]!='.') s.insert(b[row][col]);
            }
        }

        for(int col = 0; col< 9; col++){
            unordered_set<char>s;
            for(int row = 0; row<9; row++){
                if(s.find(b[row][col])!=s.end()) return false;
                if(b[row][col]!='.') s.insert(b[row][col]);
            }
        }

        for(int row = 0; row<9; row+=3){
            for(int col = 0; col<9; col+=3){

                int i = 0, j = 0;
                unordered_set<char> s;

                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(s.find(b[i+row][j+col])!=s.end()) return false;
                        if(b[i+row][j+col]!='.') s.insert(b[i+row][j+col]);
                    }
                }
            }
        }

        return true;
    }
};
