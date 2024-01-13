/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
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
    map<int, int>mp;
    int n, now;
    TreeNode* helper(vector<int>& post, vector<int>& in, int st, int en)
    {
        if(now<0 || st>en)
        {
            return nullptr;
        }

        int it=mp[post[now]];
        TreeNode* node=new TreeNode(post[now]);
        now--;
        node->right=helper(post, in, it+1, en);
        node->left=helper(post, in, st, it-1);
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n=inorder.size();
        now=n-1;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* root=helper(postorder, inorder, 0, n-1);
        return root;
        
    }
};
