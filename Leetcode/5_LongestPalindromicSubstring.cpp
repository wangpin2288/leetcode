class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        vector<vector<bool>> memo(s.size(), vector<bool>(s.size(), false));
        int start=0;
        int maxLen=1;
        for(int i=s.size()-1; i>=0; i--){
            for(int j=i;j<s.size(); j++){
                if(i==j){
                    memo[i][j]=true;
                }else if(j-i <= 2 && s[i]==s[j]){
                    memo[i][j]=true;
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        start = i;
                    }
                }else if(s[i]==s[j]){
                    memo[i][j] = memo[i+1][j-1];
                    if(memo[i][j] && j-i+1 > maxLen){
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
