class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        map<char, int> m;
        for(auto it : s1){
            m[it]++;
        }
        
        int n = s1.size();
        int l = 0, r = 0;
        map<char, int> m1;
        while(n--){

            m1[s2[r]]++;
            r++;
        }

        int len = s2.size();
        while(r<len){

            if(m==m1) return true;
            else{

                m1[s2[r]]++;
                r++;
                m1[s2[l]]--;
                if(m1[s2[l]]<=0) m1.erase(s2[l]); 
                l++;
            }
        }

        if(m==m1) return true;
        return false;
    }
};
