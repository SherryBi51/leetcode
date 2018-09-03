class Solution {
public:
    void helper(vector<int>& nums, int start, vector<vector<int>>& permutations){
        if(nums.size()==start){
            permutations.push_back(nums);
            return;
        }
        int cur;
        for(int i=start; i<nums.size(); ++i){
            swap(nums[start], nums[i]);
            helper(nums, start+1, permutations);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        helper(nums, 0, permutations);
        return permutations;
    }
};
