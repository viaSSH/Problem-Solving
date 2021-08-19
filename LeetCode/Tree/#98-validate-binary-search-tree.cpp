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
    
    vector<int> res; 
    void inOrder(TreeNode* root) {
        
        if(root == NULL) return; // Base Condition
        inOrder(root->left); // Left subtree
        res.push_back(root->val); // Keep pushing elements in in-order manner
        inOrder(root->right); // Right subtree
    }
    
    bool isValidBST(TreeNode* root) {
        
        inOrder(root);
        
        for(int i=1 ; i< res.size() ; i++) {
            if(res[i] <= res[i-1]) return false;
        }
        
        return true;
    }
};