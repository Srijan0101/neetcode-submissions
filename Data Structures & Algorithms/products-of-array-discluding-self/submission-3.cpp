class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix_p(n), suffix_p(n), res(n);

        prefix_p[0] = 1, suffix_p[n-1] = 1;

        int p = 1;
        for(int i = 1; i < n; i++){

            p *= nums[i-1];
            prefix_p[i] = p;
        }

        p = 1;
        for(int j = n-2; j>=0; j--){

            p*=nums[j+1];
            suffix_p[j] = p;
        }

        for(int i = 0; i < n; i++){
            res[i] = prefix_p[i] * suffix_p[i];
        }
        return res;
    }
};
