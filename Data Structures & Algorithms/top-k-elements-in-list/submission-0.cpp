class Solution {
   public:
    vector<int> topKFrequent(vector<int>& v1, int k) {
        unordered_map<int, int> mp;
        for (auto it : v1) {
            mp[it]++;
        }

        vector<pair<int, int>> v;

        for(auto it : mp){
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end(), greater<pair<int, int>> ());

        vector<int> res;
        int i = 0;
        while(k--){
            res.push_back(v[i].second);
            i++;
        }

        return res;
    }
};
