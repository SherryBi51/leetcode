class Solution {
public:
    // KEY: use "start" to low bound the possible split in each recursion.
    void helper(vector<int>& factors, vector<vector<int>>& res, int start, int target){
        // If no more split, store the factors.
        factors.push_back(target);
        if(factors.size()>1) res.push_back(factors);
        factors.pop_back();
        //keep spliting n, the splited num is lower bounded by "start", and is upper bounded by sqrt(target)
        for(int i=start; i*i<=target; ++i){
            if(target%i==0){
                factors.push_back(i);
                helper(factors, res, i, target/i);
                factors.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> factors;
        helper(factors, res, 2, n);
        return res;
    }
};
