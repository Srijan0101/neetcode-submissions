class Solution {
public:

    vector<vector<int>> res;

    void func(vector<int> &nums, int i, vector<int> &v){

        if(i==nums.size()){
            res.push_back(v);
            return;
        }

        v.push_back(nums[i]);
        func(nums, i+1, v);
        v.pop_back();

        while(i+1< nums.size() && nums[i]==nums[i+1]) i++;
        func(nums, i+1, v);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int> v;
        func(nums, 0, v);
        return res;
    }
};
