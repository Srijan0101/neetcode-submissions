class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int res = INT_MIN, sum = 0;

        for(auto it : nums){

            sum = max(sum+it, it);
            res = max(res, sum);
        }

        return res;
    }
};
