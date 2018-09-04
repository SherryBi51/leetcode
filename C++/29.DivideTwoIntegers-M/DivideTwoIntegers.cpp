//Suppose we want to divide 15 by 3. 
//First, we shift 3 to the left, and finally we can get 12 (4 times of 3), the largest multiply of 3 that is smaller than 16. And now, we get a result 4 (12=4*3), and remaining dividend 3 (16-12=4).
//Second, the remaining dividend is 4, and the divisor is 3. And here we got a result 1, and remaining dividend 1 (0 is smaller than 1). And 4+1=5.
//When the remaining dividend is smaller than the divisor, we just stop the loop. So the final result is 5.
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MAX && divisor==1) return INT_MAX;
        int result=0;
        bool sign = (bool(dividend>0)==bool(divisor>0));
        long long dividendabs = labs(dividend);
        long long divisorabs = labs(divisor);
        while(dividendabs>=divisorabs){
            long long temp = divisorabs, mask = 1;
            while((temp<<1)<=dividendabs){
                temp <<= 1;
                mask <<= 1;
            }
            dividendabs -= temp;
            result += mask;
        }
        return sign? result:-result;
    }
};
