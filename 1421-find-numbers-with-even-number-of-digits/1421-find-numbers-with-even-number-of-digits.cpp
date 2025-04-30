class Solution {
public:

    int countOfDigits(int num) {
        int count = 0;
        while (num > 0) {
            count++;
            int lastDigit = num % 10;
            num = num / 10;
        }

        return count;
    }

    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto x:nums) {
            if(countOfDigits(x) % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};