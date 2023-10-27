/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    void makeParents( TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parentCheck )
    {
        queue<TreeNode*>queue ;
        queue.push( root ) ;
        
        while ( !queue.empty() )
        {
            
            TreeNode* curr = queue.front() ;
            queue.pop() ;
                
            if( curr->left != NULL )
            {
                parentCheck[curr->left] = curr ;
                queue.push( curr->left ) ;
            }
                
            if( curr->right != NULL )
            {
                parentCheck[curr->right] = curr ;
                queue.push( curr->right ) ;
            }
               

        }
    }
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int> ans ;
        unordered_map<TreeNode*,TreeNode*>parentCheck ;
        unordered_map<TreeNode*,bool> visited ;
        makeParents( root, parentCheck ) ;
        
        
        queue<TreeNode*>queue ;
        queue.push( target ) ;
        visited[target] = true ;
        int distance = 0 ;
        
        while ( !queue.empty() )
        {
            if ( distance == k )    break ;
            int l = queue.size() ;
            
            while( l-- )
            {
                TreeNode* curr = queue.front() ;
                queue.pop() ;
            
                if ( curr->left && !visited[curr->left] )
                {
                    queue.push(curr->left) ;
                    visited[curr->left] = true ;
                }
                
            
                if ( curr->right && !visited[curr->right] )
                {    queue.push(curr->right) ;
                     visited[curr->right] = true ;
                }
                
                
                if ( parentCheck[curr] && !visited[parentCheck[curr]] )
                {
                    queue.push(parentCheck[curr]) ;
                    visited[parentCheck[curr]] = true ;
                }
                
            }
            
            distance++ ;
            
        }
        while ( !queue.empty() )
        {
            TreeNode* a = queue.front() ;
            queue.pop() ;
            ans.push_back( a->val ) ;
        }
        return ans ;
    }
};