class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
    

        unordered_map<string, vector<string>> m;
        for(auto s : str){

            string r = s;
            sort(s.begin(), s.end());

            m[s].push_back(r);
        }

        vector<vector<string>> res;

        for(auto it : m){

            vector<string> v; 
            for(auto j : it.second){
                v.push_back(j);
            }

            res.push_back(v);
        }
        return res;
    }
};
