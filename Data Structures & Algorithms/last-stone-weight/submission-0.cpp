class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //max heap
        priority_queue<int>maxHeap;

        for(int x:stones)
        {
            maxHeap.push(x);
        }

        while(maxHeap.size() > 1)
        {
            int top1 = maxHeap.top();
            maxHeap.pop();
            int top2 = maxHeap.top();
            maxHeap.pop();
            if(top1 != top2)
            {
                maxHeap.push(abs(top2 - top1));
            }
        }
        if(maxHeap.empty())return 0;
        return maxHeap.top();
    }
};
