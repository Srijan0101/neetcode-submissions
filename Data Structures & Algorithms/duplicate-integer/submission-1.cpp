class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        if(!nums.size()) return false;
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++){

            if(nums[i-1]==nums[i]) return true;
        }
        return false;
    }
};