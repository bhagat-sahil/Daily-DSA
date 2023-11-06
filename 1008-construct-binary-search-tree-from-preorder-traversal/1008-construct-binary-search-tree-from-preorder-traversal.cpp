/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *righ     val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    TreeNode* findans( int &i,vector<int>&preorder, int bound )
    {
        if ( i == preorder.size() || preorder[i] > bound ) return NULL ;
        
        
        TreeNode* root = new TreeNode( preorder[i++]) ;
        
        
        root->left = findans( i, preorder, root->val ) ;
        root->right = findans( i, preorder, bound ) ;
        
        
        return root ;
    }
    
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int i = 0 ;
        return findans( i,preorder, INT_MAX ) ;
    }
};