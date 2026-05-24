class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;

        unordered_map<int,int>mp;
        for(int x : nums)
        {
            mp[x]++;
        }

        //maxheap {cnt, ele}
        priority_queue<pair<int,int>>pq;

        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        while(k--)
        {
            int ele = pq.top().second; //ele;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;


    }
};
