class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        // int count = 0;
        // int ans;
        // while(pq.size() > 0){
        //     int t = pq.top();
        //     pq.pop();
        //     count++;

        //     if(count == k){
        //          ans = t;
        //     }
        // }
        // return ans;

        for(int i=0; i<k-1; i++){
            pq.pop();
        }

        return pq.top();
    }
};