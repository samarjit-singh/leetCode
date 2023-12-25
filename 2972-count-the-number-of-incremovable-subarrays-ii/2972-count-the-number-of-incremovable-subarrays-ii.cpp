class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
    int left = 0, right = n - 1;
    long long ways = 0;
    //decrement right to extreme such that nums[right:end] is increasing
    while (right > 0 and nums[right-1] < nums[right]) right--;

    //trivial case where whole array is strictly increasing =>
    //we need to return here, because not to bother about edge cases
    if (right == 0) return n*(n+1)/2;

    //now nums[0:x] is removable, where x = right -1 to n - 1;
    ways += (n - right + 1);
    
    while (left < n) {
        //increment right such that {nums[start:left] U nums[right:end]} is increasing        
        while (right < n and nums[left] >= nums[right]) right++;

        //now nums[left+1:x] is removable, where x = right -1 to n-1
        ways += (n - right + 1);

        //make sure nums[start:left] is increasing in the next step
        if (left == n-1 or nums[left] < nums[left+1]) {
            left++;       
        }
        else {
            break;
        }           
    }

    return ways;   
    }
};