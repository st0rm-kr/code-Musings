namespace l367 {
class Solution {
 public:
  int BinarySearch(int x) {
    int l = 1, r = x;
    while (l < r) {
      int mid = l / 2 + r / 2;
      if (mid < x / mid)
        l = mid + 1;
      else
        r = mid;
    }
    return r;
  }
  bool isPerfectSquare(int num) {
    auto x = BinarySearch(num);
    return (long long)x * x == num;
  }
};
}  // namespace l367