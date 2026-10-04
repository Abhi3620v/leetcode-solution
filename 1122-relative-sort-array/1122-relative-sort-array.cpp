class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();

        vector<int> ans;
        unordered_map<int, int> m;

        for(int i=0; i<n; i++){
            m[arr1[i]]++;
        }

        for(int x : arr2){
            if(m.find(x) != m.end()){
                while(m[x] > 0){
                    ans.push_back(x);
                    m[x]--;
                }
            }
        }

        vector<int> rem;
        for (int i=0; i<n; i++){
            if(m[arr1[i]] > 0){
                rem.push_back(arr1[i]);
            }
        }

        sort(rem.begin(), rem.end());

        for(int x : rem){
            ans.push_back(x);
        }

        return ans;
    }
};