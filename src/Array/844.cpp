#include <string>

using namespace std;

namespace l844 {
class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    int n = s.size(), m = t.size();
    int i = n - 1, j = m - 1;
    int s1 = 0, s2 = 0;
    while (i >= 0 || j >= 0) {
      while (i >= 0) {
        if (s[i] == '#') {
          ++s1, --i;
        } else if (s1 > 0) {
          --s1, --i;
        } else {
          break;
        }
      }
      while (j >= 0) {
        if (t[j] == '#') {
          ++s2, --j;
        } else if (s2 > 0) {
          --s2, --j;
        } else {
          break;
        }
      }
      if (i >= 0 && j >= 0) {
        if (s[i] != t[j]) return false;
      } else {
        if (i >= 0 || j >= 0) return false;
      }
      --i, --j;
    }
    return true;
  }
};
}