class Solution { 
public: 
    vector<int> partitionLabels(string s) { 
        // Fixed the double quote syntax error here
        vector<vector<int>> v(26, vector<int>(2, -1)); 
        for(int i = 0; i < s.size(); i++){ 
            int idx = s[i]-'a'; 
            if(v[idx][0]==-1) v[idx][0] = i; 
            v[idx][1] = i; 
        } 
        vector<vector<int>> t; 
        sort(v.begin(), v.end()); 
        for(int i = 0; i < v.size(); i++){ 
            if(v[i][0]!=-1){ 
                if(t.empty()) t.push_back(v[i]); 
                else{ 
                    int j = t.back()[1]; 
                    if(j>v[i][0]) t.back()[1] = max(j, v[i][1]); 
                    else t.push_back(v[i]); 
                } 
            } 
        } 
        vector<int> res; 
        for(int i = 0; i < t.size(); i++){ 
            res.push_back(t[i][1]-t[i][0]+1); 
        } 
        return res;
    } 
};