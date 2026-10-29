class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int sum_g = accumulate(gas.begin(), gas.end(), 0);
        int sum_c = accumulate(cost.begin(), cost.end(), 0);

        if(sum_g < sum_c) return -1;

        int start = 0, total = 0;

        for(int i = 0; i < gas.size(); i++){

            total += gas[i] - cost[i];
            if(total<0){
                start = i+1;
                total = 0;
            }
        }
        return start;
    }
};
