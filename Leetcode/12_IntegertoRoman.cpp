class Solution {
public:
    vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	vector<string> tens = {"", "X", "XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	vector<string> hunds = {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	vector<string> thous = {"", "M","MM","MMM"};
    
    string intToRoman(int num) {
    
        if(num < 10)
        	return ones[num];
        if(num < 100){
        	return tens[num/10]+ones[num%10];
        }
        if(num < 1000){
        	return hunds[num/100]+intToRoman(num%100);
        }
        return thous[num/1000]+intToRoman(num%1000);
        
    }
};
