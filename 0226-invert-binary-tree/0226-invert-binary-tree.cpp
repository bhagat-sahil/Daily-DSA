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


    void findans( TreeNode* ans, TreeNode* root )
    {
        if ( root == NULL )  return ;


        if ( root->right != NULL )
        {
            TreeNode* lChild ;
            lChild = new TreeNode(root->right->val) ;
            ans->left = lChild ;
        }

        if ( root->left != NULL )
        {
            TreeNode* rChild ;
            rChild = new TreeNode(root->left->val) ;
            ans->right = rChild ;

        }


        findans( ans->right, root->left ) ;
        findans( ans->left, root->right ) ;

    }

    TreeNode* invertTree(TreeNode* root)
    {
        if ( root == NULL )     return root ;
        TreeNode* ans = new TreeNode( root->val ) ;
        findans( ans, root ) ;
        return ans ;    
    }
};