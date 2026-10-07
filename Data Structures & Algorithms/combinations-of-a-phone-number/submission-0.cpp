class Solution {
public:

    vector<string> res;
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void func(string dig, string s, int i){

        if(dig.size() == s.size()){
            res.push_back(s);
            return;
        }

        string str = v[dig[i]-'0'];

        for(auto c : str){

            func(dig, s+c, i+1);
        }

    }

    vector<string> letterCombinations(string digits) {
        
        if(!digits.size()) return res;

        string s = "";
        func(digits, s, 0);

        return res;
    }
};
