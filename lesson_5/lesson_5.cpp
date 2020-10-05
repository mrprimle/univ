#include <iostream>
#include <vector>
using namespace std;


void first(int a, int b, int c, int d)
{
    if (a < b and a < c and a < d) {
        cout << a;
    }
    else if (b < a and b < c and b < d) {
        cout << b;
    }
    else if (c < a and c < b and c < d) {
        cout << c;
    }
    else {
        cout << d;
    }
}

void second(int a, int b, int c, int d)
{
    int counter = 0;
    int tempMax = -999999;

    vector<int> nums = {a, b, c, d};
    for (int num : nums) {
        if (num > tempMax) {
            counter = 1;
            tempMax = num;
        }
        else if (num == tempMax){
            counter++;
        }
    }
    cout << counter;
}

void third(int a, int b, int c, int d, int e)
{
    int tempMax = -999999;
    int tempMin = 9999999;

    vector<int> nums = { a, b, c, d, e };
    for (int num : nums) {
        if (num > tempMax) {
            tempMax = num;
        }
        else if (num < tempMin) {
            tempMin = num;
        }
    }
    cout << tempMin << endl << tempMax;
}

void fourth(int a)
{
    if ((a < 3) or (a == 12)) {
        cout << "зима";
    }
    else if (a < 6) {
        cout << "весна";
    }
    else if (a < 9) {
        cout << "лето";
    }
    else {
        cout << "осень";
    }
}


int main()
{
    return 0;
}