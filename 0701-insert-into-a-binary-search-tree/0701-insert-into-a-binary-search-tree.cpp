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
    
    void insertBST( TreeNode* root, int val )
    {
        
        if ( root->val < val )  
        {
            if ( root->right != NULL )  insertBST( root->right, val ) ;
            else 
            {
                TreeNode* node = new TreeNode( val ) ;
                root->right = node ;
            } 
        }
        if ( root->val > val )
        {
            if ( root->left != NULL )   insertBST( root->left, val ) ;
            else 
            {
                TreeNode* node = new TreeNode( val ) ;
                root->left = node ;
            }
        }
    }
    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if ( root == NULL )     
        {
            TreeNode* node = new TreeNode( val ) ;
            return node ;
            
        }
        insertBST( root, val ) ;
        return root ;
    }
};