class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> s;
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            long long sum = 0;
            while(n){
                int dig = n%10;
                sum += dig*dig;
                n/=10;
            }
            n = sum;
        }
        if(n==1) return true;
        return false;
    }
};
