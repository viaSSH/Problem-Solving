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
private:
    TreeNode newTree;
    int maxSum = INT_MIN;
public:
    int dfs(TreeNode* root, int sum) {
        if(root == NULL) {
            return -999999;
        }
        int value = root->val;
        
        int left, right;
        left = max(dfs(root->left, sum), 0);
        right = max(dfs(root->right, sum), 0);
        
        // cout << "left : " << left << ", right : " << right << endl;  
        int curSum = sum + value + left + right;
        if(maxSum < curSum) maxSum = curSum;
        
        return max({sum+value+left, sum+value+right, sum+value});
    }
    
    int maxPathSum(TreeNode* root) {
        
        int x = 0;
        x = dfs(root, 0); 
        // cout << "result " << x << ", " << maxSum << endl;
        return max(x, maxSum);
    }
};