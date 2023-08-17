class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        vector<vector<int>>ans;
        
        sort(arr.begin(),arr.end());
        
        vector<int>temp;
        for(int i=0;i<arr.size()-1;i++)
        {
            temp.push_back(arr[i+1]-arr[i]);
        }
        int mini=INT_MAX;
        for(int i=0;i<temp.size();i++)
        {
            mini=min(mini,temp[i]);
        }
        for(int i=0;i<temp.size();i++)
        {
            vector<int>res;
            if(temp[i]==mini)
            {
                res.push_back(arr[i]);
                res.push_back(arr[i+1]);
            }
            else{
                continue;
            }
            ans.push_back(res);
        }
        return ans;
    }
};