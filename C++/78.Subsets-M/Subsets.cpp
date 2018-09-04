//The tail recursion is used. We manipulate the start position of candidate nums, add one item to the tail, and get the new subset.
//In each recurtion, we first store the former subset, and then add one of the candidate items to the tail, update the start position and step into the next recursion. 
class Solution {
public:
    void helper(vector<int>& nums, int start, vector<int>& oneset, vector<vector<int>>&sets){
        sets.push_back(oneset);
        if(start==nums.size()) return;
        for(int i=start; i<nums.size(); ++i){
            oneset.push_back(nums[i]);
            helper(nums, i+1, oneset, sets);
            oneset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subSets;
        vector<int> oneset;
        helper(nums, 0, oneset, subSets);
        return subSets;
    }
};
