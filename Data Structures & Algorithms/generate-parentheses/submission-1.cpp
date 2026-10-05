class Solution {
public:
    vector<string> res;

    void func(string &s, int size, int open, int close){

        if(open==close && open==size){
            res.push_back(s);
            return;
        }

        if(open<size){
            s += '(';
            func(s, size, open+1, close);
            s.pop_back();
        }
        
        if(close<open){
            s += ')';
            func(s, size, open, close+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        string s = "";
        func(s, n, 0, 0);
        return res;
    }
};
