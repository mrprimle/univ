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
        cout << "Плохо";
        break;
    case 2:
        cout << "Неудовлитворительно";
        break;
    case 3:
        cout << "Удовлитворительно";
        break;
    case 4:
        cout << "Хорошо";
        break;
    case 5:
        cout << "Отлично";
        break;
    default:
        cout << "Ошибка";
        break;
    }
}
void switch_3(int a) {
    switch (a) {
    case 12:
    case 1:
    case 2:
        cout << "Зима";
        break;
    case 3:
    case 4:
    case 5:
        cout << "Весна";
        break;
    case 6:
    case 7:
    case 8:
        cout << "Лето";
        break;
    case 9:
    case 10:
    case 11:
        cout << "Осень";
        break;
    default:
        cout << "Ошибка";
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
        cout << "Ошибка";
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
        cout << "Ошибка";
        break;
    }
    cout << a << " " << a * sqrt(3) / 6 << " " << a * sqrt(3) / 3 << " " << a * a * sqrt(3) / 4;
}
void switch_19(int year) {
    int col = (year - 1984) % 60 / 12;
    int anim = (year - 1984) % 60 % 12;
    switch (col) {
    case 0:
        cout << "зеленый";
        break;
    case 1:
        cout << "красный";
        break;
    case 2:
        cout << "желтый";
        break;
    case 3:
        cout << "белый";
        break;
    case 4:
        cout << "черный";
        break;
    default:
        cout << "Ошибка";
        break;
    }
    switch (anim) {
    case 11:
        cout << "свинья";
        break;
    case 0:
        cout << "крыса";
        break;
    case 1:
        cout << "корова";
        break;
    case 2:
        cout << "тигр";
        break;
    case 3:
        cout << "заяц";
        break;
    case 4:
        cout << "дракон";
        break;
    case 5:
        cout << "змея";
        break;
    case 6:
        cout << "лошадь";
        break;
    case 7:
        cout << "овца";
        break;
    case 8:
        cout << "обезьяна";
        break;
    case 9:
        cout << "курица";
        break;
    case 10:
        cout << "собака";
        break;
    default:
        cout << "Ошибка";
        break;
    }
}






int main()
{
    return 0;
}