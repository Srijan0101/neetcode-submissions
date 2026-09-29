class Solution {
public:
    vector<int> plusOne(vector<int>& dig) {
        
        int carry = 0, n = dig.size();
        for(int i = n-1; i >= 0; i--){

            int sum = 0;
            if(i==n-1) sum+=1;
            sum += carry+dig[i];

            if(sum==10){
                dig[i] = 0;
                carry = 1;
            }
            else {
                dig[i] = sum;
                carry = 0;
            }
        }

        vector<int> res;
        if(carry){
            res.push_back(1);
        }   

        for(auto it : dig) res.push_back(it);

        return res;
    }
};
