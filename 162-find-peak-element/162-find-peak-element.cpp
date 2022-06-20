class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        
        while(start < end){
            int mid = start + (end-start) / 2;
            if(arr[mid]>arr[mid+1]){
//                 means you are in decreasing part of array
//                 so this may be the answer, but look left
//                 this is why end != mid-1
                end = mid;
            } else {
//                 you are in ascending part of array
                start = mid+1;
            }
        }
//         in the end , start == end and pointing to the largest number beacause of the 2 check above
//         start and end are always trying to find the max element in the above 2 checks
//         hence, they are ponting to just one element, that is the max one
        return start;
    }
};