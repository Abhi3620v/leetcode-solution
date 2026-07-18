class Solution {
public:
    

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>m;
        for(int num : nums){
            if(m.count(num)){
                m[num]++;
            } else {
                m[num] = 1;
            }
        }

       sort(nums.begin(), nums.end(), [&](int a, int b) {
        if(m[a] != m[b]){
            return m[a] < m[b];
        }
        return a > b;
       });

       return  nums;
    }
};