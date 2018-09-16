class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(char ch: t) map[ch]++;
        int counter = t.size(), begin = 0, end = 0, head = 0;
        int minD = INT_MAX;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--;
            //if map[ch]>0 ==> the character in string t.
            while(counter==0){ //valid
                if(minD>end-begin){ //optimize
                    head = begin;
                    minD = end-head;
                }
                if(map[s[begin++]]++==0) counter++;  //make it invalid
                //if map[ch]==0 ==> the character in string t
                //if map[ch]<0 ==> the ch in string s but not t
            }
        }
        return (minD==INT_MAX)?"":s.substr(head, minD); 
    }
};
