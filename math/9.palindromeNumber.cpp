#include "../utils.hpp"

bool isPalindrome(int x) {
    //edge case
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reverted = 0;
    while (x > reverted) {
        reverted = reverted * 10 + x % 10;
        x /= 10;
    }

    return reverted == x || x == reverted / 10;
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
  vector<int> input = {1, 121, 123, 124421, 15, 36063};
  /*
   * Add solution function(s) here.
   */
  for (auto x: input) {
      cout << x << "\t isPalindrome()==" << isPalindrome(x) << endl;
  }
  return 0;
}
