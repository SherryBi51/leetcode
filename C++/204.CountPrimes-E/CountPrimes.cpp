class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, true);
        int count = 0;
        //If 2 is the prime number, then 4, 6, 8, ..., every multiply of 2 is not prime number.
        //If 3 is the prime number, then 9, 12, 15, ..., every multiply of 2 is not prime number.
        for(int i=2; i<=n; ++i){
            if(!isPrime[i]) continue;
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
        for(int i=2; i<=n; ++i){
            if(isPrime[i]) count++;
        }
        return count;
    }
};
