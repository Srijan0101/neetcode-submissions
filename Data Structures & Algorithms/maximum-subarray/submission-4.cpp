class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = -10001, max_sum = INT_MIN;
        for(auto it : nums){

            sum = max(sum + it, it);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};
