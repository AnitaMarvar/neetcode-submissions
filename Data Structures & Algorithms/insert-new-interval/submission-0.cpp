class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);

        sort(intervals.begin(),intervals.end());

        for(auto it : intervals)
        {
            if(ans.empty() || ans.back()[1] < it[0])
            {
                ans.push_back(it);
            } 
            else{
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
        }
        return ans;
    }
};
