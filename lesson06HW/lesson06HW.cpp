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


// MINMAX
void minmax1(vector<int> arr) {
    cout << min(arr) << " " << max(arr);
}
void minmax12(vector<int> arr) {
    int min = 999999, res = 0;
    for (auto i : arr) {
        if (i > 0 && i < min) {
            min = i;
            res = i;
        }
    }
    cout << res;
}
void minmax21(vector<int> arr) {
    int sum = 0, amount = 0;
    for (int i = 1; i < arr.size() - 1; i++) {
        sum += arr[i];
        amount += 1;
    }
    cout << float(sum) / amount;
}
// ARRAY
vector<int> array1(int n) {
    vector<int> nums = {};
    for (int i = 1; i < n * 2; i += 2) {
        nums.push_back(i);
    }
    return nums;
}
void array11(int k, int n, vector<int> arr) {
    for (int i = 1; i * k < n; i++) {
        cout << arr[i * k] << endl;
    }
}
// FOR
void for1(int n, int k) {
    for (int i = 0; i < n; i++) {
        cout << k << ' ';
    }
}
int for11(int n) {
    int res = 0;
    for (int i = 0; i <= n; i++) {
        res += (n + i) * (n + i);
    }
    return res;
}
float for21(int n) {
    float res = 1;
    float sum = 0;
    for (int i = 1; i <= n; i++) {
        res *= i;
        sum += (1 / res);
    }
    return sum;
}
void for31(int n) {
    float prev = 2;
    for (int i = 0; i < n; i++) {
        cout << 2 + 1 / prev << endl;
        prev = 2 + 1 / prev;
    }
}
// WHILE
int while1(int a, int b) {
    int bArea = 0;
    while (bArea <= a) {
        bArea += b;
    }
    return a - (bArea - b);
}
void while11(int n) {
    int k = 1;
    int sum = 0;
    while (sum < n) {
        sum += k;
        k += 1;
    }
    cout << sum << endl << k - 1;
}
bool while21(int n) {
    while (n != 0) {
        if ((n % 10) % 2 == 1) {
            return true;
        }
        else {
            n /= 10;
        }
    }
    return false;
}

int main()
{
    return 0;
}