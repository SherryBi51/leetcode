//1. First, we need to sort the vector. 
//2. I use three pointers. i points is initiated to the first position, j points to the item next to i, k points to the last item of the vector.
//3. In the for loop of i, for each i, if the sum of (i,j,k) is small than the target, which means (i,j,k-1) (i,j,k-2)... also smaller than the target. So we get a count of k-j, and then move j to the next item; Else if the sum of (i,j,k) is larger than the target, we need to move k to the left item, so that the sum can be a little bit samller.
then we get k-j counts.  
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        int i, j, k;
        sort(nums.begin(), nums.end());
        for(i=0; i<(int)nums.size()-2; ++i){
            j = i+1;
            k = nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]<target){
                    count += k-j;
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return count;
    }
};
