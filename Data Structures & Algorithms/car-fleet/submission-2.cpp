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

            if(s.empty()) s.push(time);
            else {
                double t2 = s.top();

                if(t2<time) s.push(time);
            }
        }

        return s.size();
    }
};
