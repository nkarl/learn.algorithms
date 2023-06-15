fn my_print(vec: &[i32]) {
    for x in vec {
        print!("{} ", x);
    }
}

fn search(nums: &Vec<i32>, target: i32) -> i32 {
    let mut lo = 0;
    let mut hi = nums.capacity() - 1;

    while lo <= hi {
        let m = lo + (hi - lo) / 2;
        if target < nums[m] {
            hi = m - 1;
        } else if target > nums[m] {
            lo = m + 1;
        } else {
            return m as i32;
        }
    }
    return i32::MIN;
}

fn search_re(nums: &[i32], lo: usize, hi: usize, target: i32) -> i32 {
    if lo > hi {
        return i32::MIN;
    }

    let m = lo + (hi - lo) / 2;
    if target < nums[m] {
        return search_re(nums, lo, m - 1, target);
    } else if target > nums[m] {
        return search_re(nums, m + 1, hi, target);
    } else {
        return m as i32;
    }
}

fn main() {
    let nums: Vec<i32> = vec![-1, 0, 2, 5, 9, 11];
    my_print(&nums);
    let res = search(&nums, 5);
    let res_re = search_re(&nums, 0 as usize, nums.capacity(), 5);
    println!("\n{}", res);
    println!("\n{}", res_re);
}
