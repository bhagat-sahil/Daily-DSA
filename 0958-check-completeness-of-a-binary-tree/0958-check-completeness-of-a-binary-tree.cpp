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
    bool isCompleteTree(TreeNode* root) 
    {
        queue<TreeNode*>queue ;
        queue.push( root ) ;
        
        while( !queue.empty() )
        {
            TreeNode* curr = queue.front() ;
            queue.pop() ;
            
            if ( curr != NULL )
            {
                queue.push( curr->left ) ;
                queue.push( curr->right ) ;
            }
            else 
            {
                while ( !queue.empty() )
                {
                    if ( queue.front() != NULL )    return false ;
                    else queue.pop() ;
                }
            }
        }
        return true ;
        
    }
};