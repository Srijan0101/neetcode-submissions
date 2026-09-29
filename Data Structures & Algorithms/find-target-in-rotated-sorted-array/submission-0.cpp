class Solution {
public:

    int find_pivot(vector<int>& nums){

        int l = 0, r = nums.size()-1;

        if(nums[l]<nums[r]) return 0;

        while(l<r){

            int mid = l + (r-l)/2;
            if(nums[r]<nums[mid]) l = mid+1;
            else r = mid;
        }
        return l;

    }

    int binary_search(vector<int> &nums, int target, int l, int r){

        while(l<=r){

            int mid = l+(r-l)/2;

            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l = mid+1;
            else r = mid-1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        int pivot = find_pivot(nums);

        cout<<"pivot: "<<pivot<<endl;

        int res = binary_search(nums, target, 0, pivot);

        cout<<"res1: "<<res<<endl;
        if(res==-1) res = binary_search(nums, target, pivot, nums.size()-1);

        cout<<"res2: "<<res<<endl;

        return res;
    }
};
