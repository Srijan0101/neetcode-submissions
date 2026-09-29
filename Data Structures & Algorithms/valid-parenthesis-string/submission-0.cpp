class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> left, star;

        int n = s.size();
        for(int i = 0; i < n; i++){

            if(s[i]=='(') left.push(i);
            else if(s[i]=='*') star.push(i);
            else{

                if(left.size()>0) left.pop();
                else if(star.size()>0) star.pop();
                else return false;
            }
        }

        while(!left.empty() && !star.empty()){

            if(left.top()>star.top()) return false;
            left.pop();
            star.pop();
        }

        return left.empty();
    }
};
