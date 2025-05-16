class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int maxLength = 0, left = 0;
        for (int i = 0; i < s.length(); ++i){
            if (seen.count(s[i]) && seen[s[i]] >= left){
                left = seen[s[i]] + 1;
            }
            seen[s[i]] = i;
            maxLength = max(maxLength, i - left + 1);
        }
        return maxLength;
    }
};
