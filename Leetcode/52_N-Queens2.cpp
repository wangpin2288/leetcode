class Solution {
private:
    int cnt=0;
    vector<bool> col;
    vector<bool> dia1;
    vector<bool> dia2;
    void putQueen(int n, int index){
        if(index==n){
            cnt++;
            return;
        }
        for(int j=0;j<n;j++){
            if(!col[j] && !dia1[index+j] && !dia2[index-j+n-1]){
                col[j]=true;
                dia1[index+j]=true;
                dia2[index-j+n-1]=true;
                putQueen(n, index+1);
                col[j]=false;
                dia1[index+j]=false;
                dia2[index-j+n-1]=false;
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n, false);
        dia2 = vector<bool>(2*n, false);
        putQueen(n, 0);
        return cnt;
    }
};

