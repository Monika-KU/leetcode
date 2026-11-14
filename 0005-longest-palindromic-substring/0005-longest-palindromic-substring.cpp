class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            for (int l : {i, i + 1}) {
                int left = i, right = l;
                while (left >= 0 && right < n && s[left] == s[right]) {
                    if (right - left + 1 > maxLen) {
                        start = left;
                        maxLen = right - left + 1;
                    }
                    --left; ++right;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};