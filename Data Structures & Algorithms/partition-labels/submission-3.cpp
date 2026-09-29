class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<vector<int>> v(26, vector<int>(2, -1));

        for(int i = 0; i < s.size(); i++){

            int idx = s[i]-'a';
            if(v[idx][0]==-1) v[idx][0] = i;
            else v[idx][1] = i;
        }

        vector<vector<int>> t;
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            
            if(v[i][0]!=-1){
                if(t.empty()) t.push_back(v[i]);
                else{
                    int j = t.back()[1];
                    if(j>v[i][0]) t.back()[1] = max(t.back()[1], v[i][1]);
                    else t.push_back(v[i]);
                }
            }
        }

        for(auto it : t){

            cout<<it[0]<<" "<<it[1]<<endl;
        }

        vector<int> res;
        for(int i = 0; i < t.size(); i++){

            if(t[i][1]!=-1){
                res.push_back(t[i][1]-t[i][0]+1);
            }
            else res.push_back(1);
        }
        return res;
    }
};
