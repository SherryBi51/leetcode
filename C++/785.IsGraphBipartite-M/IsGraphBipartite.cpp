//divide the vertices into part -1 and part 1, and we record it in a hashmap
//use queue to store the vertices that need to be divide and check;

//Noted that there may be some disconnection in the given graph

//For example, [[1,2,3], [0,2], [0,1,3], [0,2]]
//If 0 in part A, then 123 should in part B
//If 1 is in part B, then 02 should in part A, and we got a contradiction.


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> part(graph.size(), 0);
        queue<int> vertices;
        int cur, pre;
        
        for(int i=0; i<graph.size(); ++i){
            if(part[i]==0){
                part[i] = -1;
                vertices.push(i);
                while(!vertices.empty()){
                    cur = vertices.front();
                    vertices.pop();
                    pre = part[cur];
                
                    for(int vi: graph[cur]){
                        if(part[vi]==-pre) continue;
                        else if(part[vi]==pre) return false;
                        else{
                            part[vi]=-pre;
                            vertices.push(vi);
                        }
                    }
                }
            }
        }
        return true;
    }
};
