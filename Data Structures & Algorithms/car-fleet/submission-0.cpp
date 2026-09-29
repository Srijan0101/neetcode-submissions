class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        
        vector<pair<int, int>> v;
        int n = pos.size();
        for(int i = 0; i < n; i++){

            v.push_back({pos[i], speed[i]});
        }

        sort(v.rbegin(), v.rend());

        stack<double> s;

        for(int i = 0; i < n; i++){

            int dist = target-v[i].first;
            int speed = v[i].second;
            double time = (double)dist/speed;

            if(s.empty() || time>s.top()) s.push(time);
        }

        return s.size();
    }
};
