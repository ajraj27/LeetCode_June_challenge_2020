/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int util(TreeNode* root,int res){
        if(root==NULL) return 0;
        
        res=res*10+root->val;
        
        if(root->left==NULL && root->right==NULL) return res;
        
        return util(root->left,res)+util(root->right,res);
    }
    
    int sumNumbers(TreeNode* root) {
        return util(root,0);    
    }
};