class Solution {
public:
    
    bool check(int x,vector<int>& price,int k){
        int last = price[0], count = 1,i =1;
        while(count < k && i<price.size()){
            if(price[i]-last>=x){
                last = price[i],count++;
            }
            i++;
        }
        return count==k;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int lo=0;
        int high = INT_MAX;
        while(lo<high){
            int mid = lo + (high-lo)/2;
            if(check(mid,price,k)) lo = mid+1;
            else {
                high = mid;
            }
        }
        return lo-1;
    }
};