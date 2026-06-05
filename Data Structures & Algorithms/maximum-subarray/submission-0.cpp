class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane

        int maxSum = INT_MIN;
        int currSum = 0;

        for(int x : nums)
        {
            currSum = max(x, currSum + x);
            maxSum = max(maxSum , currSum);
        }
        return maxSum;
        
    }
};
