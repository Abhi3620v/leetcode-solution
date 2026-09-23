class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int index;
        

        for(int i=0; i<n; i++){
            index = abs(nums[i]) - 1;
            if(nums[index] > 0){
                nums[index] = -nums[index];
            } else {
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
    }
};