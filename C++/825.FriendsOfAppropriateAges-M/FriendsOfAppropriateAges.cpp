//B should in (A/2+7:A]


class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> agesNum(121, 0);
        vector<int> agesNumSum(121, 0);
        int count = 0;
        
        for(int age: ages) agesNum[age]++;
        
        agesNumSum[0] = agesNum[0]; 
        for(int i=1; i<=120; ++i){
            agesNumSum[i] = agesNum[i] + agesNumSum[i-1];
        }
        
        for(int i=0; i<=120; ++i){
            if(agesNum[i]==0) continue;
            if(i/2+7>=i) continue;
            int cur = agesNumSum[i] - agesNumSum[i/2+7];
            count += cur*agesNum[i] - agesNum[i];
        }
        return count;
        
    }
};
