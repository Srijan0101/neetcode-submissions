class Solution {
public:
    bool checkValidString(string s) {

        int left_min = 0;
        int left_max = 0;

        for(auto it : s){

            if(it=='(') {
                left_min++;
                left_max++;
            }
            else if(it==')'){
                left_min--;
                left_max--;
            }
            else{
                left_max++;
                left_min--;
            }
            if(left_max<0) return false;
            if(left_min<0) left_min = 0;
        }
        
        if(left_min==0) return true;
        return false;
    }
};
