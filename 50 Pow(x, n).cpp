class Solution {
public:
    double ppow(double x, long n) {
        if (n == 1) return x;
        if (n == 0) return 1;
        if (n < 0) {
            x = 1/x;
            n = -n;
        }
        if (n % 2 == 0) {
            return ppow(x * x, n/2); 
        } else {
            return x * ppow(x * x, n/2); 
        }
    }
    
    double myPow(double x, int n) {
        return ppow(x, (long)n);
    }
};

// x*x is Divide and Conquer
// And you don't necessarily need to flip the sign of n because at the end if n < 0 all you need to do is make the final answer ans = 1/ans.
// the value of n has to be carefully handled when n equals to Integer.MIN_VALUE. Hence, better method is to convert n to data type of long