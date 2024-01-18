#include <string>
#include <unordered_map>
#include <vector>

namespace l17 {
class Solution {
public:
  void search(const std::string &str, size_t pos, std::string &path) {
    if (path.size() == n_ && path.size() > 0) {
      res_.push_back(path);
    }
    if (pos >= str.size()) {
      return;
    }

    auto &alphas = map_[str[pos]];
    for (auto alpha : alphas) {
      path.push_back(alpha);
      search(str, pos + 1, path);
      path.pop_back();
    }
  }
  std::vector<std::string> letterCombinations(std::string digits) {
    n_ = digits.size();
    std::string t;
    search(digits, 0, t);
    return res_;
  }

private:
  size_t n_{};
  std::vector<std::string> res_{};
  std::unordered_map<char, std::string> map_{
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
  };
};
} // namespace l17