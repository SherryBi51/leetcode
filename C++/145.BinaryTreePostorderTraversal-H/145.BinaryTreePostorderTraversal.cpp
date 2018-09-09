/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Postorder means we visit the left sub-tree first, and then the right sub-tree, and finally the root itself. So it is a little bit complex than preorder and inorder, since the visited node stored in the cannot be poped directly. The visited node can only be poped, when its right child has been traversaled.
//So the key point is to check if the node we just traversed is the right node of the current node.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> postorder;
        TreeNode *pre = root, *cur = root;
        
        if(root!=NULL) stk.push(root);
        while(!stk.empty()){
            cur = stk.top();
            if((cur->left==NULL && cur->right==NULL) ||
              (cur->right==NULL && cur->left==pre)||
              (cur->right==pre)){
                postorder.push_back(cur->val);
                pre = cur;
                stk.pop();
            }
            else{
                //Push right first, because we have to traverse left first. 
                if(cur->right) stk.push(cur->right);
                if(cur->left) stk.push(cur->left);
            }
        }
        return postorder;
    }
};
