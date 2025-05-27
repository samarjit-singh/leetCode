class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sumOfN = n*(n+1) / 2;
        int sumOfAp = 0;

        for(int i=1;i<=n;i++) {
            if(i%m==0) sumOfAp+=i;
        }

        return sumOfN - sumOfAp - sumOfAp;
    }
};