class Solution {
public:
    int trap(vector<int>& h) {
        
        int res = 0;
        int n = h.size();
        vector<int> prev_h(n, INT_MIN);
        vector<int> next_h(n, INT_MIN);

        prev_h[0] = h[0];

        for(int i = 1; i < n; i++){

            prev_h[i] = max(prev_h[i-1], h[i]);
        }

        next_h[n-1] = h[n-1];
        for(int i = n-2; i >= 0; i--){

            next_h[i] = max(next_h[i+1], h[i]);
        }

        for(int i = 0; i < n; i++){

            res += min(prev_h[i], next_h[i]) - h[i];
        }

        return res;
    }
};
