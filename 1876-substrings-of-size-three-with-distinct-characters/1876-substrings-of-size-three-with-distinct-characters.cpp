class Solution {
public:
    int countGoodSubstrings(string s) {
        
        if(s.length()<3)
        {
            return 0;
        }
        int count = 0;
        for (int i = 0; i <= s.length() - 3; i++) {
            string str = s.substr(i, 3);
            unordered_map<char, int> freq;
            bool flag = true;
            for (char ch : str) {
                freq[ch]++;
                if (freq[ch] > 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
        return count;
    }
};