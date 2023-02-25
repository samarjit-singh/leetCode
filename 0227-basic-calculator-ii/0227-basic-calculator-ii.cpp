class Solution {
public:
    int calculate(string s) {
        int size = s.size(),i=0,ans = 0;
        char prevOperator = '+';
        stack<int> st;
        
        while(i<size){
            
            if(s[i] == ' '){
                i++;
                continue;
            }
            
            int num = 0;
            while(isdigit(s[i]))
                num = num*10 + (s[i++]-'0');
            if(prevOperator == '+')
                st.push(num);
            else if(prevOperator == '-')
                st.push(-num);
            else if(prevOperator == '*'){
                int x = st.top();
                st.pop();
                st.push(x*num);
            } else if(prevOperator == '/'){
                int x = st.top();
                st.pop();
                st.push(x/num);
            }
            prevOperator = s[i++];
        }
        
        while(st.size()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};