class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
        // remember this writing.
        memset(prime, true, sizeof prime);
        for (int i = 2; i * i <= n; i++) {
            if (prime[i] == true) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
            
        }
        
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i] == true)
                count++;
        }
        
        return count;
    }
};

// since all the numbers can be factorized to many prime numbers, it's more effective to calculate from first prime number.
// in order to avoid duplicate calculation, we only calculte the multiple of prime number who is larger than the square of prime number.

// why ? 'if (prime[i] == true)'?
