class Solution {
public:
    /*
    //DP
    //Scan from left to right, record the max height ever met in leftMax[i]
    //Scan from right to left, record the max height ever met in rightMax[i]
    //For each position, the water at that position is min(leftMax[i-1], rightMax[i+1])-height[i]
    
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);
        int total = 0;
        
        leftMax[0] = height[0];
        for(int i=1; i<height.size(); ++i){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        
        rightMax[height.size()-1] = height[height.size()-1];
        for(int i=height.size()-2; i>=0; --i){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        
        for(int i=1; i<height.size()-1; ++i){
            total += max(0, min(leftMax[i-1], rightMax[i+1]) - height[i]);
        }
        return total;
    }
    */
    /*
    //Two Pointers
    //We use two pointers, left pointer start from 0, right pointer start from n-1
    //if height[left]<=height[right], we move left, maintain a the maxLeftHeight(maxLeftHeight is smaller than height[right])，and the water stored at this position is maxLeftHeight-height[left]
    //if height[right]<height[left], we move right;
    //left and right meet at the max Height 
    
    int trap(vector<int>& height){
        if(height.size()<=2) return 0;
        
        int leftMax = height[0], rightMax = height[height.size()-1];
        int leftIndex = 0, rightIndex = height.size()-1;
        int total = 0;
        
        while(leftIndex<rightIndex){
            if(height[leftIndex]<=height[rightIndex]){
                leftIndex++;
                if(leftMax>=height[leftIndex]){
                    total += leftMax-height[leftIndex];
                }
                else leftMax = height[leftIndex];
            }
            else{
                rightIndex--;
                if(rightMax>=height[rightIndex]){
                    total += rightMax-height[rightIndex];
                }
                else rightMax = height[rightIndex];
            }
        }
        return total;
    }
    */
    
    //stack
    int trap(vector<int>& height){
        if(height.size()<=2) return 0;
        stack<int> dStk;
        int total = 0;
        
        for(int i=0; i<height.size(); ++i){
            if(dStk.empty() || height[i]<=height[dStk.top()]){
                dStk.push(i);
            }
            else{
                while(dStk.size()>1 && height[i]>height[dStk.top()]){
                    int mid = dStk.top();
                    dStk.pop();
                    total += (min(height[i],height[dStk.top()])-height[mid])*(i-dStk.top()-1);
                }
                if(dStk.size()==1 && height[i]>height[dStk.top()]){
                    dStk.pop();
                    dStk.push(i);
                }
                else{
                    dStk.push(i);
                }
            }
        }
        return total;
    }
};
