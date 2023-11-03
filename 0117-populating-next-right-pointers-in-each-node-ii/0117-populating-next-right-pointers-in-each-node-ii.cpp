/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if ( root == NULL ) return root ;
        queue<Node*>queue ;
        queue.push( root ) ;
        while (!queue.empty() )
        {
            vector<Node*>temp ;
            int l = queue.size() ;
            while ( l-- )
            {
                Node* curr = queue.front() ;
                queue.pop() ;
                
                temp.push_back( curr ) ;
                
                if( curr->left != NULL )    queue.push( curr->left ) ;
                if( curr->right != NULL )    queue.push( curr->right ) ;
                
            }
            
            for ( int i = 0 ; i < temp.size() ; i++ )
            {
                if ( i != temp.size() - 1  )    temp[i]->next = temp[ i + 1 ] ;
                else temp[i]->next == NULL ;
            }
        }
        return root ;
    }
};