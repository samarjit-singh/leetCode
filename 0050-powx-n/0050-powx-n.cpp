class Solution {
public:
    
    double util(double x,long n){
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n < 0) return util(1/x,-n);
        double result = util(x*x, n /2);
        if(n%2 != 0) result *= x;
        return result;
    }
    
    double myPow(double x, int n) {
        return util(x,n);
    }
};