//We do not have to treat it as a math problem, it is too complicated.
//We use two pointers, low and high.
//If a>0, f(nums[low]) and f(nums[high]) can be bigger, so we start from the biggest one at nums.size()-1
//If a<0, f(nums[low]) and f(nums[high]) can be smaller, so we start from the smallest one at 0

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c){
        vector<int> res(nums.size(), 0);
        int low = 0, high = nums.size()-1;
        int fxl, fxr;
        int index = a>0?nums.size()-1:0;
        while(low<=high){
            fxl = fx(nums[low], a, b, c);
            fxr = fx(nums[high], a, b, c);
            if(a>0){
                if(fxl>=fxr){
                    res[index--] = fxl;
                    low++;
                }
                else{
                    res[index--] = fxr;
                    high--;
                }
            }
            else{
                if(fxl<=fxr){
                    res[index++] = fxl;
                    low++;
                }
                else{
                    res[index++] = fxr;
                    high--;
                }
            }
        }
        return res;
    }
    int fx(int x, int a, int b, int c){
        return a*x*x+b*x+c;
    }
    /*
    int findPivotIndex(vector<int>& nums, double pivot){
        int low = 0, high = nums.size()-1;
        int mid;
        while(low<high-1){
            mid = (high-low)/2+low;
            if((double)nums[mid]==pivot) return mid;
            else if((double)nums[mid]<pivot) low = mid;
            else if((double)nums[mid]>pivot) high = mid;
        }
        return (abs((double)nums[low]-pivot)<=abs((double)nums[high]-pivot))?low:high;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> fx(nums.size(), 0);
        if(a==0 && b>=0)
            for(int i=0; i<nums.size(); ++i)
                fx[i] = b*nums[i]+c;
        else if(a==0 && b<0)
            for(int i=0; i<nums.size(); ++i)
                fx[nums.size()-i-1] = b*nums[i]+c;
        else if(a>0){
            double pivot = -double(b)/double(2*a);
            int midIndex = findPivotIndex(nums, pivot);
            int x = nums[midIndex];
            fx[0] = a*x*x+b*x+c;
            for(int i=1, j=midIndex-1, k=midIndex+1; i<nums.size(); ++i){
                if(j>=0 && k<nums.size()){
                    double tmp = (nums[k]+nums[j])/2.0;
                    if(tmp<pivot) x = nums[k++];
                    else x = nums[j--];
                }
                else if(j>=0) x = nums[j--];
                else if(k<nums.size()) x = nums[k++];
                fx[i] = a*x*x+b*x+c;
            }
        }
        else if(a<0){
            double pivot = -double(b)/double(2*a);
            int midIndex = findPivotIndex(nums, pivot);
            int x = nums[midIndex];
            fx[nums.size()-1] = a*x*x+b*x+c;
            for(int i=nums.size()-2, j=midIndex-1, k=midIndex+1; i>=0; --i){
                if(j>=0 && k<nums.size()){
                    double tmp = (nums[k]+nums[j])/2.0;
                    if(tmp<pivot) x = nums[k++];
                    else x = nums[j--];
                    //cout<<"tmp"<<tmp<<"pivot"<<pivot<<endl;
                }
                else if(j>=0) x = nums[j--];
                else if(k<nums.size()) x = nums[k++];
                //cout<<x<<endl;
                fx[i] = a*x*x+b*x+c;
            }
        }
        return fx;
    }
    */
};
