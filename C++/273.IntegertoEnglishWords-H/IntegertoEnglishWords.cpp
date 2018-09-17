//corner case: 0->Zero
//Important: space  (xxx?" ":"")

class Solution {
public:
    string lessThan20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",                                "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[4] = {"", " Thousand", " Million", " Billion"};
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string res = "";
        int i = 0;
        while(num){
            if(num%1000) res = helper(num%1000)+thousands[i]+(res.size()?" ":"")+res;
            num = num/1000;
            i++;
        }
        return res;
    }
    
    string helper(int num){
        if(num>=100) return lessThan20[num/100]+" Hundred"+ (num%100?" ":"")+helper(num%100);
        else if(num>=20) return tens[num/10]+(num%10?" ":"")+helper(num%10);
        else return lessThan20[num];
    }
};
