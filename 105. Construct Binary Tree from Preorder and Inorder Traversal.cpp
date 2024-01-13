/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
*/
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
    int n, now=0;
    map<int, int>mp;
    TreeNode* helper(vector<int>& pre, vector<int>& in, int st, int en)
    {
        if(now>=n)
        {
            return nullptr;
        }
        if(st>en)
        {
            return nullptr;
        }

        int it=mp[pre[now]];
        TreeNode* node=new TreeNode(pre[now]);
        now++;
        node->left=helper(pre, in, st, it-1);
        node->right=helper(pre, in, it+1, en);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n=inorder.size();
        TreeNode* root;
        int now=0;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        root=helper(preorder, inorder, 0, n-1);
        return root;
        
    }
};
