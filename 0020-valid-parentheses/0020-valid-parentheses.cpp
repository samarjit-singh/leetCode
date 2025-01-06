class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        stack.push(s[0]);
        if(s.size() == 1){
            return false;
        }

        for(int i=1;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push(s[i]);
            } else if(stack.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')) {
                return false;
            } else {
                // s[i] could be { , [ , (
                char top = stack.top();

                if(stack.empty()) return false;
                
                if(s[i] == ')'){
                    if(top == '(') {
                        stack.pop();
                    }
                } else if(s[i] == '}'){
                    if(top == '{') {
                        stack.pop();
                    }
                } else if(s[i] == ']'){
                    if(top == '[') {
                        stack.pop();
                    }
                } 

                stack.pop();
            }
        }


        return stack.empty() ? true : false;
    }
};