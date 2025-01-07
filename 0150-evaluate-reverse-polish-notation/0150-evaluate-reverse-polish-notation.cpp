class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for(const auto& token : tokens){
            if (isdigit(token[0]) || (token.size() > 1)) { // or case is for negative number 
                stack.push(stoi(token));
            } else {
                int first = stack.top();
                stack.pop();
                
                int second = stack.top();
                stack.pop();

                if(token == "+"){
                    stack.push(second + first);
                } else if(token == "*"){
                    stack.push(second * first);
                } else if(token == "-"){
                   stack.push(second - first);
                } else if(token == "/"){
                    stack.push(second / first);
                } 
            }
        }


        return stack.top();
    }
};