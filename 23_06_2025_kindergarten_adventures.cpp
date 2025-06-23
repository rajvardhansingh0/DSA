#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    long long min_val = a[0];
    long long max_diff = 0;

    for (int i = 1; i < n; ++i) {
      min_val = min(min_val, a[i]);
      max_diff = max(max_diff, a[i] - min_val);
    }
    cout << max_diff << endl;
  }
  return 0;
}