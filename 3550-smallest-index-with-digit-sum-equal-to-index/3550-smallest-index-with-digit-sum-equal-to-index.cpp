class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            
            }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int digitSum = (nums[i] == 0) ? 0 : getDigitSum(nums[i]);
            if (digitSum == i) {
                return i;
            }
        }
        return -1;
    }
};