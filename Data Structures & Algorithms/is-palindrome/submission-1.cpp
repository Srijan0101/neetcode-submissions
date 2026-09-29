class Solution {
public:
    bool isPalindrome(string s) {
        
        string r = "";
        for(auto it : s){
            if(isalnum(it)) {
                if(it>='A' && it<='Z') r+=tolower(it);
                else r+=it;
            }
        }

        string t = r;
        reverse(t.begin(), t.end());

        return t==r;
    }
};
