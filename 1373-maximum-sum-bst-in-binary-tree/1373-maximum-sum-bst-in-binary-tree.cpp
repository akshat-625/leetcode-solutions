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
    vector<int> find(TreeNode* root, int& ans){
        if(!root) return {0, INT_MAX, INT_MIN, 0};
        vector<int> left=find(root->left, ans);
        vector<int> right=find(root->right, ans);

        if(left[0] || right[0] || left[2]>=root->val || right[1]<=root->val) return {1, INT_MAX, INT_MIN, 0};
        int temp=left[3]+right[3]+root->val;
        ans=max(ans,temp);

        return {0,min(left[1],root->val),max(right[2],root->val),temp};
    } 
    int maxSumBST(TreeNode* root) {
        int ans=0;
        find(root,ans);
        return ans;
    }
};