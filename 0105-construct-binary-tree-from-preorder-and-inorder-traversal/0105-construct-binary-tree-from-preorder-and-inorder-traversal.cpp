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
// class Solution {
// public:
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
//     {
//         unordered_map<int,int>inMap ;
//         for ( int i = 0 ; i < inorder.size() ; i++ )    inMap[ inorder[i] ] = i ;
        
//         TreeNode* root = buildTree( preorder, 0, preorder.size() - 1,
//                    inorder, 0, inorder.size() - 1, inMap ) ;
//         return root ;
        
//     }
    
//     TreeNode* buildTree( vector<int>& preorder, int preStart, int preEnd,
//                     vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>inMap)
        
//     {
//         if ( preStart > preEnd || inStart > inEnd )     return NULL ;
        
//         TreeNode* root = new TreeNode( preorder[ preStart ] ) ;
        
//         int inRoot = inMap[ root->val ] ;
//         int numLeft = inRoot - inStart ;
        
//         root->left = buildTree( preorder, preStart + 1, preStart + numLeft,
//                                 inorder, inStart, inRoot - 1, inMap ) ;
        
//         root->right = buildTree( preorder, preStart + numLeft + 1, preEnd,
//                                 inorder, inRoot + 1, inEnd, inMap ) ;
//         return root ;
//     }
// };



class Solution {
public:
    
    TreeNode* constructTree(vector<int>& preorder,int preIndex,     
                            unordered_map<int,int>&m,int start,int end)
    {
        if(start > end || preIndex >= preorder.size())
            return NULL;
        
        int inIndex = m[preorder[preIndex]];
        
        TreeNode* root = new TreeNode(preorder[preIndex]);

        
        root->left = constructTree(preorder,preIndex+1,m,start,inIndex-1);
        root->right = constructTree(preorder,preIndex+(inIndex-start+1),m,inIndex+1,end);
    
    return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        
        return constructTree(preorder,0,m,0,inorder.size()-1);
    }
};






















