#include "../utils.cpp"

bool palindrome(int head, int tail) {
    if (head <= tail) {
        return head == tail || head == tail / 10;
    }
    (tail*= 10)+= head % 10;
    head/= 10;
    // printf("head=%d tail=%d\n", head, tail);
    return palindrome(head, tail);
}

bool isPalindrome(int x) {
    // edge case: x < 0 or x is modulus of base 10.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    return palindrome(x, 0);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<int> input= {-10, -121, 1, 121, 123, 124421, 15, 36063};
    for (auto x : input) {
        printf("%d\t isPalindrome() -->%s\n", x, (isPalindrome(x) ? "True" : "False"));
    }
    return 0;
}
