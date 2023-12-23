class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        queue<pair<string,int>>q ;
        q.push({beginWord,1}) ;
        unordered_set<string> st(wordList.begin(),wordList.end()) ;
        int m = beginWord.size() ;
        st.erase(beginWord) ;
        while( !q.empty())
        {
            int step = q.front().second ;
            string word = q.front().first ;
            string temp = word ;
            q.pop() ;
            if ( word == endWord )  return step ;
            for ( int i = 0 ; i < m ; i++ )
            {
                for ( char letter = 'a' ; letter <= 'z' ; letter++ )
                {
                    word[i] = letter ;
                    if ( st.find(word) != st.end())
                    {
                        st.erase(word) ;
                        q.push({word,step+1}) ;
                        
                    }
                }
                word = temp ;
            }
        }
        return 0 ;
    }
};