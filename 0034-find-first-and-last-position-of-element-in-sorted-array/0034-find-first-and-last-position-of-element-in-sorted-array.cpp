class Solution {
public:

    int leftMostOccurance(vector<int>& nums, int target)
    {
        int n=nums.size();
        int high=n-1;
        int low=0;
        int mid;
        int i=-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                i=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
        }
        
        return i;
    }
    int rightMostOccurance(vector<int>& nums, int target)
    {
        int n=nums.size();
        int high=n-1;
        int low=0;
        int mid;
        int i=-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                i=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
        }
        
        return i;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=leftMostOccurance(nums,target);
        int y=rightMostOccurance(nums,target);
        vector<int>ans;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};