class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(); // this will give Number of rows
        if(r == 0){
            return 0;
        }
        int c = matrix[0].size(); // this will give number of columns
        
        //converting the same matrix to integer format
        vector<vector<int>> mat(r+1,vector<int>(c)); 
        for(int i=1;i<=r;i++){
            for(int j=0;j<c;j++){
                mat[i][j] = matrix[i-1][j]=='1'?1:0;
            }
        }
        
//         forming another matrix dp to store the maximum area
        vector<vector<int>> dp(r+1,vector<int>(c));
        
        int mx = 0; //for stroing the max area found till now
        
        for(int i=0;i<=r;i++){
            
//             find the left just like histogram
            int leftBound = -1;
            stack<int> st;
            vector<int> left(c);
            
            for(int j=0;j<c;j++){
                
            
            
            if(mat[i][j]==1){
                mat[i][j]=1+mat[i-1][j];
                while(!st.empty() && mat[i][st.top()]>=mat[i][j]){
                    st.pop();
                }
                int val = leftBound;
                
                if(!st.empty()){
                    val = max(val,st.top());
                }
                left[j] = val;
            } else {
                leftBound = j;
                left[j] = 0;
            }
            st.push(j);
        }
        
        
        while(!st.empty()){
            st.pop();
        }
        
        int rightBound = c;
        for(int j=c-1;j>=0;j--){
            if(mat[i][j]!=0){
                while(!st.empty() && mat[i][st.top()]>=mat[i][j]) {
                    st.pop();
                }
                int val = rightBound;
                if(!st.empty()){
                    val = min(val,st.top());
                }
                dp[i][j] = mat[i][j]*((val-1)-(left[j]+1)+1);
                mx = max(mx,dp[i][j]);
                st.push(j);
            } else {
                dp[i][j] = 0;
                rightBound = j;
            }
            }
        }
        return mx;
    }
};