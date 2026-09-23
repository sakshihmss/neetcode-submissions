class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string str = "";
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i]))
                str += s[i];
        }
        cout<<str<<endl;
        int i = 0, j = str.length()-1;
        while(i <= j)
        {
            if(tolower(str[i]) != tolower(str[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
