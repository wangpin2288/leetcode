class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> strV(numRows,"");
        int i=0;
        while(i<s.size())
        {
            for(int j=0; j<numRows; j++)
            {
                if(i<s.size()) strV[j].push_back(s[i++]);
            }
            for(int j=numRows-2; j>=1; j--)
            {
                if(i<s.size()) strV[j].push_back(s[i++]);
            }
        }
        string res="";
        for(string str : strV)
            res += str;
        return res;
    }
};
