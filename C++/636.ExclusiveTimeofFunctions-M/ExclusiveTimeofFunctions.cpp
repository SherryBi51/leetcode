//exclusive time: the total running time of funtion id
//We use stack. if start, push; if end, pop;
//when we finish one function, we calculate the duration, and update the previous log.
//eg. if start+start+end, then we minus the current duration from the outer one.

class Solution {
public:
    vector<string> split(string log){
        vector<string> res(3, "");
        int index1=0, index2=0;
        while(index1<log.size() && log[index1]!=':') index1++;
        res[0] = log.substr(0,index1);
        index2 = index1+1;
        while(index2<log.size() && log[index2]!=':') index2++;
        res[1] = log.substr(index1+1, index2-index1-1);
        res[2] = log.substr(index2+1);
        //cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
        return res;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> stk;
        stack<int> otherTime;
        vector<int> time(n, 0);
        int pre = 0;
        for(string log: logs){
            vector<string> logContent = split(log);
            if(logContent[1]=="start"){
                stk.push({stoi(logContent[0]), stoi(logContent[2])});
            }
            else if(logContent[1]=="end"){
                auto startLog= stk.top();
                stk.pop();
                int duration = stoi(logContent[2]) - startLog.second + 1;
                time[startLog.first] += duration;
                if (!stk.empty())
                    time[stk.top().first] -= duration;
            }
        }
        return time;
    }
};
