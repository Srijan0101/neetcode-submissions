class Solution {
public:

    vector<string> res;

    bool isValid(string &s){

        stack<char> st;

        for(auto it : s){

            if(it=='(') st.push(it);
            else {
                if(!st.empty() && st.top()=='(') st.pop();
                else return false;
            }
        }

        return st.empty() ? true : false;
    }

    void func(string s, int i, int size){

        if(i==size){

            if(isValid(s)) res.push_back(s);
            return;
        }

        func(s+"(", i+1, size);
        func(s+")", i+1, size);
    }

    vector<string> generateParenthesis(int n) {
        
        string s = "";

        func(s, 0, 2*n);

        return res;
    }
};
