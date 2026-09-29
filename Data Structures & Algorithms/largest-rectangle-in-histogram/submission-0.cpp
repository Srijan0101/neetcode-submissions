class Solution {
public:
    int largestRectangleArea(vector<int>& h) {

        int n = h.size();
        stack<pair<int, int>> s;
        int max_area = 0;

        for(int i = 0; i < n; i++){

            if(s.empty()) s.push({i, h[i]});
            int idx = i;
            while(!s.empty() && s.top().second>h[i]){
                idx = s.top().first;
                max_area = max(max_area, s.top().second*(i-idx));
                s.pop();
            }

            s.push({idx, h[i]});
        }

        while(!s.empty()){

            max_area = max(max_area, s.top().second*(n-s.top().first));
            s.pop();
        }

        return max_area;
    }
};
