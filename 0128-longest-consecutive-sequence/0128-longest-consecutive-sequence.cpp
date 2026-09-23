class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0; 
        
        for(int x : s){
            if(s.find(x-1) != s.end()){
                continue;
            } else {
                int length = 1;
                while(s.find(x+1) != s.end()){
                    length++;
                    x++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};