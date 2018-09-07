//This problem is equivalent to whether there exist a cycle in the graph. I treat the courses as vertices, and treat the prerequisite pairs as edges. 
//I define 2D vector of int to store the vertices and edges. And I also define a vector<int> to record the in-degree of each vertice. 
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        queue<int> in0;
        int cur;
        //1. construct the graph from prerequisites. 
        for(auto item: prerequisites){
            in[item.first]++;
            graph[item.second].push_back(item.first);
        }
        //To find a cycle in the graph, we have to delete the vertices, whose in-degree is zero.
        //When deleting one vertices, we also need to change the in-degree of other vertices.
        //2. Delete the vertices, whose in-degree is 0. And I use a queue to store the these vertices. 
        for(int i=0; i<numCourses; ++i){
            if(in[i]==0) in0.push(i);
        }
        while(!in0.empty()){
            cur = in0.front();
            in0.pop();
            for(int vi: graph[cur]){
                in[vi]--;
                if(in[vi]==0) in0.push(vi);
            }
        }
        //3. After recursively delete the vertice, which in-degree is 0. The graph should be empty, or remain a cycle. 
        for(int i=0; i<numCourses; ++i){
            if(in[i]>0) return false;
        }
        return true;
    }
};
