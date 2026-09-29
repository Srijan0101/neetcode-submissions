class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        int min_p = INT_MAX;
        int res = INT_MIN;
        for(auto it : p){

            min_p = min(min_p, it);
            res = max(res, it-min_p);
        }

        return res;
    }
};
