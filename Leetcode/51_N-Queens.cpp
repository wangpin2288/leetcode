class Solution {
private:
    vector<vector<string>> res;
    vector<bool> col;
    vector<bool> dia1;
    vector<bool> dia2;
    void putQueen(int n, int index, vector<int> &row){
        if(index==n){
            vector<string> queen = generateBoard(n, row);
            res.push_back(queen);
            return;
        }
        for(int j=0;j<n;j++){
            if(!col[j] && !dia1[index+j] && !dia2[index-j+n-1]){
                col[j]=true;
                dia1[index+j]=true;
                dia2[index-j+n-1]=true;
                row.push_back(j);
                putQueen(n, index+1, row);
                col[j]=false;
                dia1[index+j]=false;
                dia2[index-j+n-1]=false;
                row.pop_back();
            }
        }
    }

    vector<string> generateBoard(int n, vector<int>& row){
        vector<string> ret(n,string(n,'.'));
        assert(row.size()==n);
        for(int i=0;i<n;i++){
            ret[i][row[i]] = 'Q';
        }
        return ret;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n, false);
        dia2 = vector<bool>(2*n, false);
        vector<int> row;
        putQueen(n, 0, row);
        return res;
    }
};
