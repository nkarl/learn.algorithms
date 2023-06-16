#include "../utils.cpp"

bool isPalindrome(int x) {
    // edge case: x < 0 or x is modulus of base 10.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int lo= x, hi= 0;
    while (lo > hi) {
        hi= hi * 10 + lo % 10;
        lo/= 10;
    }
    printf("\tlo=\t%d\thi=\t%d\t", lo, hi);

    return lo == hi || lo == hi / 10;
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<int> input= {1, 121, 123, 124421, 15, 36063};
    for (auto x : input) {
        printf("%d\t isPalindrome() -->%s\n", x, (isPalindrome(x) ? "True" : "False"));
    }
    return 0;
}
