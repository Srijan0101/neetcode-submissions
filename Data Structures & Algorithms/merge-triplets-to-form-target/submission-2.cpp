class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& k) {
        
        vector<vector<int>> v;

        for(auto it : t){

            if(it[0]>k[0] || it[1]>k[1] || it[2]>k[2]) continue;
            else v.push_back(it);
        }

        int max_0 = INT_MIN, max_1 = INT_MIN, max_2 = INT_MIN;

        for(int i = 0; i < v.size(); i++){

            max_0 = max(max_0, v[i][0]);
            max_1 = max(max_1, v[i][1]);
            max_2 = max(max_2, v[i][2]);
        }

        int have = 0;
        if(max_0 == k[0]) have++;
        if(max_1 == k[1]) have++;
        if(max_2 == k[2]) have++;

        return have == 3 ? true : false;


    }
};
