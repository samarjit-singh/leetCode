class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int l = nums.size(),r = 0,temp;
        
//         this is for storing the start index
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                temp = st.top();
                st.pop();
                l = min(l,temp);
            }
            cout<<"l "<<l<<endl;
            st.push(i);
        }
        
        for(int i = nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                temp = st.top();
                st.pop();
                r = max(r,temp);
            }
            cout<<"r "<<r<<endl;
            st.push(i);
        }
        
        if(r==0 && l==nums.size()) return 0;
        
        return r-l+1;
    }
};