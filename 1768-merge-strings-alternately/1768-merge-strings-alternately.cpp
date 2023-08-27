class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n;
        if(word1.length()<=word2.length())
        {
            n=word1.length();
        }
        else if(word2.length()<=word1.length())
        {
            n=word2.length();
        }
        int i;
        string res="";
        for(i=0;i<n;i++)
        {
            res=res+word1[i]+word2[i];
        }
        while(i<word1.length())
        {
            res=res+word1[i];
            i++;
        }
        while(i<word2.length())
        {
            res=res+word2[i];
            i++;
        }
        return res;
    }
};