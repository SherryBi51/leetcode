//1. We have a stack of string.
//2. We scan the path, and split the path by "/(slash)". 
//2.1 When we meet '/', then we have two options. If the top item in stack is also "/", then we just skip. 
//2.2 When we get the substring between two slash, then we have three options. If it is "..", then we pop the slash and filename. If it is ".", then skip it. And if it is a filename, push it into the stack. 
//2.3 In order to make the logic easy, in each loop, if the stack is empty, just push a "/". 

//Noted: in some cases, the path end with "/", we need to ignore it.
//corner case: "/...", "/../"

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        int start;
        string sub;
        string sPath = "";
        for(int i=0; i<path.size(); ++i){
            if(stk.empty()) stk.push("/");
            if(path[i] == '/'){
                if(stk.top() != "/") stk.push("/");
            }
            else{
                start = i;
                while(i<path.size()-1 && path[i+1]!='/') i++;
                sub = path.substr(start, i-start+1);
                if(sub==".."){
                    while(!stk.empty() && stk.top()=="/") stk.pop();
                    if(!stk.empty()) stk.pop();
                    if(stk.empty()) stk.push("/");
                }
                else if(sub==".") continue;
                else stk.push(sub);
            }
        }
        if(stk.size()==1) return "/";
        if(stk.top()=="/") stk.pop();
        while(!stk.empty()){
            sPath = stk.top() + sPath;
            stk.pop();
        }
        return sPath;
    }
};
