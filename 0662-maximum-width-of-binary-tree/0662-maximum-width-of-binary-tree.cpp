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
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair<TreeNode*,unsigned long long>> q;
        q.push({root,1});                           //use unsigned LL as it uses only +ve but doubles the range
        unsigned long long first=0,last=0,width=0;
        while (!q.empty()){
            int size=q.size();
            for (int i=0;i<size;i++){
                auto [node,ind]=q.front();     //optimal o(n) o(width)
                q.pop();
                if (node->left) q.push({node->left,(ind*2)-1});
                if (node->right) q.push({node->right,ind*2});
                if (i==0) first=ind;
                if (i==size-1) last=ind;
            }
            width=max(width,last-first+1);
        }
        return width;
    }
};