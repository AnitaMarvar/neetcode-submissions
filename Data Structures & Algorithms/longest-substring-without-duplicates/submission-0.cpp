class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;

        unordered_map<char, int>mp;
        int l=0;
        int r=0;

        while(r < s.length())
        {
            mp[s[r]]++;

            while(mp[s[r]] > 1)
            {
                mp[s[l]]--;
                if(mp[s[l]]==0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;

    }
};
