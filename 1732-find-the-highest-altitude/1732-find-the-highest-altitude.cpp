class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> arr(gain.size());
        arr.push_back(0);
            
        for(int i=0;i<gain.size();i++){
            arr[i+1] = arr[i]+gain[i];
        }    
    
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        
        int maxEle = *max_element(arr.begin(), arr.end());
        
        return maxEle > 0 ? maxEle : 0;
    }
};