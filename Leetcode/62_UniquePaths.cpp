class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> num(m, vector<int>(n, 0));
        num[m-1][n-1] = 1;
        for(int i=0; i<m-1;i++){
            num[i][n-1] = 1;   
        }
        for(int j=0; j<n-1;j++){
            num[m-1][j] = 1;   
        }
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                num[i][j] = num[i+1][j] + num[i][j+1];
            }
        }
        
        return num[0][0];
    }
};
