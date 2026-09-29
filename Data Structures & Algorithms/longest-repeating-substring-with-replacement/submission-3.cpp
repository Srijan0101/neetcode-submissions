class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int res = 0;
        unordered_map<char, int> m;

        int l = 0, r = 0, size = 0;

        while(l<=r && r<s.size()){

            m[s[r]]++;
            int count = 0;
            for(auto it : m){

                count = max(count, it.second);
            }

            if((r-l+1)-count<=k){

                size = max(size, r-l+1);
                r++;
            }
            else{
                m[s[l]]--;
                l++;
                r++;
            }
        }

        return size;
    }
};
