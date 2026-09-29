class Solution {
public:
    int trap(vector<int>& h) {
        
        int n = h.size();
        vector<int> p_h(n, INT_MIN), s_h(n, INT_MIN);

        int max_h = INT_MIN;
        for(int i = 0; i < n; i++){

            max_h = max(max_h, h[i]);
            p_h[i] = max_h;
        }

        max_h = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            max_h = max(max_h, h[i]);
            s_h[i] = max_h;
        }

        int res = 0;
        for(int i = 0; i < n; i++){

            res += min(p_h[i], s_h[i])-h[i];
        }

        return res;
    }
};
