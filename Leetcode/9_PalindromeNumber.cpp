class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int y = 0;
        int temp = x;
        while(temp){
            y = y*10 + temp%10;
            temp /= 10;
        }
        return x==y;
    }
};
