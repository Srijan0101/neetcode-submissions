class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> s(nums.begin(), nums.end());
        int res = 0;

        for(auto it : nums){

            if(s.find(it-1)==s.end()){

                int len = 1, num = it;
                while(s.find(num+1)!=s.end()){
                    num++;
                    len++;
                }

                res = max(res, len);
            }
        }
        return res;
    }
};
