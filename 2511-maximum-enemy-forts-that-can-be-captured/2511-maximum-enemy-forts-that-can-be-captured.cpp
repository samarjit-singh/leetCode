class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        for(int i=0;i<forts.size();i++){
            int count=0;
            for(int j=i+1;j<forts.size();j++){
                if(forts[i]==1 && forts[j]==-1){
                    ans=max(ans,count);
                }
                if(forts[i]==-1 && forts[j]==1){
                    ans = max(ans,count);
                }
                if(forts[j]!=0){break;}
                count++;
            }
        }
        return ans;
        
    }
};