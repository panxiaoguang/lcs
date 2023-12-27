#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
std::string longest_common_substring(std::string s1, std::string s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    std::vector<std::vector<int>> m(len1 + 1, std::vector<int>(len2 + 1, 0));

    int longest = 0, x_longest = 0;
    for (int x = 1; x <= len1; ++x) {
        for (int y = 1; y <= len2; ++y) {
            if (s1[x - 1] == s2[y - 1]) {
                m[x][y] = m[x - 1][y - 1] + 1;
                if (m[x][y] > longest) {
                    longest = m[x][y];
                    x_longest = x;
                }
            } else {
                m[x][y] = 0;
            }
        }
    }

    return s1.substr(x_longest - longest, longest);
}