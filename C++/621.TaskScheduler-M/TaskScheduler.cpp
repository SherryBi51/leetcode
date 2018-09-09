//I think the key point is to find how many idle do we need.
//And we can arrange the task with most frequency first. For example ...
//So, the final intervals can only be determined by the number of most frequency task and its frequency. And for those tasks which is not the most frequency one, they can just fill out the idle intervals, or insert in a non-idle pipeline.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxN = 0;
        vector<int> cnt(26, 0);
        for(char ch: tasks){
            cnt[ch-'A']++;
        }
        sort(cnt.begin(), cnt.end());
        while(maxN<26 && cnt[25]==cnt[25-maxN]) maxN++;
        return max(int(tasks.size()), (cnt[25]-1)*(n+1)+maxN);
    }
};
