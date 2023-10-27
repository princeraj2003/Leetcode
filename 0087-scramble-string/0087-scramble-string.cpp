class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        int n = s1.length();
        if (n != s2.length()) {
            return false;
        }
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return isScrambleHelper(s1, s2, 0, 0, n, dp);
    }
    
    bool isScrambleHelper(string& s1, string& s2, int i, int j, int len, vector<vector<vector<int>>>& dp) {
        if (dp[i][j][len] != -1) {
            return dp[i][j][len];
        }
        if (s1.substr(i, len) == s2.substr(j, len)) {
            return dp[i][j][len] = true;
        }
        vector<int> count(26, 0);
        for (int k = 0; k < len; k++) {
            count[s1[i + k] - 'a']++;
            count[s2[j + k] - 'a']--;
        }
        for (int k = 0; k < 26; k++) {
            if (count[k] != 0) {
                return dp[i][j][len] = false;
            }
        }
        for (int k = 1; k < len; k++) {
            if ((isScrambleHelper(s1, s2, i, j, k, dp) && isScrambleHelper(s1, s2, i + k, j + k, len - k, dp)) ||
               (isScrambleHelper(s1, s2, i, j + len - k, k, dp) && isScrambleHelper(s1, s2, i + k, j, len - k, dp))) {
                return dp[i][j][len] = true;
            }
        }
        return dp[i][j][len] = false;
    }
};