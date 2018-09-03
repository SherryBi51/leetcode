//We manipulate target and candidates to indicate whether current result meets the requirement. 
//In each recursion, we choose one item in the candidates. 
//Since the same repeated number may be chosen from candidates unlimited number of times, so in the next recursion, the candidates still start in the same position. 

class Solution {
public:
    void helper(vector<int>& candidates, int start, vector<int>& oneres, vector<vector<int>>& combinations, int target){
        if(target==0){
            combinations.push_back(oneres);
            return;
        }
        else if(start==candidates.size()) return;
        
        for(int i=start; i<candidates.size(); ++i){
            if(candidates[i]>target) break;
            oneres.push_back(candidates[i]);
            helper(candidates, i, oneres, combinations, target-candidates[i]);
            oneres.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> oneres;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, oneres, combinations, target);
        return combinations;
    }
};
