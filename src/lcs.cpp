#include <Rcpp.h>

using namespace Rcpp;

// Function to find the longest common substring between two strings
// [[Rcpp::export]]
std::string longest_common_substring(const std::string& s1, const std::string& s2) {
  int m = s1.size() + 1;
  int n = s2.size() + 1;
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
  int longest = 0, x_longest = 0;

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > longest) {
          longest = dp[i][j];
          x_longest = i;
        }
      } else {
        dp[i][j] = 0;
      }
    }
  }

  return s1.substr(x_longest - longest, longest);
}
