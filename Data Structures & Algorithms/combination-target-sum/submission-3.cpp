class Solution {
public:

    vector<vector<int>> res;

    void func(vector<int>& nums, int i, int target, vector<int> v) {

        if (target == 0) {
            res.push_back(v);
            return;
        }

        if (i >= nums.size() || nums[i] > target)
            return;

        v.push_back(nums[i]);
        func(nums, i, target - nums[i], v);
        v.pop_back();

        func(nums, i + 1, target, v);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<int> v;
        func(nums, 0, target, v);

        return res;
    }
};
