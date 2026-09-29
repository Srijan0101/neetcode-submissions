class Solution {
public:

    bool func(char c){

        return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9');
    }

    bool isPalindrome(string s) {
        
        string r = "";
        for(auto it : s){
            if(func(it)) {
                if(it>='A' && it<='Z') r+=tolower(it);
                else r+=it;
            }
        }

        int l = 0, w = r.size()-1;
        while(l<w){

            if(r[l]!=r[w]) return false;
            l++;
            w--;
        }

        return true;
    }
};
