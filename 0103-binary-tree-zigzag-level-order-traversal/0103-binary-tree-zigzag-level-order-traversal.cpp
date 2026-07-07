/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        vector<vector<int>> v;
        int i = 0;
        if (root)
            s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            v.push_back({});
            bool flag = 1;
            while (!s1.empty()) {
                TreeNode* node = s1.top();
                v[i].push_back(node->val);
                if (node->left)
                    s2.push(node->left);
                if (node->right)
                    s2.push(node->right);
                s1.pop();
                flag=0;
            }

            while (!s2.empty() && flag) {
                TreeNode* node = s2.top();
                v[i].push_back(node->val);
                if (node->right)
                    s1.push(node->right);
                if (node->left)
                    s1.push(node->left);
                s2.pop();
            }

            i++;
        }
        return v;
    }
};