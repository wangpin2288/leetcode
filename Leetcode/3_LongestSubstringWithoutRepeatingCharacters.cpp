class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int sz = 1;
        int i=0;
        for(int j=0;j<s.size();j++){
            for(int k=i;k<j;k++){
                if(s[k]==s[j]) i = k+1;
            }
            sz = max(sz,j-i+1);
        }
        return sz;
    }
};
