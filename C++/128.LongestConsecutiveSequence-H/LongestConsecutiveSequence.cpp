class Solution {
/*
private:
    vector<int> unionSet;
    int find(int m){
        while(m!=unionSet[m]){
            m = unionSet[m];
        }
        return m;
    }
    void unionS(int m, int n){
        int rootM = find(m);
        int rootN = find(n);
        unionSet[rootN] = rootM;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        unordered_map<int, int> count;
        unionSet = vector<int>(nums.size());
        int len = 0;
        
        for(int i=0; i<nums.size(); ++i) unionSet[i] = i;
        for(int i=0; i<nums.size(); ++i){
            if(hashmap.find(nums[i])!=hashmap.end()) continue;
            if(hashmap.find(nums[i]-1)!=hashmap.end()){
                unionS(hashmap[nums[i]-1], i);
            }
            if(hashmap.find(nums[i]+1)!=hashmap.end()){
                unionS(hashmap[nums[i]+1], i);
            }
            hashmap[nums[i]] = i;
        }
        for(int i=0; i<unionSet.size(); ++i) unionSet[i] = find(i);
        for(int i=0; i<unionSet.size(); ++i) count[unionSet[i]]++;
        for(auto it = count.begin(); it != count.end(); it++) len = max(len, it->second);
        return len;
    }
    */
//We use hashmap. The key point is to keep track of the consecutive sequence length, and store that in the boundary of the consecutive sequence. 
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> len;
        int left, right, curLen;
        int maxLen = 0;
        for(int i=0; i<nums.size(); ++i){
            //if duplicate, ignore
            if(len.find(nums[i])!=len.end()) continue;
            //if n-1 and n+q exist, this means there is a consecutive sequence next to n, and we can update the sequence length. 
            left = (len.find(nums[i]-1)!=len.end())? len[nums[i]-1]:0;
            right = (len.find(nums[i]+1)!=len.end())? len[nums[i]+1]:0;
            curLen = left+right+1;
            len[nums[i]-left] = curLen;
            len[nums[i]+right] = curLen;
            len[nums[i]] = curLen;
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};
