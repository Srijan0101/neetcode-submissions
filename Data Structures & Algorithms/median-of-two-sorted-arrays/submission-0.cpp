class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        for(auto it : nums1) res.push_back(it);
        for(auto it : nums2) res.push_back(it);

        sort(res.begin(), res.end());

        int n = res.size();
        if(n%2==0){
            double num1 = (double) res[(n/2)-1];
            double num2 = (double) res[n/2];

            return (double) (num1+num2)/2;
        }
        else{
            return (double) res[n/2];
        }
    }
};
