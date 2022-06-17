class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // if (letters.back() <= target) return letters.front();
        // int n = letters.size();
        // int start = 0;
        // int end = n-1;
        // while(start<=end){
        //     auto mid = (start + end)/2;
        //     if(target < letters[mid]){
        //         end = mid;
        //     } else {
        //         start = mid+1;
        //     }
        // }
        // return letters[start];
        if (letters.back() <= target) return letters.front();
        int low = 0, high = letters.size() - 1;
        while (low < high) {
            auto mid = (low + high) / 2;
            if (target < letters[mid]) high = mid;
            else low = mid + 1;
        }
        return letters[low];
    }
};