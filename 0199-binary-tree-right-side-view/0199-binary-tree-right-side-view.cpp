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
    
    
    
    
    vector<int> levelOrder( TreeNode* root, vector<int> &ans ) 
    {
        
        if ( root == NULL )     return ans ;
        queue<TreeNode*>queue ;
        queue.push( root ) ;

        while ( !queue.empty() )
        {
            int len = queue.size() ;
            vector<int>temp ;
            while ( len-- )
            {
                TreeNode* currNode = queue.front() ;
                queue.pop() ;
                temp.push_back( currNode->val ) ;

                if ( currNode->left != NULL )   queue.push( currNode->left ) ;
                if ( currNode->right != NULL )   queue.push( currNode->right );
            }
            ans.push_back( temp [ temp.size() - 1 ] ) ;
        }
        return ans ;
        
    }
    
    
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans ;
        levelOrder( root, ans ) ;
        return ans ; 
    }
};