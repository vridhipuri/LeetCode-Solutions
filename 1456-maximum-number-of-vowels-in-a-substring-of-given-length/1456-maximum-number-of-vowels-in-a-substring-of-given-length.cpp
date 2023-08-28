class Solution {
public:
    int maxVowels(string s, int k) {
        /*vector<int>ans;
        
        for(int i=0;i<=s.length()-k;i++)
        {
            int count=0;
            string sub=s.substr(i,i+k);
            for(int j=0;j<k;j++)
            {
                if(sub[j]=='a' || sub[j]=='e' || sub[j]=='i' ||
                sub[j]=='o' || sub[j]=='u')
                {
                    count++;
                }
            }
            ans.push_back(count);
        } 
        int maxi=ans[0]; 
        for(int i=0;i<ans.size();i++)
        {
            if(maxi<ans[i])
            {
                maxi=ans[i];
            }
        }
        return maxi; */

        int count=0;
        unordered_set<char>vowels={'a','e','i','o','u'};
        for(int i=0;i<k;i++)
        {
            if(vowels.find(s[i])!=vowels.end())
            {
                count++;
            }
        }
        int maxi=count;
        int start=0;
        int end=k-1;
        while(end<s.length()-1)
        {
            if(vowels.find(s[start])!=vowels.end())
            {
                count--;
            }
            start++;
            end++;
            if(vowels.find(s[end])!=vowels.end())
            {
                count++;
            }
            maxi=max(count,maxi);
        }
        return maxi;
    }
};