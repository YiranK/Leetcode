class Solution {
public:
    int climbStairs(int n) {
        int steps[n+1];
        steps[0] = 1;
        steps[1] = 1;

        for (int i = 2; i <= n; i++) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        return steps[n];
    }
};


class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        int prestep = 2;
        int preprestep = 1;
        int curstep;

        for (int i = 3; i <= n; i++) {
            curstep = prestep + preprestep;
            preprestep = prestep;
            prestep = curstep;
        }
        return curstep;
    }
};
