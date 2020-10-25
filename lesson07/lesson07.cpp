#include <iostream>
#include <vector>
using namespace std;

int min(vector<int> arr) {
    int min = 999999;
    for (auto i : arr) {
        if (i < min) {
            min = i;
        }
    }
    return min;
}
int max(vector<int> arr) {
    int max = -999999;
    for (auto i : arr) {
        if (i > max) {
            max = i;
        }
    }
    return max;
}


vector<int> array1(int n) {
    vector<int> nums = {};
    for (int i = 1; i < n * 2; i += 2) {
        nums.push_back(i);
    }
    return nums;
}
vector<int> array2(int n) {
    vector<int> nums = {};
    for (int i = 1; i <= n; i++) {
        nums.push_back(pow(2, i));
    }
    return nums;
}
vector<int> array3(int n, int a, int d) {
    vector<int> nums = {};
    int diff = 0;
    for (int i = 0; i < n; i++) {
        nums.push_back(a + diff);
        diff += d;
    }
    return nums;
}


void array11(int k, int n, vector<int> arr) {
    for (int i = 1; i * k < n; i++) {
        cout << arr[i * k] << endl;
    }
}
vector<int> array12(vector<int> arr, int n) {
    vector<int> nums = {};
    for (int i = 1; i < n; i += 2) {
        nums.push_back(arr[i]);
    }
    return nums;
}
vector<int> array13(vector<int> arr, int n) {
    vector<int> nums = {};
    for (int i = n - 1; i >= 0; i -= 2) {
        nums.push_back(arr[i]);
    }
    return nums;
}


int array18(vector<int> nums) {
    for (auto num : nums) {
        if (num < nums[9]) {
            return num;
        }
    }
    return 0;
}
int array19(vector<int> nums) {
    int res = 0;
    for (auto num : nums) {
        if (nums[0] < num && num < nums[9]) {
            res = num;
        }
    }
    return res;
}
int array20(vector<int> nums, int l, int r) {
    int res = 0;
    for (int i = l - 1; i < r; i++) {
        res += nums[i];
    }
    return res;
}

int main()
{
    return 0;
}