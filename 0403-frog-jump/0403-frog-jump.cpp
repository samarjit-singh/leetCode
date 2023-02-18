class Solution {
public:
    
//     this search fundtion return the index
    int search(vector<int> &st,int k){
        int l = 0;
        int r = st.size()-1;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            if(st[mid]==k){
                return mid;
            } else if(st[mid]>k){
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return -1;
    }
    
    bool find(int index,vector<int> &st, vector<vector<int>> &dp,int l){
        
        if(index == st.size()-1){ //if index is == to the last pos return true
            return 1;
        }
        
        if(dp[index][l]!=-1) // basic dp procedure
            return dp[index][l];
        
        bool r=0,s=0,t=0; // now initialize threee values for k-1, k , k+1 jumps
        
        if(l>0){ // we cannot do a jump of 0 length need to be >=1
            
            int a = search(st,st[index]+l-1);
            
            if(a!=-1){
                r=find(a,st,dp,l-1);
            }
            
            int b = search(st,st[index]+l);
            
            if(b!=-1){
                s=find(b,st,dp,l);
            }
        }
        
        
//         search the index in arry using the binary search function
        int c = search(st,st[index]+l+1);  // first this statement will be persformed
        
//         if it is present in the stones array
        if(c!=-1){
            t=find(c,st,dp,l+1); // we recursively call the function
        }
        
//         and if we get 1 from any of the 3 jumps we return 1
        return dp[index][l] = r||s||t;
        
    }
    
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(2001,vector<int>(2001,-1)); // make a dp vector for stroing the states    
        return find(0,stones,dp,0);
    }
};