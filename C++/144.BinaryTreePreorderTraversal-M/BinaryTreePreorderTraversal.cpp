/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//The preorder traversal means we first visit root, and then it left sub-tree and finally it right sub-tree.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //For this problem, I want to use stack to store the visited TreeNode. 
        stack<TreeNode*> stk;
        vector<int> preorder;
        TreeNode *cur = root;
        while(cur!=NULL || !stk.empty()){
            while(cur!=NULL){
                //First, we visit the root, and output its value;
                preorder.push_back(cur->val);
                //Then, we push the root into stack, because we want to visit its right sub-tree later.
                stk.push(cur);
                //And then, we go to this left sub-tree and start the next iteration.
                cur = cur->left;
            }
            if(!stk.empty()){
                //If the left sub-tree is empty, we pop a node and go to its right sub-tree, and start the next iteration.
                cur = stk.top();
                stk.pop();
                cur = cur->right;
            }
        }
        return preorder;
    }
};

