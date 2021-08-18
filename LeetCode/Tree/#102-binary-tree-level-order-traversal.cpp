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
    void bfs(TreeNode* root, vector<vector<int>> &arr, int depth) {
        if(root == NULL) return;
        if(arr.size() <= depth) {
            arr.push_back({});
        }
        arr[depth].push_back(root->val);
        cout << root->val << endl;
        
        bfs(root->left, arr, depth+1);
        bfs(root->right, arr, depth+1);
        
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> arr;
       
        
        bfs(root, arr, 0);
        
        return arr;
        
        
        
    }
};