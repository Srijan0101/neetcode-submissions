class Solution {
public:

    int f(vector<int> &nums, int i, int n, vector<int> &t){

        if(i==n-1) return 0;

        if(t[i]!=-1) return t[i];

        int jump = INT_MAX;
        for(int j = 1; j<=nums[i] && i+j<n; j++){

            jump = min(jump, f(nums, i+j, n, t));
        }

        if (jump != INT_MAX) return t[i] = 1 + jump;
        
        return t[i] = INT_MAX;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> t(n, -1);

        return f(nums, 0, n, t);
    }
};
