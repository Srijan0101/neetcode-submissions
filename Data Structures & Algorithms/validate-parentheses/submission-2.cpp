class Solution {
   public:
    bool isValid(string t) {
        stack<char> s;
        for (auto it : t) {
            if (it == '(' || it == '{' || it == '[') {
                s.push(it);
            } else {
                if (s.empty()) return false;
                char top = s.top();
                if (it == ')' && top == '(')
                    s.pop();
                else if (it == '}' && top == '{')
                    s.pop();
                else if (it == ']' && top == '[')
                    s.pop();
                else
                    return false;
            }
        }
        return s.empty();
    }
};