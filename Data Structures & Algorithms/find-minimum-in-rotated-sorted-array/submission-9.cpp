class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        // If the array is not rotated at all, the first element is the minimum
        if (nums[l] <= nums[r]) return nums[l];
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            // If mid element is greater than the rightmost element,
            // the minimum must be in the right half.
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } 
            // Otherwise, the minimum is in the left half (including mid)
            else {
                r = mid;
            }
        }
        
        return nums[l];
    }
};