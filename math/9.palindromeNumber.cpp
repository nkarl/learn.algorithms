#include "../utils.hpp"

bool isPalindrome(int x) {
    //edge case: x < 0 or x is modulus of base 10.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int head = x; int tail = 0;
    while (head > tail) {
        tail = tail * 10 + head % 10;
        head /= 10;
    }
    cout << "\thead=\t" << head << "\ttail=\t" << tail << "\t";

    return head == tail || head == tail / 10;
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
