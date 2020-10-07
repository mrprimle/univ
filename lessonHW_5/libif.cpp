#include <iostream>
#include "libif.h"
using namespace std;




void if_1(int a) {
    if (is_positive(a)) {
        a++;
    }
    cout << a;
}
void if_2(int a) {
    if (is_positive(a)) {
        a++;
    }
    else {
        a -= 2;
    }
    cout << a;
}
void if_3(int a) {
    if (is_positive(a)) {
        a++;
    }
    else if (a < 0){
        a -= 2;
    }
    else {
        a = 10;
    }
    cout << a;
}

void if_11(int a, int b) {
    if (a == b) {
        a = b = 0;
    }
    else {
        a = b = max(a, b);
    }
    cout << a << endl << b;
}
void if_12(int a, int b, int c) {
    int minNum = min(a, min(b, c));
    cout << minNum;
}
void if_13(int a, int b, int c) {
    int mid;
    if (b <= a <= c) {
        mid = a;
    }
    else if (a <= b <= c) {
        mid = b;
    }
    else {
        mid = c;
    }
    cout << mid;
}

void if_28(int year) {
    if (high_year(year)) {
        cout << 366;
    }
    else {
        cout << 365;
    }
}
void if_21(int x, int y) {
    if (x == 0) {
        if (y == 0) {
            cout << 0;
        }
        else {
            cout << 2;
        }
    }
    else if (y == 0){
        cout << 1;
    }
    else {
        cout << 3;
    }
}
void if_22(int x, int y) {
    if (x > 0) {
        if (y > 0) {
            cout << 1;
        }
        else {
            cout << 4;
        }
    }
    else if (y > 0) {
        cout << 2;
    }
    else {
        cout << 3;
    }
}



