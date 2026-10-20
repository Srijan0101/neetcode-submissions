class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = 0, r = 0, len = 0;
        unordered_map<char, int> m;

        while(r<s.size()){

            m[s[r]]++;
            while(m[s[r]]>1){
                m[s[l]]--;
                l++;
            }

            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};
