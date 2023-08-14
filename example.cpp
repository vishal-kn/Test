int n = a.size();
    int m = a[0].size();
    int maxLen = 0;
  
    // Create a dp table to store the maximum good length
    // ending at each cell
    vector<vector<int>> dp(n, vector<int>(m, 0));
  
    // Iterate over the a to fill the dp table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the current cell is 1, then it can be part
            // of a good length square a
            if (a[i][j] >= 1) {
                // Minimum good length ending at current cell
                // is 1 (as the cell itself is a 1x1 a)
                dp[i][j] = 1;
  
                // Check if the previous row and column can
                // be part of a larger good length square a
                if (i > 0 && j > 0) {
                    // Minimum good length ending at current cell
                    // is the minimum of the lengths ending at the
                    // previous row, previous column, and the
                    // previous diagonal cell
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
  
                // Update the maximum good length
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
  
    return maxLen;