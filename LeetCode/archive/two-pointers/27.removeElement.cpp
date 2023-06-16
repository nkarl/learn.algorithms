#include "../utils.cpp"

using std::swap;

int removeElement(vector<int> &nums, int val) {
    int k= 0;
    for (int l= 0, c= 0; c < nums.size(); ++c) {
        printf("for=%d; l=%d\n", c, l);
        printf("nums[%d]==%d; nums[%d]==%d", c, nums[c], l, nums[l]);
        if (nums[c] != val) {
            printf("\tswapping\n");
            swap(nums[l], nums[c]);
            printf("\t\t");
            myPrint(nums);
            ++l;
        }
        else {
            printf("\n\t\t");
            myPrint(nums);
        }
        printf("\n");
        k= l;
    }
    return nums.size() - (nums.size() - k);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<int> nums= {1, 0, 2, 0, 3};
    int         val = 3;
    myPrint(nums);  // before
    int c= removeElement(nums, val);
    myPrint(nums);  // after
    for (int i= 0; i < c; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
