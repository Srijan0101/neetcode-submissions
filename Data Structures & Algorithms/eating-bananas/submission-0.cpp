class Solution {
public:

    bool canBeDone(vector<int> &p, int k, int h){

        long long res = 0;
        for(auto it : p){

            res += (it+k-1)/k;
        }

        return res<=h;
    }

    int minEatingSpeed(vector<int>& p, int h) {
        
        int r = *max_element(p.begin(), p.end()); 
        int l = 1;

        while(l<r){

            int mid = l + (r-l)/2;
            if(canBeDone(p, mid, h)) r = mid;
            else l = mid+1;
        }

        return r;
    }
};
