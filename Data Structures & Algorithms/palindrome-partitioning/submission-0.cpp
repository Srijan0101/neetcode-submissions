class Solution {
public:

    vector<vector<string>> res;

    bool isPalindrome(string &t){

        string r = t;
        reverse(r.begin(), r.end());

        return r == t;
    }

    void func(string &s, int i, vector<string> &v){

        if(i==s.size()){
            res.push_back(v);
            return;
        }

        for(int j = i; j < s.size(); j++){

            string t = s.substr(i, j-i+1);
            if(!isPalindrome(t)) continue;

            v.push_back(t);
            func(s, j+1, v);

            v.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        
        vector<string> v;
        func(s, 0, v);
        
        return res;
    }
};
