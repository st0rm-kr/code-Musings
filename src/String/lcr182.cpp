#include <string>
#include <algorithm>

namespace lcr182 {
class Solution {
 public:
  std::string dynamicPassword(std::string password, int target) {
    std::reverse(password.begin(), password.end());
    std::reverse(password.begin(), password.begin() + password.size() - target);
    std::reverse(password.begin() + password.size() - target, password.end());
    return password;
  }
};
}  // namespace lcr182