class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> ans;
        int st = 1, end = n;

while (st < end) {
    if (nums[st-1] + nums[end-1] == target) {  // offset by -1 when accessing
        ans.push_back(st);
        ans.push_back(end);
        break;
    } else if (nums[st-1] + nums[end-1] < target) {
        st++;
    } else {
        end--;
    }
}
    return ans;
    }
};