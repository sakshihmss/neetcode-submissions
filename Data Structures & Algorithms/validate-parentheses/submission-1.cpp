class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        unordered_map<char, char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        int i = 0;
        while(i < n)
        {
            if(st.empty())
            {
                if(s[i] == ']' || s[i] == '}' || s[i] == ')')
                    return false;
                else
                    st.push(s[i]);
            }
            else
            {
                char c = st.top();
                if(s[i] == ']' || s[i] == '}' || s[i] == ')')
                {
                    if(c == mp[s[i]])
                        st.pop();
                    else
                        return false;
                }
                else
                    st.push(s[i]);
            }
            i++;
        }
        return st.empty();
    }
};
