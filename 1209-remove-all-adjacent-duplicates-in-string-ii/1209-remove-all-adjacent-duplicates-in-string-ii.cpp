class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>>st;
        for(int index = 0; index < s.size(); index++)
        {
            if(!st.empty() && st.top().first == s[index])
            {
                st.top().second++;
                if(st.top().second == k)
                    st.pop();
            }
            else
                st.push({s[index],1});
        }
        string ans = "";
        while(!st.empty())
        {
            int count = st.top().second;
            while(count--)
                ans += st.top().first;
            st.pop();
        }
        
        reverse(ans.begin(),ans.end()) ;
        return ans ;
    } 
};