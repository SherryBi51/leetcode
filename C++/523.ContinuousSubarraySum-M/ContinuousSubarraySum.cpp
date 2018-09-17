//This is a dynamic programming problem. We maintain a sum of subarray, and a remainer of sum divide k in the DP process.
//If we get a repeated remainer, this means the required subarray has been found. For example, in ""[23,2,4,6,7], k=6", when i=0, the sum is 23, remainer is 5; when i=1, sum=25, remainer=1; when i=2, sum=29, remainer=5. 5 show up again, and this means [2, 4] sum up to n*6.

//Note that the size of subarray is at least 2.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //I use a set to store the remainer that has showed up.
        unordered_set<int> modK;
        int sum = 0;
        int mod = 0;
        //I use a variable pre, to store the remainer showed up last time. 
        int pre = 0;
        
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i];
            mod = (k==0)?sum:sum%k;
            if(modK.find(mod)!=modK.end()) return true;
            modK.insert(pre);
            pre = mod;
        }
        return false;
    }
};
