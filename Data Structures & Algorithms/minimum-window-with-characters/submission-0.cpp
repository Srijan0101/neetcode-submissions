class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ms, mt;

        for(auto it : t){
            mt[it]++;
        }

        int l = 0, r = 0, n = s.size();
        int need = mt.size();
        int have = 0;
        int i = -1, resLen = INT_MAX;
        
        while(r < n){
            char c = s[r];
            ms[c]++;

            if(mt.count(c) && mt[c] == ms[c]) have++;

            while(have == need){
                int len = r - l + 1;
                if(len < resLen){
                    resLen = len;
                    i = l;
                }
                
                // Get the character at the left pointer
                char leftChar = s[l];
                ms[leftChar]--;

                // Check if removing it breaks our 'have' requirement
                if(mt.count(leftChar) && ms[leftChar] < mt[leftChar]) {
                    have--;
                }
                
                // FIX: Move the left pointer forward to avoid an infinite loop
                l++; 
            }
            r++;
        }

        return resLen == INT_MAX ? "" : s.substr(i, resLen);
    }
};
