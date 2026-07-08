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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }

    TreeNode* build(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>& mp){
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }
        TreeNode* node=new TreeNode(preorder[preStart]);
        int inRoot=mp[preorder[preStart]];
        int numsleft=inRoot-inStart;

        node->left=build(preorder,preStart+1,numsleft+preStart,inorder,inStart,inRoot-1,mp);
        node->right=build(preorder,preStart+numsleft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        return node;

    }
};