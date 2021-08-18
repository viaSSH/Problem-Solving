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
    bool ans = false;
    
    bool secondDfs(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) {
            cout << "double end" << endl;
            return true;
        }
        if(!root || !subRoot) {
            cout << "single end" << endl;
            return false;
        }
        cout << "second dfs : " << root->val << " , " << subRoot->val << endl;
        
        if(root->val != subRoot->val) {
            cout << "diff" << endl;
            return false;
        }
        return secondDfs(root->left, subRoot->left) & secondDfs(root->right, subRoot->right);
    }
    
    void dfs(TreeNode* root, TreeNode* subRoot) {
        if(!root || ans) return;
        cout << root->val << endl;
        if(root->val == subRoot->val) {
            if(secondDfs(root, subRoot)){
                cout << "Same Tree" << endl;
                ans = true;
                return;
            }
        }
        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root, subRoot);
        return ans;
    }
};