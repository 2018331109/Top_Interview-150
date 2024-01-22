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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        int f=0;
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root!=nullptr)
        {
            q.push(root);
        }
        
        while(!q.empty())
        {
            int n=q.size();
            vector<int>v;
            for(int i=0;i<n;i++)
            {
                TreeNode* x=q.front();
                q.pop();
                v.push_back(x->val);
                if(x->left != nullptr)
                {
                    q.push(x->left);
                }
                if(x->right != nullptr)
                {
                    q.push(x->right);
                }

            }
            if(f==0)
            {
                ans.push_back(v);
            }
            else
            {
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }

            f^=1;
        }

        return ans;
        
    }
};
