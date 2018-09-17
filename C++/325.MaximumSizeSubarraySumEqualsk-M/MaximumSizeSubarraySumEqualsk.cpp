//We use hashmap to store the sum from 0~i as key, and i as value;
//We scan the vector of numbers from 0 to n-1
//Each time we find if (curSum-k) exists in hashmap. If exists, we find a subarray sum up to k, and we update the maxLen.

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        int sum = 0;
        int maxLen = 0;
        hashmap[0] = -1;
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i];
            if(hashmap.find(sum-k)!=hashmap.end()){
                maxLen = max(maxLen, i-hashmap[sum-k]);
            }
            if(hashmap.find(sum)==hashmap.end()) hashmap[sum] = i;
        }
        return maxLen;
    }
};
