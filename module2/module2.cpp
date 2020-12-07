#include <iostream>
#include <vector>
using namespace std;

void arrFunc(vector<int> arr) {
    // FIRST PART (SUM ODS)
    int first = 0;
    for (int i = 0; i < arr.size(); i += 2) {
        first += arr[i];
    }
    cout << first << endl;


    // SECOND PART (SUM FROM FIRST MIN TO LAST)
    int l = 99999;
    int r = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            if (i <= l) {
                l = i;
            }
            else {
                r = i;
            }
        }
    }
    if (l == 99999 || r == -1) {
        cout << 0 << endl;
    }
    else {
        int second = 0;
        for (int i = l; i < r; i++) {
            second += arr[i];
        }
        cout << second - arr[l] << endl;
    }




    // THIRD PART (MODIFY ARR)
    int origSize = arr.size();
    for (int i = 0; i < arr.size(); i++) {
        if (abs(arr[i]) <= 1) {
            arr.erase(arr.begin() + i);
        }
    }
    
    for (int i = 0; i < origSize - arr.size(); i++) {
        arr.push_back(0);
    }
    




}



int main()
{
    arrFunc({1, -4, 3, 4, 9, -4, 8, -2, 4, 1});

    return 0;
}


