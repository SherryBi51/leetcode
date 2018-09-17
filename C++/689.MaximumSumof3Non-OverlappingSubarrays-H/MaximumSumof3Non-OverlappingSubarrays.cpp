//My solution is based on DP
//We locate the middle interval at [i,i+k-1], so the first interval can be found in [0, i-1], the last interval can be found in [i+k, n-1]
//maxLeftKsumPos[j] represents the starting index of max Ksum found in [0, i-1];
//maxRightKsumPos[j] represents the starting index of max Ksum found in [i+k, n-1];

//Note: kSum = sums[i]-sums[i-k];

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> maxLeftKsumPos(nums.size(), 0);
        vector<int> maxRightKsumPos(nums.size(), 0);
        vector<int> sums(nums.size(), 0);
        vector<int> pos(3,0);
        int curSum = 0;

        for(int i=0; i<nums.size(); ++i){
            curSum += nums[i];
            sums[i] = curSum;
        }
        
        //calculate maxLeftKsumPos[j] based in DP
        maxLeftKsumPos[k-1] = 0;
        for(int i=k, preMax = sums[k-1]; i<nums.size(); ++i){
            if(preMax>=sums[i]-sums[i-k]) maxLeftKsumPos[i] = maxLeftKsumPos[i-1];
            else{
                preMax = sums[i]-sums[i-k];
                maxLeftKsumPos[i] = i-k+1;
            }
        }
        //calculate maxRightKsumPos[j] based in DP
        for(int i=nums.size()-k, preMax=0; i>0; --i){
            if(preMax>=sums[i+k-1]-sums[i-1]) 
                maxRightKsumPos[i] = maxRightKsumPos[i+1];
            else{
                preMax = sums[i+k-1]-sums[i-1];
                maxRightKsumPos[i] = i;
            }
        }
        
        //start: [0, k-1][k,2k-1][2k,xxx]
        //end: [xxx,n-2k-1][n-2k,n-k-1][n-k,n-1]
        int max3Sum = 0;
        for(int i=k; i<=nums.size()-2*k; ++i){
            int leftIndex = maxLeftKsumPos[i-1];
            int rightIndex = maxRightKsumPos[i+k];
            if(max3Sum<sums[i+k-1]-sums[i-1]+sums[leftIndex+k-1]-sums[leftIndex-1]+sums[rightIndex+k-1]-sums[rightIndex-1]){
                pos[0] = leftIndex;
                pos[1] = i;
                pos[2] = rightIndex;
                max3Sum=sums[i+k-1]-sums[i-1]+sums[leftIndex+k-1]-sums[leftIndex-1]+sums[rightIndex+k-1]-sums[rightIndex-1];
            }
        }
        return pos;
    }
};
