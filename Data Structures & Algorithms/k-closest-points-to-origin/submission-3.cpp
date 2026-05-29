class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //minheap
        vector<vector<int>>ans;
        priority_queue<P, vector<P>, greater<>>pq;

        for(auto it : points)
        {
            int x = it[0];
            int y = it[1];
            int dist = pow(x,2) + pow(y,2);
            pq.push({dist, {x,y}});
        }

        int cnt=0;
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            ans.push_back({x,y});
            cnt++;
            if(cnt==k)
            {
               break;
            }
        }
        return ans;
    }
};
