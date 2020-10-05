#include <iostream>
using namespace std;

void Integer_6(int a)
{
    int c = a / 10;
    int b = a % 10;
    cout << c << endl << b;
}

void Integer_7(int a)
{
    int c = a / 10;
    int b = a % 10;
    cout << c + b << endl << c * b;
}

void Integer_8(int a)
{
    int c = a / 10;
    int b = a % 10;
    cout << b * 10 << endl << c;
}

void Integer_9(int a)
{
    int c = a / 100;
    cout << c;
}

void Integer_10(int a)
{
    int c = a % 10;
    int b = (a / 10) % 10;
    cout << c << endl << b;
}

void Integer_11(int a)
{
    int c = a % 10;
    int b = (a / 10) % 10;
    int d = a / 100;
    cout << c + b + d << endl << c * b * d;
}

void Integer_12(int a)
{
    int c = a % 10;
    int b = (a / 10) % 10;
    int d = a / 100;
    cout << c << b << d;
}

void Integer_13(int a)
{
    int c = a % 10;
    int b = (a / 10) % 10;
    int d = a / 100;
    cout << b << c << d;
}


void Integer_21(int a)
{
    cout << a / 60;
}

void Integer_22(int a)
{
    cout << a / 3600;
}

void Integer_23(int a)
{
    cout << (a / 3600) / 60;
}

bool Boolean_1(int a)
{
    return (a > 0);
}

bool Boolean_2(int a)
{
    return (a % 2 == 1);
}

bool Boolean_3(int a)
{
    return (a % 2 == 0);
}

bool Boolean_11(int a, int b)
{
    return (a % 2 == b % 2);
}

bool Boolean_12(int a, int b, int c)
{
    return (a > 0 && b > 0 && c > 0);
}

bool Boolean_13(int a, int b, int c)
{
    return (a > 0 || b > 0 || c > 0);
}

bool Boolean_21(int a)
{
    int c = a % 10;
    int b = (a / 10) % 10;
    int d = a / 100;
    return (b > d && c > b);
}

bool Boolean_22(int a)
{
    int c = a % 10;
    int b = (a / 10) % 10;
    int d = a / 100;
    return (b > d && c > b) || (d > b && b > c);
}

bool Boolean_23(int a)
{
    int c = a % 10;
    int b = (a / 10) % 10;
    int d = (a / 100) % 10;
    int e = a / 1000;
    return (e == c && b == d);
}

bool Boolean_31(int a, int b, int c)
{
    return (a == b || a == c || b == c);
}

bool Boolean_32(int a, int b, int c)
{
    return ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a));
}

bool Boolean_33(int a, int b, int c)
{
    return ((a + b > c) && (a + c > b) && (b + c > a));
}



int main()
{
    
}



