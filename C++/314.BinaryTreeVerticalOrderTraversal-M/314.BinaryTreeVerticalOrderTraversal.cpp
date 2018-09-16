/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//If current Node is in column n, so if left child is in column n-1, and it right child is in column n+1;
//1. First organize the nodes according to the column.
//2. Second we origanize the columns from left to right;
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root==NULL) return vector<vector<int>>();
        unordered_map<int, vector<int>> vertical;
        vector<vector<int>> verOrder;
        int minColumn = 0, maxColumn = 0;
        queue<pair<TreeNode*, int>> que;
        if(root!=NULL) que.push({root,0});
        
        while(!que.empty()){
            auto cur = que.front();
            que.pop();
            if(cur.first->left){
                que.push({cur.first->left, cur.second-1});
                minColumn = min(minColumn, cur.second-1);
            }
            if(cur.first->right){
                que.push({cur.first->right, cur.second+1});
                maxColumn = max(maxColumn, cur.second+1);
            }
            vertical[cur.second].push_back(cur.first->val);
        }
        
        for(int i=minColumn; i<=maxColumn; ++i){
            verOrder.push_back(vertical[i]);
        }
        
        return verOrder;
    }
};
