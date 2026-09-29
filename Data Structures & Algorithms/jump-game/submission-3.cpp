class Solution {
public:

    bool f(vector<int> &nums, int i, int n, vector<int> &t){

        if(i>=n-1) return true;

        if(t[i] != -1) return t[i];
        
        bool res = false;
        for(int k = 1; k <= nums[i]; k++){

            if(f(nums, i+k, n, t)) return t[i] = 1;

        }

        return t[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> t(n, -1);

        return f(nums, 0, n, t);
    }
};
