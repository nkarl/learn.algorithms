#include "../utils.cpp"

bool isBadVersion(int v) {
    return true;
}

int search(vector<int>& nums, int target) {
    int lo=0, hi=nums.size()-1;

    while (lo <= hi) {
      int m = lo+(hi-lo)/2;

      if (isBadVersion(m)) hi=m-1;
      else                 lo=m+1;
    }

    return lo;
}

int main(int argc, char* argv[]) {

    vector<int> nums = { -1, 0, 2, 5, 9, 11 };
    //vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int target = 5;
    myPrint(nums); // before

    int res = search(nums, target);
    printf("\nindex of target: %d\n", res);

    myPrint(nums); // after
    return 0;
}
