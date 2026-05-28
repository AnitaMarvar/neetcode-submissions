class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        
        for(int i =0;i<s.length();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                char smallCase = s[i] +32;
                str += smallCase;
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                str += s[i];
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                str += s[i];
            }
            else{
                continue;
            }
        }
        int l=0;
        int r=str.length()-1;
        while(l <= r)
        {
            if(str[l] != str[r])return false;
            else{
                l++;
                r--;
            }
        }
        return true;
    }
};
