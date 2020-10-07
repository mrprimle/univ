//#include "libSwitch.h"
#include <iostream>
using namespace std;

void switch_1(int a) {
    switch (a) {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    }
}
void switch_2(int a) {
    switch (a) {
    case 1:
        cout << "�����";
        break;
    case 2:
        cout << "�������������������";
        break;
    case 3:
        cout << "�����������������";
        break;
    case 4:
        cout << "������";
        break;
    case 5:
        cout << "�������";
        break;
    default:
        cout << "������";
        break;
    }
}
void switch_3(int a) {
    switch (a) {
    case 12:
    case 1:
    case 2:
        cout << "����";
        break;
    case 3:
    case 4:
    case 5:
        cout << "�����";
        break;
    case 6:
    case 7:
    case 8:
        cout << "����";
        break;
    case 9:
    case 10:
    case 11:
        cout << "�����";
        break;
    default:
        cout << "������";
        break;
    }
}


void switch_12(int a, double val) {
    double pi = 3.14;
    double r;
    switch (a) {
    case 1:
        r = val;
        break;
    case 2:
        r = val / 2;
        break;
    case 3:
        r = val / 2 / pi;
        break;
    case 4:
        r = sqrt(val / pi);
        break;
    default:
        cout << "������";
        break;
    }
    cout << r << " " << r * 2 << " " << r * 2 * pi << " " << r * r * pi;
}
void switch_13(int num, double val) {
    double pi = 3.14;
    double a;
    switch (num) {
    case 1:
        a = val;
        break;
    case 2:
        a = 6 * val / sqrt(3);
        break;
    case 3:
        a = 3 * val / sqrt(3);
        break;
    case 4:
        a = sqrt(4 * val / sqrt(3));
        break;
    default:
        cout << "������";
        break;
    }
    cout << a << " " << a * sqrt(3) / 6 << " " << a * sqrt(3) / 3 << " " << a * a * sqrt(3) / 4;
}
void switch_19(int year) {
    int col = (year - 1984) % 60 / 12;
    int anim = (year - 1984) % 60 % 12;
    switch (col) {
    case 0:
        cout << "�������";
        break;
    case 1:
        cout << "�������";
        break;
    case 2:
        cout << "������";
        break;
    case 3:
        cout << "�����";
        break;
    case 4:
        cout << "������";
        break;
    default:
        cout << "������";
        break;
    }
    switch (anim) {
    case 11:
        cout << "������";
        break;
    case 0:
        cout << "�����";
        break;
    case 1:
        cout << "������";
        break;
    case 2:
        cout << "����";
        break;
    case 3:
        cout << "����";
        break;
    case 4:
        cout << "������";
        break;
    case 5:
        cout << "����";
        break;
    case 6:
        cout << "������";
        break;
    case 7:
        cout << "����";
        break;
    case 8:
        cout << "��������";
        break;
    case 9:
        cout << "������";
        break;
    case 10:
        cout << "������";
        break;
    default:
        cout << "������";
        break;
    }
}






int main()
{
    return 0;
}