class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, currmax = 0, currmin = 0, totalsum = 0, kadansmax = INT_MIN, kadansmin = INT_MAX ;

        for(int i=0; i<n; i++){
            totalsum += nums[i];
            currmax += nums[i];
            kadansmax = max(kadansmax, currmax);
            if(currmax < 0){
                currmax = 0;
            }

            currmin += nums[i];
            kadansmin = min(kadansmin, currmin);
            if(currmin > 0){
                currmin = 0;
            }
        }

        if(kadansmax < 0){
            return kadansmax;
        }

        int circularsum = totalsum - kadansmin;
        ans = max(kadansmax, circularsum);

        return ans;
    }
};