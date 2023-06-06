class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> diff;
        for(int i=0;i<arr.size()-1;i++){
            diff.push_back(arr[i+1]-arr[i]);
        }
        
        for(int i=0;i<diff.size()-1;i++){
            if(diff[i]!=diff[i+1]){
                return false;
            }
        }
        
        return true;
    }
};