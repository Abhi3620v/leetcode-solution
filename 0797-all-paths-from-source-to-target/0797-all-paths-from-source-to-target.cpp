class Solution {
public:
    void helper(vector<vector<int>>& graph, int src, int dest,  vector<vector<int>>& ans, vector<int>& ans1){
        if(src == dest){
            ans1.push_back(dest);
            ans.push_back(ans1);
            ans1.pop_back();
            return;
        }
        ans1.push_back(src);

        for(int v : graph[src]){
                helper(graph, v, dest, ans, ans1);
        }
        ans1.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> ans1;
        helper(graph,0, n-1, ans, ans1);
        return ans;
    }
};