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
    unordered_map<int, int> m; // store index of inorder
    TreeNode* solve(vector<int>&postorder, int s, int e, int&idx){
        if(s > e) return nullptr;
        TreeNode* root = new TreeNode(postorder[idx]);
        int i = m[postorder[idx]];
        idx--;
        root->right = solve(postorder, i+1, e, idx);
        root->left = solve(postorder, s, i-1, idx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        for(int i=0;i<n;++i){
            m[inorder[i]] = i;
        }
        int idx = n-1;
        return solve(postorder, 0, n-1, idx); // start, end, idx
    }
};