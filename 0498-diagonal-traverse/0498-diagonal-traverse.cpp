class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;
        int r=0, c=0, dir = 1;

        for(int i=0; i<m*n; i++){
            ans.push_back(mat[r][c]);

            if(dir == 1){
                r--, c++;

                if(r < 0 && c >= n){
                    r = 1;
                    c = n-1;
                    dir = 0;
                } else if(r < 0){
                    r = 0;
                    dir = 0;
                } else if(c >= n){
                    c = n-1;
                    r += 2;
                    dir = 0;
                }
            } else {
                r++, c--;

                if(c < 0 && r >= m){
                    c = 1;
                    r = m-1;
                    dir = 1;
                } else if(c < 0){
                    c = 0; 
                    dir = 1;
                } else if(r >= m){
                    r = m-1;
                    c += 2;
                    dir = 1;
                }
            }
        }
        return ans;
    }
};