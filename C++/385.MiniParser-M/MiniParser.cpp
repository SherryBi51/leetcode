/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

//1. I have a stack of NestedInteger.
//2. We scan the string. 
//2.1 When we meet '['(open parenthesis), then we push a new NestedInteger into the stack. 
//2.2 When we meet ']'(close parenthesis), then we pop the top one, and add it to the previous NestedInteger.

//Noted: void add(const NestedInteger &ni);
//corner case: "123", "[123]"
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.size()==0) return NestedInteger();
        stack<NestedInteger> stk;
        stk.push(NestedInteger());
        int start;
        string sub;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '['){
                stk.push(NestedInteger());
            }
            else if(s[i]==']'){
                auto tmp = stk.top();
                stk.pop();
                stk.top().add(tmp);
            }
            else if(s[i] == '-' || s[i] >='0'&&s[i]<='9'){
                start = i;
                while(i<s.size() && (s[i] >='0'&&s[i]<='9' || s[i]=='-')) i++;
                sub = s.substr(start, i-start);
                stk.top().add(NestedInteger(stoi(sub)));
                i--;
            }
            else{
                continue;
            }
        }
        return stk.top().getList().front();
    }
};
