class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> testMap; //testmap is used as hashing
        int x = 0, y = 0;
        for (int k = 0; k < nums.size(); k++) {
            x = nums[k]; //x takes the element in the array 
            y = target - x; // y takes the difference 
            if (testMap.find(y) != testMap.end()) {
                return {testMap[y],k};
            }
            testMap[x] = k;
        }
        return {-1,-1};
    }
};