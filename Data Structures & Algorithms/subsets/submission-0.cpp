class Solution {
public:
    vector<vector<int>> res;

    void func(vector<int>& nums, int i, int n, vector<int> v){

        if(i==n){
            res.push_back(v);
            return;
        }

        v.push_back(nums[i]);
        func(nums, i+1, n, v);

        v.pop_back();
        func(nums, i+1, n, v);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> v;
        func(nums, 0, nums.size(), v);
        return res;
    }
};
