class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
        stack<int> s;
        int n = t.size();

        vector<int> v(n, 0);

        for(int i = 0; i < n; i++){

            int curr = t[i];
            if(s.empty()) s.push(i);
            else{

                while(!s.empty() && t[s.top()]<curr){

                    v[s.top()] = i-s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
        return v;
    }
};
