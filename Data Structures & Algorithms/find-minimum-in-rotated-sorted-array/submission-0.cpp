class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int min_ele = INT_MAX;
        for(auto it : nums){
            min_ele = min(min_ele, it);
        }
        return min_ele;
    }
};
