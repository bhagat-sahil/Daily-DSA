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

    void findans( TreeNode* root, int &ans, bool leftLeaf )
    {
        if ( root->left == NULL && root->right == NULL )
        {
            if ( leftLeaf == true ) ans = ans + root->val ;
            return ;
        }
        if ( root->left != NULL )   findans ( root->left, ans, true ) ;
    
        if ( root->right != NULL )  findans( root->right, ans, false ) ;
    }


    int sumOfLeftLeaves(TreeNode* root) 
    {
        int ans = 0 ;
        findans( root, ans , false ) ;
        return ans ;
    }

};