class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = 0, high = 1.0;
        
        while(low < high){
            double mid = (low+high)/2;
            
            double max_fraction = 0.0; // for storing the maximum fraction
            
            int total = 0, p = 0 , q = 0; //p and q are used for storing the indices of max fraction
            
            int j = 1;
            
            for(int i = 0 ; i < n-1; i++){
                while(j<n && arr[i]>mid*arr[j]){
                    j++;
                }
                total += (n-j);
                
                if(j==n){
                    break;
                }
                
                double f = static_cast<double>(arr[i]) / arr[j];
                
                if(f>max_fraction){
                  p = i;
                  q = j;
                  max_fraction = f;
                }
            }
            if (total == k)
                return {arr[p], arr[q]};
            else if (total > k)
                high = mid;
            else
                low = mid;
            
        }
        return {};
    }
};