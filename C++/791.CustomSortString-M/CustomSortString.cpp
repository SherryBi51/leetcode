//Use a hashmap to record the frequency of character in string T.
//Scan the string S, output the character in hashmap by the order of S.
//Output the rest characters in hashmap.

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> hashmap(26, 0);
        string res = "";
        for(char ch: T) hashmap[ch-'a']++;
        for(char ch: S){
            while(hashmap[ch-'a']!=0){
                res.push_back(ch);
                hashmap[ch-'a']--;
            }
        }
        for(int i=0; i<26; ++i){
            while(hashmap[i]){
                res.push_back('a'+i);
                hashmap[i]--;
            }
        }
        return res;
    }
};
