class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size(); // take the size of string
        stack<char> st;  // declare a stack
        
        
//         lets take eg 1432219 and k = 3
        
        for(char c:num){ // run the for loop
//             if stack is not empty and k value is greater than 0 
//             and if stack top is greater than element in the string
            while(!st.empty() && k>0 && st.top()>c){ 
                st.pop();
                k -= 1;
            }
            if(!st.empty() || c!='0'){
                st.push(c);
            }
        }
        while(!st.empty() && k--){
            st.pop();
        }
        
        if(st.empty()){
            return "0";
        }
        
        while(!st.empty()){
            num[n-1] = st.top();
            st.pop();
            n -= 1;
        }
        
        return num.substr(n);
        
    }
};

// time and space complexity  - O(n)
