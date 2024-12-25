class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() < 3){
            return 0;
        }

        int maxLen = 0;
        int i = 1;

        while(i < arr.size() - 1){

            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                int left = i-1;
                int right = i+1;

                while(left > 0 && arr[left] > arr[left - 1]){
                    left--;
                }

                while(right < arr.size() - 1 && arr[right] > arr[right + 1]){
                    right++;
                }

                maxLen = max(maxLen, right - left + 1);

                i = right;
            } else {
                i++;
            }
        }

        return maxLen;
    }
};