class Solution {
public:
    bool isPossible(vector<int>&piles, int mid, int h)
    {
        int eat = 0;
        for(int x : piles)
        {
            eat += (x / mid);

            if(x % mid != 0)
            {
                eat++;
            }
        }

        return eat <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans=0;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(isPossible(piles, mid, h))
            {
                ans=mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
