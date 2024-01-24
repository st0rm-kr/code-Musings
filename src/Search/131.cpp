#include <vector>
#include <string>

namespace l131 {
class Solution {
 public:
  void dfs(int startIndex, const std::string &s) {
    if (startIndex >= s.size()) {
      result.push_back(path);
      return;
    }
    for (int i = startIndex; i < s.size(); ++i) {
      if (isPalindrome(s, startIndex, i)) {
        path.push_back(s.substr(startIndex, i - startIndex + 1));
      } else {
        continue;
      }
      dfs(i + 1, s);
      path.pop_back();
    }
  }
  std::vector<std::vector<std::string>> partition(std::string s) {
    dfs(0, s);
    return result;
  }

 private:
  std::vector<std::string> path{};
  std::vector<std::vector<std::string>> result{};
  static bool isPalindrome(const std::string &s, int i, int j) {
    for (; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
  }
};
}