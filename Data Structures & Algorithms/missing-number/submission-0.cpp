class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        set<int>sets(nums.begin(),nums.end());
        for(int i = 0;i<=n;i++)
        {
            if(sets.find(i) == sets.end())
            {
                return i;
            }
        }
        return -1;
    }
};
