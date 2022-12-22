#include "../utils.hpp"

bool isPalindrome(int x) {
    //edge case: x < 0 or x is modulus of base 10.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int lo = x; int hi = 0;
    while (lo > hi) {
        hi = hi*10 + lo%10;
        lo /= 10;
    }
    cout << "\tlo=\t" << lo << "\thi=\t" << hi << "\t";

    return lo==hi || lo==hi/10;
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
  vector<int> input = {1, 121, 123, 124421, 15, 36063};
  for (auto x: input) {
      cout << x << "\t isPalindrome() -->" << (isPalindrome(x) ? "True" : "False") << endl;
  }
  return 0;
}
