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
    
    TreeNode* constructTree( vector<int>& preorder, int preS, int preE,
                            vector<int>& postorder, int postS, int postE, unordered_map<int,int> &m )
        
    {
        
        if ( preS > preE )  return NULL ;
        
        TreeNode* root = new TreeNode(preorder[preS]) ;
        if ( preE == preS )     return root ;       //when the array is of size one only
        
        
        int currIndex = m[preorder[preS+1]];
        
        int totEle = currIndex - postS + 1 ;
        
        
        root->left = constructTree( preorder, preS+1 , preS+totEle, postorder, postS, currIndex, m ) ;
        root->right = constructTree( preorder, preS+totEle+1 , preE, postorder, currIndex+1, postE, m ) ;
            
            
            
        return root ;
        
    }
    
    
    
    
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        int n = postorder.size() ;
        unordered_map<int,int>m;
        for(int i = 0; i < postorder.size(); i++)
            m[postorder[i]] = i;
        
        return constructTree( preorder, 0, n - 1, postorder, 0, n - 1, m ) ;
        
    }
};

