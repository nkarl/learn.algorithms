#include "../utils.hpp"

int removeDuplicates(vector<int> &nums) {
    int k = 1;
    for (int c = 1; c < nums.size(); ++c) {
        cout << "for=" << c << "; k=" << k << endl;
        cout << "nums[" << c << "]==" << nums[c] << "; "
             << "nums[" << k << "]==" << nums[k];
        if (nums[c - 1] != nums[c]) {
            cout << "\tswapping" << endl;
            nums[k] = nums[c];
            cout << "\t\t";
            myPrint(nums);
            ++k;
        }
        else {
            cout << endl
                 << "\t\t";
            myPrint(nums);
        }
        cout << endl;
    }
    return k;
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int         val  = 3;
    myPrint(nums);  // before
    int c = removeDuplicates(nums);
    myPrint(nums);  // after
    for (int i = 0; i < c; ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}
