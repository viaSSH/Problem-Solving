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
    void bfs(TreeNode* root, vector<string>&ans, string curr) {
        
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            curr = curr + to_string(root->val);
            ans.push_back(curr);
        }
        else{
            curr = curr + to_string(root->val) + "->";    
        }
        
        bfs(root->left, ans, curr);
        bfs(root->right, ans, curr);
        
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        string curr = "";
        bfs(root, ans, curr); 
        return ans;
    }
};