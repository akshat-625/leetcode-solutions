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
    unordered_map<int,int>m;
    
    TreeNode* solve(vector<int>& in, vector<int>& post,int ins,int ine,int &posti){
        if(ins>ine) return NULL;
        int v=post[posti];
        posti--;
        TreeNode*root=new TreeNode(v);
        root->right=solve(in,post,m[v]+1,ine,posti);
        root->left=solve(in,post,ins,m[v]-1,posti);
        return root;

    }
    TreeNode* buildTree(vector<int>& in,vector<int>& post) {
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
        int idx=post.size()-1; // or in.size()
        return solve(in,post,0,in.size()-1,idx);
    }
};