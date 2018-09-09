/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Inorder Traversal: left sub-tree first, root, and right sub-tree
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> inorder;
        TreeNode *cur = root;
        while(cur!=NULL || !stk.empty()){
            //1. Store the visited TreeNode in stack, since we want to visit the value and its right sub-tree later. Go to the next iteration for its left sub-tree;
            while(cur!=NULL){
                stk.push(cur);
                cur = cur->left;
            }
            //2. If the left sub-tree is empty, just pop a visited node, output its value, and go the next iteration for its right sub-tree.
            if(!stk.empty()){
                cur = stk.top();
                stk.pop();
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
        return inorder;
    }
};

