#include <vector>
#include <string>

namespace l93 {
class Solution {
 public:
  std::vector<std::string> restoreIpAddresses(std::string s) {
    if (s.size() < 4 || s.size() > 12) {
      return {};
    };
    dfs(s, 0, 0);
    return result;
  }

 private:
  std::vector<std::string> segs{};
  std::vector<std::string> result{};
  bool isValid(const std::string &s, size_t startIndex, size_t endIndex) {
    if (startIndex > endIndex) {
      return false;
    }
    if (s[startIndex] == '0' && startIndex != endIndex) {
      return false;
    }
    for (size_t i = startIndex, sum = 0; i <= endIndex; ++i) {
      if (s[i] > '9' || s[i] < '0') {
        return false;
      }
      sum = sum * 10 + s[i] - '0';
      if (sum > 255) {
        return false;
      }
    }
    return true;
  }
  void dfs(const std::string &s, size_t startIndex, size_t segments) {
    if (segments == 3) {
      if (isValid(s, startIndex, s.size() - 1)) {
        segs.push_back(s.substr(startIndex));
        std::string res;
        for (auto &str : segs) {
          res += str + ".";
        }
        res.pop_back();
        result.push_back(res);
        segs.pop_back();
      }
    }
    for (int i = startIndex; i < s.size(); ++i) {
      if (isValid(s, startIndex, i)) {
        segs.push_back(s.substr(startIndex, i - startIndex + 1));
        ++segments;
        dfs(s, i + 1, segments);
        --segments;
        segs.pop_back();
      } else {
        break;
      }
    }
  }
};
}  // namespace l93