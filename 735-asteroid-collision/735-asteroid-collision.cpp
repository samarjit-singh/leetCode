class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            if(st.empty() || asteroids[i]>0){
                st.push(asteroids[i]);
            } else {
                while(true){
                    int peek = st.top();
                    if(peek<0){
                        st.push(asteroids[i]);
                        break;
                    } else if(peek == -asteroids[i]){
                        st.pop();
                        break;
                    } else if(peek>-asteroids[i]) {
                        break;
                    } else {
                        st.pop();
                        if(st.empty()){
                            st.push(asteroids[i]);
                            break;
                        }
                    }
                }
            }
        }
        vector<int> ans(st.size());
        
        for(int i=st.size()-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};

// [-5,4,3,2,1] -4