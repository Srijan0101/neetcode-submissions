class Solution {
public:
    vector<vector<int>> res;
    void func(vector<int> &c, int start, int target, vector<int> &v){

        if(target==0) {
            res.push_back(v);
            return;
        }

        for(int i = start; i < c.size(); i++){
            if(i > start && c[i]==c[i-1]) continue;

            if(c[i]>target) return;

            v.push_back(c[i]);
            func(c, i+1, target-c[i], v);

            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        
        vector<int> v;

        sort(c.begin(), c.end());

        func(c, 0, target, v);

        return res;
    }
};
