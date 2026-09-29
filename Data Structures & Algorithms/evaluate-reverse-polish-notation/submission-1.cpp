class Solution {
public:

    bool isOperator(string s){

        return s == "+" || s == "-" || s=="*" || s=="/";
    }

    int evalRPN(vector<string>& t) {

        stack<int> s;

        for(auto c : t){

            if(!isOperator(c)){

                int ele = stoi(c);

                s.push(ele);
            }
            else{

                long long c1 = s.top();
                s.pop();
                long long c2 = s.top();
                s.pop();

                long long ele;

                if(c=="+"){
                    ele = c1+c2;
                }
                else if(c=="-"){
                    ele = c2-c1;
                }
                else if(c=="*"){
                    ele = c1*c2;
                }
                else if(c=="/"){
                    ele = c2/c1;
                }

                s.push(ele);
            }
        }

        return s.top();
    }
};
