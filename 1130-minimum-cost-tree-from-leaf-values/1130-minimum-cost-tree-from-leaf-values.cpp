class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        st.push(INT_MAX);
        int res = 0;
        
        for(int i:arr){
            while(st.top()<i){
                int temp = st.top();
                st.pop();
                res = res+( temp * min(st.top(),i) );
            }
                
            st.push(i);
        }
        
        while(st.size()>2){
            int temp = st.top();
            st.pop();
            res = res+(temp*st.top());
        }
        return res;
    }
};