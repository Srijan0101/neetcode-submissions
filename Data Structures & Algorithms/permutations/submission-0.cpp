class Solution {
public:

    vector<vector<int>> res;

    void func(vector<int>& nums, int i){

        if(i==nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++){

            swap(nums[i], nums[j]);
            func(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        func(nums, 0);
        return res;
    }
};
