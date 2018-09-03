//The difference between PermutationII and PermutationI is that the items in the vector can be duplicated.
//We can also use "nums" itself for in-place permutaion. And the key point of this problem is avoiding duplicates. Here I use hashset to record the occurance of the candidate items.  
class Solution {
public:
    void helper(vector<int>& nums, int key, vector<vector<int>>& permutations){
        if(nums.size()==key){
            permutations.push_back(nums);
            return;
        }
        int pre;
        unordered_set<int> record;
        for(int i=key; i<nums.size(); ++i){
            if(record.find(nums[i])!=record.end()) continue;
            record.insert(nums[i]);
            swap(nums[i], nums[key]);
            helper(nums, key+1, permutations);
            swap(nums[i], nums[key]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        helper(nums, 0, permutations);
        return permutations;
    }
};
