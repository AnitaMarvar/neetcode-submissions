class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length())return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i=0;i<s1.length();i++)
        {
            int ind = s1[i] - 'a';
            freq1[ind]++;
        }

        //first window
        int k = s1.length();
        for(int i = 0;i<k;i++)
        {
            int ind = s2[i] - 'a';
            freq2[ind]++;
        }
        if(freq1 == freq2)return true;

        for(int i = k;i<s2.length();i++)
        {
            int addWala = s2[i] - 'a';
            freq2[addWala]++;
            int removeWala = s2[i-k] - 'a';
            freq2[removeWala]--;
            if(freq1 == freq2)return true;
        }
        return false;
    }
};
