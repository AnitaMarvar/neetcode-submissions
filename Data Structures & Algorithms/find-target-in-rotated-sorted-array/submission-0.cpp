class Solution {
public:
    int minIndexBS(vector<int>&nums)
    {
        int l=0;
        int r = nums.size()-1;
        while(l < r)
        {
            int mid = l + (r - l)/2;
            if(nums[mid] > nums[r])
            {
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return r;
    }
    int BS(vector<int>&nums, int l, int r, int tar)
    {
        int ans=-1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid]==tar)
            {
                ans = mid;
                return ans;
            }
            else if(nums[mid] > tar)
            {
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        
        //find the min ele index
        // search in first part and second part
        int n = nums.size();

        int minIndex = minIndexBS(nums);
        int first = BS(nums,0, minIndex-1, target);
        int second = BS(nums, minIndex, n-1,target);
        if(first != -1)return first;
        else if(second != -1)return second;
        return -1;
        
    }
};
