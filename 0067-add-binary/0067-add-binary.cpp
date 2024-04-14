class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1 , j = b.size()-1 ;
        int c = 0 ;
        
        
        string ans = "" ;
        while ( i >= 0 && j >= 0 )
        {
            cout<<int(a[i]-'0')<<" " ;
            cout<<int(b[j]-'0')<<" " ;
            cout<<c<<endl ;
            
            if ( int(a[i]-'0') + int(b[j]-'0') + c == 0 )
            {
                 cout<<"1"<<endl ;
                c = 0 ;
                ans = "0" + ans ;
            }
            else if ( int(a[i]-'0') + int(b[j]-'0') + c == 1 )
            {
                cout<<"2"<<endl ;
                c = 0 ;
                ans = "1" + ans ;
            }
            else if ( int(a[i]-'0') + int(b[j]-'0') + c == 2 )
            {
                cout<<"3"<<endl ;
                c = 1 ;
                ans = "0" + ans ;
            }
            else if ( int(a[i]-'0') + int(b[j]-'0') + c == 3 )
            {
                cout<<"4"<<endl ;
                c = 1 ;
                ans = "1" + ans ;
            }
            i-- ;
            j-- ;
        }
        while ( i >= 0 )
        {
            if ( int(a[i]-'0') + c == 0 )
            {
                c = 0 ;
                ans = "0" + ans ;
            }
            else if ( int(a[i]-'0') + c == 1 )
            {
                c = 0 ;
                ans = "1" + ans ;
            }
            else if ( int(a[i]-'0') + c == 2 )
            {
                c = 1 ;
                ans = "0" + ans ;
            }
            i-- ;                 
                
        }
        while ( j >= 0 )
        {
            if ( int(b[j]-'0') + c == 0 )
            {
                c = 0 ;
                ans = "0" + ans ;
            }
            else if ( int(b[j]-'0') + c == 1 )
            {
                c = 0 ;
                ans = "1" + ans ;
            }
            else if ( int(b[j]-'0') + c == 2 )
            {
                c = 1 ;
                ans = "0" + ans ;
            }
            j-- ;                 
                
        }
                     
        if ( c == 1 )
            ans = "1" + ans ;
        return ans ;
    }
};