// Forward declaration of the knows API.
bool knows(int a, int b);

//celebrity: he knows no one, but everyone knows him. 
//only one candidate can be found;

//1. find the candidate
//1.1 if A knows B, then A cannot be a candidate, and B can be a candidate.
//2. verify

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for(int i=0; i<n; ++i){
            if(!knows(i, candidate)){
                candidate = i;
            }
        }
        for(int i=0; i<n; ++i){
            if(i==candidate) continue;
            if(knows(i,candidate) && !knows(candidate, i)) continue;
            else return -1;
        }
        return candidate;
    }
};
