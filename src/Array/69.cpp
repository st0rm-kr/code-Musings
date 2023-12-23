namespace L69 {

class Solution {
 public:
  double Sqrt(double x) {
    static constexpr double eps = 1e-5;
    double l = 0.0, r = x;
    while (r - l > eps) {
      double mid = (l + r) / 2;
      if (mid <= x / mid) l = mid;
      else r = mid;
    }
    return r;
  }
  int mySqrt(int x) {
    return Sqrt(x);
  }
};
}  // namespace L69