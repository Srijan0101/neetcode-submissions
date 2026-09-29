class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        map<char, int> m;
        int res = 0;
        
        int l = 0, r = 0, n = s.size();
        while(l<=r && r<n){

            m[s[r]]++;
            while (m[s[r]] > 1) {
                m[s[l]]--;
                l++;
            }

            res = max(res, r-l+1);
            r++;
        }

        return res;
    }
};


