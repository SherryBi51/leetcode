/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//In the recursive function, we return the local max path sum start from current node to one of its child.
//In the recursive function, we also maintain a globa max path sum.
//Every variable in the class should be initialized in the function!!

class Solution {

private:
    int globalMaxPath;
public:
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int leftmax = helper(root->left);
        int rightmax = helper(root->right);
        int local = max(root->val, root->val+ max(leftmax, rightmax));
        globalMaxPath = max(globalMaxPath, max(local, root->val+leftmax+rightmax));
        return local;
    }
    int maxPathSum(TreeNode* root){
        globalMaxPath = INT_MIN;
        helper(root);
        return globalMaxPath;
    }
/*
    int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode*, int> localMaxPath;
        stack<TreeNode*> stk;
        TreeNode *pre=root, *cur=root;
        if(root!=NULL) stk.push(root);
        int leftmax, rightmax;
        int local;
        
        while(!stk.empty()){
            cur = stk.top();
            if((cur->left==NULL&&cur->right==NULL) ||
               (cur->right==NULL&&pre==cur->left) ||
               pre==cur->right){
                leftmax = (cur->left==NULL)?0:localMaxPath[cur->left];
                rightmax = (cur->right==NULL)?0:localMaxPath[cur->right];
                local = max(cur->val, cur->val+max(leftmax, rightmax));
                globalMaxPath = max(globalMaxPath, max(local, cur->val+leftmax+rightmax));
                localMaxPath[cur] = local;
                stk.pop();
                pre = cur;
            }
            else{
                if(cur->right) stk.push(cur->right);
                if(cur->left) stk.push(cur->left);
            }
        }
        
        return globalMaxPath;
    }
*/
};
