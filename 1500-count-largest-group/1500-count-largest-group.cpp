class Solution {
public:
    int sumOfDigit(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num%10;
            num = num / 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int,int> umap;
        int count = 0;

        for(int i=1;i<=n;i++) {
            int sum = sumOfDigit(i);
            umap[sum]++;
        }

        int maxFreq = 0;
        for(auto x:umap) {
            if(x.second > maxFreq){
                maxFreq = x.second;
            }
        }

        for(auto x:umap) {
            if(x.second == maxFreq) {
                count++;
            }
        }

        return count;
    }
};