class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& k) {
        
        vector<vector<int>> v;

        for(auto it : t){

            if(it[0]>k[0] || it[1]>k[1] || it[2]>k[2]) continue;
            else v.push_back(it);
        }

        vector<int> res(3, 0);

        for(auto it : v){

            if(it[0]==k[0]) res[0]++;
            if(it[1]==k[1]) res[1]++;
            if(it[2]==k[2]) res[2]++;
        }

        for(auto it : res){

            if(it==0) return false;
        }
        return true;
    }
};
