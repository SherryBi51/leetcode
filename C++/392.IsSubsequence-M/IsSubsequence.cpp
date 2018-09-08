class Solution {
public:
    /*
    //Two pointer.
    bool isSubsequence(string s, string t) {
        int i, j;
        for(i=0, j=0; i<s.size() && j<t.size(); j++){
            if(s[i]==t[j]) i++;
        }
        if(i==s.size()) return true;
        else return false;
    }
    */
    
    //If there are lot of incoming S, and the string t is very long, then it won't be a good choice to use two pointer method, in which the long string t for each S.
    //So, I want to store the positions for each letter in a map, and for each distince letter, the vector of positions can be sorted. And fortunitily, there are only lower cases, so only 26 distince letters exsit in string t;
    bool isSubsequence(string s, string t){
        //In the first step, we construct the map.
        vector<vector<int>> map(26, vector<int>());
        for(int i=0; i<t.size(); ++i){
            map[t[i]-'a'].push_back(i);
        }
        //In the second step, for each letter, we find its smallest position in T, which is bigger than the position of the last letter.
        int lastPos = -1;
        for(char ch: s){
            auto it = upper_bound(map[ch-'a'].begin(), map[ch-'a'].end(), lastPos);
            if(it == map[ch-'a'].end()) return false;
            lastPos = *it;
        }
        return true;
    }
};
